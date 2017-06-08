#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_photo.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_photo.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_photo);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_MemCfg);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_DecodeResolutionCfg);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_EnableStreamMode);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_DecodeFile_Init_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_DecodeMemory_Init_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_EncodeMemory_Init);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_Main_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_Stop);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_GetInfo_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test_MApp_Photo_GetExifInfo_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test__MApp_Photo_Reset);
CPPTEST_TEST(TestSuite_mapp_photo_test__MApp_Photo_Decode_ShowImageInfo_case1);
CPPTEST_TEST(TestSuite_mapp_photo_test__MApp_Photo_CheckCPAlive);
CPPTEST_TEST(TestSuite_mapp_photo_test__MApp_Photo_FileReadHandler_case1);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_photo_test_MApp_Photo_MemCfg();
void TestSuite_mapp_photo_test_MApp_Photo_DecodeResolutionCfg();
void TestSuite_mapp_photo_test_MApp_Photo_EnableStreamMode();
void TestSuite_mapp_photo_test_MApp_Photo_DecodeFile_Init_case1();
void TestSuite_mapp_photo_test_MApp_Photo_DecodeMemory_Init_case1();
void TestSuite_mapp_photo_test_MApp_Photo_EncodeMemory_Init();
void TestSuite_mapp_photo_test_MApp_Photo_Main_case1();
void TestSuite_mapp_photo_test_MApp_Photo_Stop();
void TestSuite_mapp_photo_test_MApp_Photo_GetInfo_case1();
void TestSuite_mapp_photo_test_MApp_Photo_GetExifInfo_case1();
void TestSuite_mapp_photo_test__MApp_Photo_Reset();
void TestSuite_mapp_photo_test__MApp_Photo_Decode_ShowImageInfo_case1();
void TestSuite_mapp_photo_test__MApp_Photo_CheckCPAlive();
void TestSuite_mapp_photo_test__MApp_Photo_FileReadHandler_case1();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_photo);

void TestSuite_mapp_photo_setUp()
{
}

