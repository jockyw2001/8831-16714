#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "Board.h"

#if ENABLE_ATSC_TTS

#include "Utl.h"
#include "tts.h"
#include "libTTS.h"
#include "langId.h"
#include "drvGlobal.h"
#include "tn_en.h"
#include "tn_es.h"
#include "tn_fr.h"


typedef struct{
    int count;
    int size;
    char* buffer;
}MyBuffer;

static U8* p;
static unsigned int language_id;
static unsigned int voice_id;
static unsigned int tts_pitch;
static HANDLE tts_handle;
static MyBuffer tts_buffer;

static int iCount;

#define SIZE_BUFFER 1024//100 * 1024
#define TTS_BUFFER 4096

void *msAPI_Malloc(unsigned int u32Number_of_bytes);
void msAPI_Free(void *pFree);

static int genTTS(HANDLE hTTS, char* text, unsigned char* waveout, unsigned int waveout_len );

const UserSetting SETTINGS01[] = {
    {LANG_EN_US,
     tn_en},
     {LANG_FR_FR,
     tn_fr},
     {LANG_ES_MX,
     tn_es},
    { 0, 0 } };

#define MEM_SIZE (1024*600)

static void MyBuffer_add(MyBuffer* buffer, char* data, int size){
#if 0
	if(buffer->count+ size> SIZE_BUFFER){
		size= SIZE_BUFFER- buffer->count;
		if(size<= 0)
			return;// buffer full
	}
	memcpy(buffer->buffer+ buffer->count, data, size);
	buffer->count+= size;
#endif
    int i;
    int intRemained = 0;
    char * pTemp = data;

    if( (buffer->count + (2*size)) > buffer->size )
    {
        intRemained = ((buffer->count + (2*size)) - buffer->size)/2;
        size = (buffer->size - buffer->count)/2;
    }

    for(i=0;i<size;i+=2)
    {
        buffer->buffer[buffer->count+2*i] = pTemp[i];
        buffer->buffer[buffer->count+2*i+2] = pTemp[i];
        buffer->buffer[buffer->count+2*i+1] = pTemp[i+1];
        buffer->buffer[buffer->count+2*i+3] = pTemp[i+1];
    }

    pTemp += size;
    buffer->count += 2*size;

    if (intRemained > 0)
    {
        buffer->count = 0;
        for(i=0;i<intRemained;i+=2)
        {
            buffer->buffer[buffer->count+2*i] = pTemp[i];
            buffer->buffer[buffer->count+2*i+2] = pTemp[i];
            buffer->buffer[buffer->count+2*i+1] = pTemp[i+1];
            buffer->buffer[buffer->count+2*i+3] = pTemp[i+1];
        }
        buffer->count += intRemained*2;
    }

}

static void  MyBuffer_clear(MyBuffer* buffer){
    if(buffer->buffer!= 0){
        msAPI_Free(buffer->buffer);
        buffer->buffer = 0;
    }
    buffer->count = 0;
    iCount = 0;
}

static int callback(void* lpVoid, int nFlag, char *lpszWav, int nSize)
{
    MyBuffer* buffer=(MyBuffer*) lpVoid;

    if (nFlag == TTS_CB_WAV && lpszWav != 0 && nSize > 0)
    {
        MyBuffer_add(buffer, lpszWav, nSize);
        iCount = buffer->count;
    }
    return 0;
}


int genTTSNext(unsigned long *count)
{
    int nRet;
    nRet = TTS_Next(tts_handle);

    if (nRet == TTS_RET_OK)
    {
        *count = (unsigned long)iCount;
    }

    return nRet;
}


static int genTTS(HANDLE hTTS, char* text, unsigned char* waveout, unsigned int waveout_len)
{
    int nRet;

    tts_buffer.buffer = (char*)waveout;
    tts_buffer.count = 0;
    tts_buffer.size = waveout_len;

    int i = 0;
    if (language_id == LANG_EN_US)
    {
        while(text[i] != '\0')
        {
            if ( (text[i] < 0x20) && (text[i] > 0) )
            {
                printf("TTS detects a control code 0x%x and convert it to space\n",text[i]);
                text[i] = 0x20;
            }
            i++;
        }
    }

    iCount = 0;

    nRet = TTS_Start(hTTS, text,  callback, &tts_buffer);

    return nRet;
}

void *msAPI_Malloc(unsigned int u32Number_of_bytes)
{
    void *ptr;
    ptr = malloc(u32Number_of_bytes);

    if(0 == ptr)
        printf("error! size %x failed\n",u32Number_of_bytes);
    return ptr;
}

void msAPI_Free(void *pFree)
{
   free(pFree);
}

unsigned int get_voice(void)
{
    return voice_id;
}

unsigned int get_language(void)
{
    if( LANG_EN_US == language_id )
        return TTS_LANGUAGE_ENGLISH;
   else if( LANG_FR_FR == language_id )
        return TTS_LANGUAGE_FRENCH;
    else
        return TTS_LANGUAGE_SPANISH;
}

unsigned int get_pitch(void)
{
    return tts_pitch;
}

void set_language(unsigned int lang)
{
    if (language_id != lang)
    {
        if( TTS_LANGUAGE_ENGLISH == lang )
           language_id = LANG_EN_US;
        else if(TTS_LANGUAGE_FRENCH == lang )
            language_id = LANG_FR_FR;
        else
           language_id = LANG_ES_MX;

        TTS_SetLanguage(tts_handle, language_id, voice_id);
	}
}

void set_pitch(unsigned int pitch)
{
    TTS_SetPitch(tts_handle,pitch);
}

void setVoice(unsigned int voice)
{
    voice_id = voice;
}

void stop(void)
{
}

int tts_init(void)
{
    p = malloc(MEM_SIZE);
    iCount = 0;

    if(p == NULL)
    {
        printf("TTS malloc MEM_SIZE error\n");
        return -1;
    }
    else
    {
        printf("TTS malloc MEM_SIZE success\n");
    }

    language_id = LANG_EN_US;
    tts_pitch = 100;
    voice_id = 0;

    tts_buffer.buffer = NULL;//(char*)malloc(SIZE_BUFFER);
    tts_buffer.count = 0;//TTS_AUDIO_BUFFER_MAX_SIZE;

    memset(p, 0x0, MEM_SIZE);

    tts_handle = TTS_Init((void *)p, MEM_SIZE, TTS_BUFFER, SETTINGS01);

    if(tts_handle == 0){
        printf("create tts fail : handle faile");
        return -1;
    }
    else
        return 0;
}

int tts_deinit(void)
{
   MyBuffer_clear(&tts_buffer);
   TTS_Release(tts_handle);

   return 0;
}

int say(unsigned char* text, unsigned int text_len, unsigned char* waveout, unsigned int waveout_len)
{
    text_len = text_len;
    return genTTS(tts_handle,(char*)text,waveout,waveout_len);
}
#endif

