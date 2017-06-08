
enum lang {EN_US, ES_ES, ES_MX, FR_FR, KR_KR, LANG_MAX};

typedef enum _EN_TTS_LANGUAGE
{
    TTS_LANGUAGE_ENGLISH,          // English
    TTS_LANGUAGE_FRENCH,           // French
    TTS_LANGUAGE_SPANISH,          // Spanish
    //TTS_LANGUAGE_KOREA,          // Korea
    TTS_LANGUAGE_NUM,             // Language maximum
} EN_TTS_LANGUAGE;
/*
// MAILBOX relative
//-------------------------------
// E_MBX_CLASS_TTS_ENGIE_CMD_IO
//-------------------------------
typedef enum
{
	MB_TTS_ENGINE_CMD_NONE      = 0x00,
    MB_TTS_ENGINE_SET_INIT_CMD  =0x01,
    MB_TTS_ENGINE_SET_TEXT_CMD        = 0x02,
	// HK --> R2
	MB_TTS_ENGINE_GET_CAP_CMD      = 0x10,   // supported languages, voice number , buffer size, is_pitch_adjustable, is_voice_adjustable, is_speed_adjustable
	MB_TTS_ENGINE_GET_LANG_CMD     = 0x11,   // 1 parameter : lang
	MB_TTS_ENGINE_GET_PITCH_CMD    = 0x12,   // 1 parameter : pitch
	MB_TTS_ENGINE_GET_VOICE_CMD    = 0x13,   // 1 parameter : voice
	MB_TTS_ENGINE_GET_SPEED_CMD    = 0x14,   // 1 parameter : speed

	MB_TTS_ENGINE_SET_LANG_CMD     = 0x15,
	MB_TTS_ENGINE_SET_PITCH_CMD    = 0x16,
	MB_TTS_ENGINE_SET_VOICE_CMD    = 0x17,
	MB_TTS_ENGINE_SET_SPEED_CMD    = 0x18,

	MB_TTS_ENGINE_SAY_CMD          = 0x19,   // 2 parameters : text buffer and text length
	MB_TTS_ENGINE_RBUF_CMD         = 0x20,   // 2 parameters : buffer address and buffer length

	// R2 --> HK
	MB_TTS_ENGINE_GET_CAP_ACK      = 0x80,
	MB_TTS_ENGINE_GET_LANG_ACK     = 0x81,    // 1 parameter : lang
	MB_TTS_ENGINE_GET_PITCH_ACK    = 0x82,    // 1 parameter : pitch
	MB_TTS_ENGINE_GET_VOICE_ACK    = 0x83,    // 1 parameter : voice
	MB_TTS_ENGINE_GET_SPEED_ACK    = 0x84,    // 1 parameter : speed

	MB_TTS_ENGINE_SET_LANG_ACK     = 0x85,
	MB_TTS_ENGINE_SET_PITCH_ACK    = 0x86,
	MB_TTS_ENGINE_SET_VOICE_ACK    = 0x87,
	MB_TTS_ENGINE_SET_SPEED_ACK    = 0x88,

	MB_TTS_ENGINE_WBUF_CMD         = 0x89,   // 2 parameters : buffer address and buffer length

      MB_TTS_ENGINE_SET_SAY_ACK = 0x90,

	MB_TTS_ENGINE_CMD_NUM,
} MB_TTS_ENGINE_CMD_IO;
*/
int tts_init(void);
int tts_deinit(void);

unsigned int get_voice(void);
unsigned int get_language(void);
unsigned int get_pitch(void);

void set_voice(unsigned int voice);
void set_language(unsigned int language);
void set_pitch(unsigned int pitch);

int say(unsigned char* text, unsigned int text_len, unsigned char* waveout, unsigned int waveout_len);

void tts_Mbx_Handler(void);

int genTTSNext(unsigned long *count);

