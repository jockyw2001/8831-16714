#ifndef	__LIB_TTS_H
#define	__LIB_TTS_H

#ifndef HANDLE
#define HANDLE void*
#endif

typedef int (*TTSCallback)(void *pVoid, int nFlag, char *pchData, int nSize);
typedef enum
{
	TTS_RET_PARAM_ERROR = -10,
	TTS_RET_MEMORY_FAIL,
	TTS_RET_FILE_ERROR,
	TTS_RET_WAV_FMT_ERROR,
	TTS_RET_DONE,
	//TTS_RET_NO_TTS,
	TTS_RET_WAV_OUT_STOP,
	TTS_RET_OK	= 0

} TTS_RETURN;

typedef enum
{
	TTS_CB_WAV,
	TTS_CB_TEXT,
	TTS_CB_MAX

} TTS_CALL_BACK;

typedef struct
{
	const int LangId;
	const int *NlpExpress;
} UserSetting;

HANDLE TTS_Init(void* mem, int memSize,  int bufferSize, const UserSetting settings[]); // bufferSize: 256~ 8192
//HANDLE TTS_Init();
int TTS_SetLanguage(HANDLE hTTS, int nLanguageID, int nSpeakerID);
int TTS_Start(HANDLE hTTS, const char *pszText, TTSCallback pfnCallback, void *pvVoid);
int TTS_Next(HANDLE hTTS);
int TTS_SetVolume(HANDLE hTTS, int nVolume); //value: 0 ~ 500; default 100
int TTS_SetPitch(HANDLE hTTS, int nPitch); //value: 50 ~ 200; default 100
int TTS_SetSpeed(HANDLE hTTS, int nSpeed);//value: 50 ~ 200; default 100
int TTS_Release(HANDLE hTTS);
const char* TTS_GetVersion(void);

#endif