void TestSuite_mapp_photo_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_MemCfg */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Photo_MemCfg(U32, U32, U32, U32, U32, U32) */
void TestSuite_mapp_photo_test_MApp_Photo_MemCfg()
{
    U32 u32DataBufferAddr = 0;
    U32 u32DataBufferSize = 0;
    U32 u32OutputBufferAddr = 0;
    U32 u32OutputBufferSize = 0;
    U32 u32PoolMemAddr = 0;
    U32 u32PoolMemSize = 0;

	/* Tested function call */
	MApp_Photo_MemCfg(u32DataBufferAddr, u32DataBufferSize, u32OutputBufferAddr, u32OutputBufferSize, u32PoolMemAddr, u32PoolMemSize);
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(u32DataBufferAddr, ( _u32DataBuffAddr ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32DataBufferSize, ( _u32DataBuffSize ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32OutputBufferAddr, ( _u32OutputBuffAddr ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32OutputBufferSize, ( _u32OutputBuffSize ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32PoolMemAddr, ( _u32PoolMemAddr ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32PoolMemSize, ( _u32PoolMemSize ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32PoolMemAddr, ( _u32ProgressiveJpegMemAddr ));
	CPPTEST_ASSERT_INTEGER_EQUAL(u32PoolMemSize, ( _u32ProgressiveJpegMemSize ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_MemCfg */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_DecodeResolutionCfg */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Photo_DecodeResolutionCfg(ST_PHOTO_DECODE_RESOLUTION_DEFINTIONS) */
void TestSuite_mapp_photo_test_MApp_Photo_DecodeResolutionCfg()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (stPhotoResolution) */ 
    ST_PHOTO_DECODE_RESOLUTION_DEFINTIONS _stPhotoResolution ;

    _stPhotoResolution.u32MinDecodeWidth = 5;
    _stPhotoResolution.u32MinDecodeHeight = 10;
    _stPhotoResolution.u32MaxDecodeJpegBaselineWidth = 10;
    _stPhotoResolution.u32MaxDecodeJpegBaselineHeight = 10;
    _stPhotoResolution.u32MaxDecodeJpegProgressiveWidth = 10;
    _stPhotoResolution.u32MaxDecodeJpegProgressiveHeight = 10;
    _stPhotoResolution.u32MaxDecodeBmpWidth = 5;
    _stPhotoResolution.u32MaxDecodeBmpHeight = 5;
    _stPhotoResolution.u32MaxDecodePngWidth = 5;
    _stPhotoResolution.u32MaxDecodePngHeight = 5;
    _stPhotoResolution.u32MaxDecodeTiffWidth = 5;
    _stPhotoResolution.u32MaxDecodeTiffHeight = 5;
    _stPhotoResolution.u32MaxDecodeGifWidth = 5;
    _stPhotoResolution.u32MaxDecodeGifHeight = 5;
    _stPhotoResolution.u32MaxDecodeMpoBaselineWidth = 5;
    _stPhotoResolution.u32MaxDecodeMpoBaselineHeight = 5;
    _stPhotoResolution.u32MaxDecodeMpoProgressiveWidth = 5;
    _stPhotoResolution.u32MaxDecodeMpoProgressiveHeight = 5;

	MApp_Photo_DecodeResolutionCfg(_stPhotoResolution);

	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeJpegBaselineHeight, ( m_u32MaxDecodeJpegBaselineHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeJpegProgressiveWidth, ( m_u32MaxDecodeJpegProgressiveWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeJpegProgressiveHeight, ( m_u32MaxDecodeJpegProgressiveHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeBmpWidth, ( m_u32MaxDecodeBmpWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MinDecodeWidth, ( m_u32MinDecodeWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeMpoProgressiveWidth, ( m_u32MaxDecodeMpoProgressiveWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeMpoProgressiveHeight, ( m_u32MaxDecodeMpoProgressiveHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeTiffHeight, ( m_u32MaxDecodeTiffHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeGifWidth, ( m_u32MaxDecodeGifWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeGifHeight, ( m_u32MaxDecodeGifHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL( _stPhotoResolution.u32MaxDecodeMpoBaselineWidth, ( m_u32MaxDecodeMpoBaselineWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeMpoBaselineHeight, ( m_u32MaxDecodeMpoBaselineHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MinDecodeHeight, ( m_u32MinDecodeHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeJpegBaselineWidth, ( m_u32MaxDecodeJpegBaselineWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeBmpHeight, ( m_u32MaxDecodeBmpHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodePngWidth, ( m_u32MaxDecodePngWidth ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodePngHeight, ( m_u32MaxDecodePngHeight ));
	CPPTEST_ASSERT_INTEGER_EQUAL(_stPhotoResolution.u32MaxDecodeTiffWidth, ( m_u32MaxDecodeTiffWidth ));

}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_DecodeResolutionCfg */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_EnableStreamMode */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Photo_EnableStreamMode(BOOLEAN) */
void TestSuite_mapp_photo_test_MApp_Photo_EnableStreamMode()
{
    //test case false
	{
		U8 bEnabled  = 0;

        MApp_Photo_EnableStreamMode(bEnabled);

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _bEnableStreamMode ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_INIT_TIMEOUT, ( _u32Photo_Init_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_START_TIMEOUT, ( _u32Photo_Start_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STOP_TIMEOUT, ( _u32Photo_Stop_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_WDT_TIMEOUT, ( _u32Photo_WDT_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_PROGRESS_TIMEOUT, ( _u32Photo_Progress_Timeout ));
    }

    //test case true
	{
		U8 bEnabled  = 1;

        MApp_Photo_EnableStreamMode(bEnabled);

        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _bEnableStreamMode ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STREAM_INIT_TIMEOUT, ( _u32Photo_Init_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STREAM_START_TIMEOUT, ( _u32Photo_Start_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STREAM_STOP_TIMEOUT, ( _u32Photo_Stop_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STREAM_WDT_TIMEOUT, ( _u32Photo_WDT_Timeout ));
        CPPTEST_ASSERT_INTEGER_EQUAL(PHOTO_STREAM_PROGRESS_TIMEOUT, ( _u32Photo_Progress_Timeout ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_EnableStreamMode */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_DecodeFile_Init_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Photo_DecodeFile_Init(FileEntry *, BOOLEAN) */
void TestSuite_mapp_photo_test_MApp_Photo_DecodeFile_Init_case1()
{

	FileEntry stFileEntryTemp;
    FileEntry * _pFileEntry  = &stFileEntryTemp;

    U8 _bThumbnail  = 0;
    enPhoto_Status = E_PHOTO_STATUS_STOPPED;
    _u32Photo_Init_Timeout = 5000;
    bDoAlphaBlendForPng = 0;
    enPhoto_AckFlags = E_PHOTO_ACKFLG_NULL;

	/* Tested function call */
	BOOLEAN _return  = MApp_Photo_DecodeFile_Init(_pFileEntry, _bThumbnail);
	/* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_DecodeFile_Init_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_DecodeMemory_Init_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Photo_DecodeMemory_Init(BOOLEAN, MApp_Photo_DataRequestCallBack) */
void TestSuite_mapp_photo_test_MApp_Photo_DecodeMemory_Init_case1()
{
    U8 _bThumbnail  = 0;
    MApp_Photo_DataRequestCallBack _pfCallBack  = 0 ;


    BOOLEAN _return  = MApp_Photo_DecodeMemory_Init(_bThumbnail, _pfCallBack);
    CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_DecodeMemory_Init_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_EncodeMemory_Init */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Photo_EncodeMemory_Init(U32, U32, MApp_Photo_DataRequestCallBack) */
void TestSuite_mapp_photo_test_MApp_Photo_EncodeMemory_Init()
{
    U32 _u32Width  = 0ul;
    U32 _u32Height  = 0ul;
    MApp_Photo_DataRequestCallBack _pfCallBack  = 0 ;

	BOOLEAN _return  = MApp_Photo_EncodeMemory_Init(_u32Width, _u32Height, _pfCallBack);
	CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_EncodeMemory_Init */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_Main_case1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_Photo_Main(void) */
void TestSuite_mapp_photo_test_MApp_Photo_Main_case1()
{
	//test E_PHOTO_STATUS_INITED
	{
	    enPhoto_Status = E_PHOTO_STATUS_INITED;
        EN_RET _return  = MApp_Photo_Main();

        CPPTEST_ASSERT_EQUAL( EXIT_PHOTO_DECODING, ( _return ) );
    }

	//test E_PHOTO_STATUS_WAITING_START_ACK
	{
	    enPhoto_Status = E_PHOTO_STATUS_WAITING_START_ACK;
        EN_RET _return  = MApp_Photo_Main();

        CPPTEST_ASSERT_EQUAL( EXIT_PHOTO_DECODE_DONE, ( _return ) );
    }

	//test E_PHOTO_STATUS_WORKING
	{
	    enPhoto_Status = E_PHOTO_STATUS_WORKING;
        EN_RET _return  = MApp_Photo_Main();
        CPPTEST_ASSERT_EQUAL( EXIT_PHOTO_DECODE_ONE_FRAME_DONE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_Main_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_Stop */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Photo_Stop(void) */
void TestSuite_mapp_photo_test_MApp_Photo_Stop()
{
	enPhoto_Status = E_PHOTO_STATUS_INITED;
    MApp_Photo_Stop();

    CPPTEST_ASSERT_BOOL_EQUAL( TRUE, bDoAlphaBlendForPng);
    CPPTEST_ASSERT_INTEGER_EQUAL(E_PHOTO_STATUS_STOPPED,enPhoto_Status);
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_Stop */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_GetInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_Photo_GetInfo(EN_PHOTO_INFO) */
void TestSuite_mapp_photo_test_MApp_Photo_GetInfo_case1()
{

	//test E_PHOTO_INFO_FILE_FORMAT
	{
		EN_PHOTO_INFO _enInfo  = E_PHOTO_INFO_FILE_FORMAT;

        U32 _return  = MApp_Photo_GetInfo(_enInfo);
        CPPTEST_ASSERT_INTEGER_EQUAL(E_PHOTO_FILE_UNKNOWN, ( _return ));
    }

	//test E_PHOTO_INFO_IMAGE_TYPE
	{
		EN_PHOTO_INFO _enInfo  = E_PHOTO_INFO_IMAGE_TYPE;

        U32 _return  = MApp_Photo_GetInfo(_enInfo);
        CPPTEST_ASSERT_INTEGER_EQUAL(E_PHOTO_IMAGE_UNKNOWN, ( _return ));
    }

	//test E_PHOTO_INFO_FILE_SIZE
	{
		EN_PHOTO_INFO _enInfo  = E_PHOTO_INFO_FILE_SIZE;
		_u32Photo_Decode_FileSize = 10;

        U32 _return  = MApp_Photo_GetInfo(_enInfo);
        CPPTEST_ASSERT_INTEGER_EQUAL(10, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_GetInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Photo_GetExifInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_Photo_GetExifInfo(EN_PHOTO_EXIF_INFO, void *, U16) */
void TestSuite_mapp_photo_test_MApp_Photo_GetExifInfo_case1()
{

	//test E_PHOTO_EXIF_INFO_CAMERA_MAKER
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_CAMERA_MAKER;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_CAMERA_MODEL
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_CAMERA_MODEL;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_FLASH_MODE
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_FLASH_MODE;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_ISO_SPEED
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_ISO_SPEED;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_EXPOSURE_BIAS
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_EXPOSURE_BIAS;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_EXPOSURE_TIME
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_EXPOSURE_TIME;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_F_STOP
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_F_STOP;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_FOCAL_LENGTH
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_FOCAL_LENGTH;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_SHUTTER_SPEED
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_SHUTTER_SPEED;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_APERTURE
	{
		EN_PHOTO_EXIF_INFO _enInfo  = E_PHOTO_EXIF_INFO_APERTURE;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }

	//test E_PHOTO_EXIF_INFO_APERTURE
	{
		EN_PHOTO_EXIF_INFO _enInfo  = 11;
		void * _pBufAddr;
		_pBufAddr = 30;
		U16 _u16BufSize  = 20u;

        BOOLEAN _return  = MApp_Photo_GetExifInfo(_enInfo, _pBufAddr, _u16BufSize);
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }



}
/* CPPTEST_TEST_CASE_END test_MApp_Photo_GetExifInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_Reset */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_Photo_Reset(BOOLEAN) */
void TestSuite_mapp_photo_test__MApp_Photo_Reset()
{
    //test TRUE
	{
		BOOLEAN _bForceResetMem = TRUE;

        /* Tested function call */
        _MApp_Photo_Reset(_bForceResetMem);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _u32ResidualReadSize ));
        CPPTEST_ASSERT_INTEGER_EQUAL(_U32_MAX, ( _u32PreGifDecodedFrameIndex ));
        CPPTEST_ASSERT_INTEGER_EQUAL(E_PHOTO_ACKFLG_NULL,enPhoto_AckFlags);
    }

    //test FALSE
	{
		BOOLEAN _bForceResetMem = FALSE;
		_u32DataBuffAddr = 0;
		_u32OutputBuffAddr = 0;
		_u32PoolMemAddr = 0;
		_u32GifFrameInfoArrayAddr = 0;
		m_u32MinDecodeWidth = 0;
		m_u32MaxDecodeJpegBaselineWidth = 0;
		m_u32MaxDecodeJpegProgressiveWidth = 0;
		m_u32MaxDecodeBmpWidth = 0;
		m_u32MaxDecodePngWidth = 0;
		m_u32MaxDecodeTiffWidth = 0;
		m_u32MaxDecodeGifWidth = 0;
		m_u32MaxDecodeMpoBaselineWidth = 0;
		m_u32MaxDecodeMpoProgressiveWidth = 0;

        /* Tested function call */
        _MApp_Photo_Reset(_bForceResetMem);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0, ( _u32ResidualReadSize ));
        CPPTEST_ASSERT_INTEGER_EQUAL(_U32_MAX, ( _u32PreGifDecodedFrameIndex ));
        CPPTEST_ASSERT_INTEGER_EQUAL(E_PHOTO_ACKFLG_NULL,enPhoto_AckFlags);
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_Reset */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_Decode_ShowImageInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_Photo_Decode_ShowImageInfo(void) */
void TestSuite_mapp_photo_test__MApp_Photo_Decode_ShowImageInfo_case1()
{

	//test E_PHOTO_DECODE
	{
		_enPhotoCmd = E_PHOTO_DECODE;
        _MApp_Photo_Decode_ShowImageInfo();
    }
	//test E_PHOTO_ENCODE
	{
		_enPhotoCmd = E_PHOTO_ENCODE;
        _MApp_Photo_Decode_ShowImageInfo();
    }
}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_Decode_ShowImageInfo_case1 */


/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_CheckCPAlive */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_Photo_CheckCPAlive(void) */
void TestSuite_mapp_photo_test__MApp_Photo_CheckCPAlive()
{
	BOOLEAN _return  = _MApp_Photo_CheckCPAlive();
	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_CheckCPAlive */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_Photo_FileReadHandler_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void _MApp_Photo_FileReadHandler(U32, U32) */
void TestSuite_mapp_photo_test__MApp_Photo_FileReadHandler_case1()
{
    U32 _u32Addr  = 0ul;
    U32 _u32Size  = 3ul;

    _MApp_Photo_FileReadHandler(_u32Addr, _u32Size);
    CPPTEST_ASSERT_INTEGER_EQUAL(0,_u32ResidualReadSize);
}
/* CPPTEST_TEST_CASE_END test__MApp_Photo_FileReadHandler_case1 */

