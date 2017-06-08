#include "base_types.h"	//Hao Add
#include "TTS.h"
#include "LexMgrDll.h"
#include "bsr_string.h"
#include "langId.h"

typedef struct
{
	const INT ID;
	const INT *NLP;
	const INT *Prosody;
	const INT *Voice;
	LangCreator lpfLangCreate;
	const char* Lang;
	const INT f0;
	const INT volume;
} Setting;

#ifdef VSRLANG_ENG_USA
#include "en_Prosody.h"
#include "en_Voice.h"
//#include "en_NLP.h"
#endif //_LANG_EN_

#ifdef VSRLANG_SPA_SPA
#include "es_Prosody.h"
#include "es_Voice.h"
#endif //_LANG_ES_

#ifdef VSRLANG_SPA_SAM
#include "es_MX_Prosody.h"
#include "es_MX_Voice.h"
#endif //_LANG_ES_

//#include "es_TN.h"
#ifdef VSRLANG_FRE_FRE
#include "fr_Prosody.h"
#include "fr_Voice.h"
#endif //_LANG_FR_

#ifdef VSRLANG_KOR_KOR
#include "ko_Prosody.h"
#include "ko_Voice.h"
#endif //_LANG_KO_

const static Setting SETTINGS[]={
#ifdef VSRLANG_ENG_USA
		{
				LANG_EN_US,
				0,
//				en_NLP,
				en_Prosody,
				en_Voice,
				LangCreate_EN,
				"en-US",
				100,
				300
		},
#endif
#ifdef VSRLANG_FRE_FRE
		 {
			LANG_FR_FR,
			0,
			fr_Prosody,
			fr_Voice,
			LangCreate_FR,
			"fr-FR",
			125,
			400
		},
#endif
#ifdef VSRLANG_KOR_KOR
		{
			LANG_KO_KR,
			0,
			ko_Prosody,
			ko_Voice,
			LangCreate_KO,
			"ko-KR",
			95,
			400
		},
#endif
#ifdef VSRLANG_SPA_SPA
		{
			LANG_ES_ES,
			0,
			es_Prosody,
			es_Voice,
			LangCreate_ES,
			"es-ES",
			120,
			500
		},
#endif
#ifdef VSRLANG_SPA_SAM
		{
			LANG_ES_MX,
			0,
			es_MX_Prosody,
			es_MX_Voice,
			LangCreate_ES,
			"es-MX",
			105,
			250
		},
#endif
		{
			0,
			0,
			0,
			0,
			0,
			0,
			0,
			0
		},

};
