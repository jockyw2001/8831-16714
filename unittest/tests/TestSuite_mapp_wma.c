#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/multimedia/mapp_wma.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/multimedia/mapp_wma.c");

CPPTEST_TEST_SUITE(TestSuite_mapp_wma);
CPPTEST_TEST(TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_RegisterBuffer);
CPPTEST_TEST(TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_SetFileLen);
CPPTEST_TEST(TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_Read_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketSCR_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketHeader_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadPTime_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadHeader);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_AddASFPacketForDSP_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_TimeOutCheck);
// CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_UpdatePlayTime_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTimeMs);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Initial_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_CloseFile);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Stop);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_OpenFile);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Input);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_LoadDspCodec);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Play);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetPayloadIndexFromIndexTable_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ProcessFfRew_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetInfoString);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Main_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test__MApp_WMA_TimeOffset);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_ProcessTimeOffset_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_FastForwardBackward);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_Probe_case1);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_Wma_GetErrCode);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_Wma_StopAfterFBBegin_enable);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetFfRewSpeed);
CPPTEST_TEST(TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime_return0);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_RegisterBuffer();
void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_SetFileLen();
void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_Read_case1();
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketSCR_case1();
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketHeader_case1();
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadPTime_case1();
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadHeader();
void TestSuite_mapp_wma_test_MApp_WMA_AddASFPacketForDSP_case1();
void TestSuite_mapp_wma_test_MApp_WMA_TimeOutCheck();
// void TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1();
void TestSuite_mapp_wma_test_MApp_WMA_UpdatePlayTime_case1();
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime();
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTimeMs();
void TestSuite_mapp_wma_test_MApp_WMA_Initial_case1();
void TestSuite_mapp_wma_test_MApp_WMA_CloseFile();
void TestSuite_mapp_wma_test_MApp_WMA_Stop();
void TestSuite_mapp_wma_test_MApp_WMA_OpenFile();
void TestSuite_mapp_wma_test_MApp_WMA_Input();
void TestSuite_mapp_wma_test_MApp_WMA_LoadDspCodec();
void TestSuite_mapp_wma_test_MApp_WMA_Play();
void TestSuite_mapp_wma_test_MApp_WMA_GetPayloadIndexFromIndexTable_case1();
void TestSuite_mapp_wma_test_MApp_WMA_ProcessFfRew_case1();
void TestSuite_mapp_wma_test_MApp_WMA_GetInfoString();
void TestSuite_mapp_wma_test_MApp_WMA_Main_case1();
void TestSuite_mapp_wma_test__MApp_WMA_TimeOffset();
void TestSuite_mapp_wma_test_MApp_WMA_ProcessTimeOffset_case1();
void TestSuite_mapp_wma_test_MApp_WMA_FastForwardBackward();
void TestSuite_mapp_wma_test_MApp_WMA_Probe_case1();
void TestSuite_mapp_wma_test_MApp_Wma_GetErrCode();
void TestSuite_mapp_wma_test_MApp_Wma_StopAfterFBBegin_enable();
void TestSuite_mapp_wma_test_MApp_WMA_GetFfRewSpeed();
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime_return0();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_mapp_wma);

void TestSuite_mapp_wma_setUp()
{
}

void TestSuite_mapp_wma_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_MID_FS_RegisterBuffer */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DataStreamIO_MID_FS_RegisterBuffer(U8 *) */
void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_RegisterBuffer()
{
    U8 u8MidFsBufTemp;

    U8 * _pu8MidFSBuf  = &u8MidFsBufTemp ;
    /* Initializing global variable stMidFSInfo */ 
    {
         stMidFSInfo.pu8MidFSCurrentBuffer  = 0 ;
         stMidFSInfo.u32StartAddr  = 0ul;
         stMidFSInfo.u32EndAddr  = 0ul;
         stMidFSInfo.u32UserSeekAddr  = 0ul;
         stMidFSInfo.u32FileLen  = 0ul;

        /* Tested function call */
        msAPI_DataStreamIO_MID_FS_RegisterBuffer(_pu8MidFSBuf);
        /* Post-condition check */
        CPPTEST_ASSERT_PTR_EQUAL(_pu8MidFSBuf,stMidFSInfo.pu8MidFSCurrentBuffer);
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMidFSInfo.u32StartAddr);
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMidFSInfo.u32EndAddr);
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stMidFSInfo.u32UserSeekAddr);

    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_MID_FS_RegisterBuffer */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_MID_FS_SetFileLen */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_DataStreamIO_MID_FS_SetFileLen(U32) */
void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_SetFileLen()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32FileLen) */ 
    U32 _u32FileLen  = 20ul;
    /* Initializing global variable stMidFSInfo */ 
    {
         stMidFSInfo.pu8MidFSCurrentBuffer  = 0 ;
         stMidFSInfo.u32StartAddr  = 0ul;
         stMidFSInfo.u32EndAddr  = 0ul;
         stMidFSInfo.u32UserSeekAddr  = 0ul;
         stMidFSInfo.u32FileLen  = 0ul;
    }
    {
        /* Tested function call */
        msAPI_DataStreamIO_MID_FS_SetFileLen(_u32FileLen);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(20, ( stMidFSInfo.u32FileLen ));
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_MID_FS_SetFileLen */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_DataStreamIO_MID_FS_Read_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 msAPI_DataStreamIO_MID_FS_Read(U32, U32, U32 *) */
void TestSuite_mapp_wma_test_msAPI_DataStreamIO_MID_FS_Read_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32Hdl) */ 
    U32 _u32Hdl  = 0ul;
    /* Initializing argument 2 (u32Length) */ 
    U32 _u32Length  = 20ul;
    /* Initializing argument 3 (pu32DestAddr) */ 

    U32 u32DestAddrTemp;
    U32 * _pu32DestAddr  = &u32DestAddrTemp ;

    U8 u8MidFsBufTemp;
    stMidFSInfo.pu8MidFSCurrentBuffer = &u8MidFsBufTemp;

    //case 1
    {
    	stMidFSInfo.u32FileLen = 20000;
		stMidFSInfo.u32StartAddr = 150;
		stMidFSInfo.u32EndAddr = 300;
    	stMidFSInfo.u32UserSeekAddr = 160;
    	U32 _return  = msAPI_DataStreamIO_MID_FS_Read(_u32Hdl, _u32Length, _pu32DestAddr);
    	CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
    	CPPTEST_ASSERT_INTEGER_EQUAL(180, stMidFSInfo.u32UserSeekAddr);
    }

    //case 2
    {
    	stMidFSInfo.u32FileLen = 20000;
		stMidFSInfo.u32StartAddr = 150;
		stMidFSInfo.u32EndAddr = 300;
    	stMidFSInfo.u32UserSeekAddr = 290;
    	U32 _return  = msAPI_DataStreamIO_MID_FS_Read(_u32Hdl, _u32Length, _pu32DestAddr);
    	CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
    }

    //case 3
    {
    	stMidFSInfo.u32FileLen = 20000;
		stMidFSInfo.u32StartAddr = 150;
		stMidFSInfo.u32EndAddr = 300;
    	stMidFSInfo.u32UserSeekAddr = 310;
    	U32 _return  = msAPI_DataStreamIO_MID_FS_Read(_u32Hdl, _u32Length, _pu32DestAddr);
    	CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_DataStreamIO_MID_FS_Read_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ParsingASFPacketSCR_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_ParsingASFPacketSCR(U32, ST_WMA_INFO *) */
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketSCR_case1()
{


	U8 u8Temp[50] = {0x82,0x00,0x00,0x08,0x5D,0x04,0x00,0x00,0x00,0x00,
	                 0x73,0x01,0x01,0x01,0x00,0x00,0x00,0x08,0x39,0x17,
	                 0x00,0x00,0x2A,0x06,0x00,0x00,0x09,0x00,0x00,0x03,
	                 0xBF,0xFF,0x00,0x23,0xB8,0x44,0x42,0x55,0x77,0xFE,
	                 0x00,0x47,0x70,0x88,0x84,0xAA,0xED,0xEB,0x10,0x41};


	ST_WMA_INFO wmaInfoTemp;
	memset(&wmaInfoTemp,0,sizeof(ST_WMA_INFO));
    ST_WMA_INFO * _pWmaInfo  = &wmaInfoTemp ;

	U32 _return  = MApp_WMA_ParsingASFPacketSCR( (U32)&u8Temp, _pWmaInfo);

	CPPTEST_ASSERT_INTEGER_EQUAL(12, _return);
	CPPTEST_ASSERT_INTEGER_EQUAL(2, _pWmaInfo->u32ErrorCLength);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->bIsMultiPayloads);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u8SequenceLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8PaddingLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u8PacketLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8ReplicatedDLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(3, _pWmaInfo->u8OffseIMOLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8MediaONLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8NumPayloads);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8FirstNumPayloads);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u32TotalPayloads);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ParsingASFPacketSCR_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ParsingASFPacketHeader_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_ParsingASFPacketHeader(U32, ST_WMA_INFO *) */
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPacketHeader_case1()
{
    U8 u8Temp[50] = {0x82,0x00,0x00,0x08,0x5D,0x04,0x00,0x00,0x00,0x00,
					 0x73,0x01,0x01,0x01,0x00,0x00,0x00,0x08,0x39,0x17,
					 0x00,0x00,0x2A,0x06,0x00,0x00,0x09,0x00,0x00,0x03,
					 0xBF,0xFF,0x00,0x23,0xB8,0x44,0x42,0x55,0x77,0xFE,
					 0x00,0x47,0x70,0x88,0x84,0xAA,0xED,0xEB,0x10,0x41};


	ST_WMA_INFO wmaInfoTemp;
	memset(&wmaInfoTemp,0,sizeof(ST_WMA_INFO));
	ST_WMA_INFO * _pWmaInfo  = &wmaInfoTemp ;

    U32 _return  = MApp_WMA_ParsingASFPacketHeader((U32)&u8Temp, _pWmaInfo);

    CPPTEST_ASSERT_INTEGER_EQUAL(12, _return);
    CPPTEST_ASSERT_INTEGER_EQUAL(2, _pWmaInfo->u32ErrorCLength);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->bIsMultiPayloads);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u8SequenceLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8PaddingLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u8PacketLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8ReplicatedDLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(3, _pWmaInfo->u8OffseIMOLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8MediaONLType);
	CPPTEST_ASSERT_INTEGER_EQUAL(1, _pWmaInfo->u8NumPayloads);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ParsingASFPacketHeader_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ParsingASFPayloadPTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_ParsingASFPayloadPTime(U32, ST_WMA_INFO *, U32, U32) */
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadPTime_case1()
{

	U8 u8Temp[30] = {0x09,0x00,0x00,0x03,0xBF,0xFF,0x00,0x23,0xB8,0x44,
			         0x42,0x55,0x77,0xFE,0x00,0x47,0x70,0x88,0x84,0xAA,
	                 0xED,0xEB,0x10,0x41,0x07,0x4F,0xFA,0xE8,0x08,0xEE};

	ST_WMA_INFO wmaInfoTemp;
	memset(&wmaInfoTemp,0,sizeof(ST_WMA_INFO));
	ST_WMA_INFO * _pWmaInfo  = &wmaInfoTemp ;
    U32 _u32IndexNum  = 0ul;
    U32 _u32PayloadPosInFile  = 0xC06;

    _pWmaInfo->u8MediaONLType = 1;
    _pWmaInfo->u8OffseIMOLType = 3;
    _pWmaInfo->u8ReplicatedDLType = 1;
    _pWmaInfo->u32PacketSize = 5976;

    ST_WMA_INDEX_TABLE stWMAIndexTableTemp;
    memset(&stWMAIndexTableTemp,0,sizeof(ST_WMA_INDEX_TABLE));
	u32WMAPayloadTableAddr  = &stWMAIndexTableTemp;

	U32 _return  = MApp_WMA_ParsingASFPayloadPTime((U32)&u8Temp, _pWmaInfo, _u32IndexNum, _u32PayloadPosInFile);
	CPPTEST_ASSERT_INTEGER_EQUAL(7, _return);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u32PayloadLength);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ParsingASFPayloadPTime_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ParsingASFPayloadHeader */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_ParsingASFPayloadHeader(U32, ST_WMA_INFO *) */
void TestSuite_mapp_wma_test_MApp_WMA_ParsingASFPayloadHeader()
{
	U8 u8Temp[30] = {0x09,0x00,0x00,0x03,0xBF,0xFF,0x00,0x23,0xB8,0x44,
				         0x42,0x55,0x77,0xFE,0x00,0x47,0x70,0x88,0x84,0xAA,
		                 0xED,0xEB,0x10,0x41,0x07,0x4F,0xFA,0xE8,0x08,0xEE};

	ST_WMA_INFO wmaInfoTemp;
	memset(&wmaInfoTemp,0,sizeof(ST_WMA_INFO));
	ST_WMA_INFO * _pWmaInfo  = &wmaInfoTemp ;

	 _pWmaInfo->u8MediaONLType = 1;
	_pWmaInfo->u8OffseIMOLType = 3;
	_pWmaInfo->u8ReplicatedDLType = 1;
	_pWmaInfo->u32PacketSize = 5976;

	U32 _return  = MApp_WMA_ParsingASFPayloadHeader((U32)&u8Temp, _pWmaInfo);

	CPPTEST_ASSERT_INTEGER_EQUAL(7, _return);
	CPPTEST_ASSERT_INTEGER_EQUAL(0, _pWmaInfo->u32PayloadLength);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ParsingASFPayloadHeader */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_AddASFPacketForDSP_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_AddASFPacketForDSP(U32, U32) */
void TestSuite_mapp_wma_test_MApp_WMA_AddASFPacketForDSP_case1()
{

    U32 _dwReqAddress  = 0ul;
    U32 _u32ReqBytes  = 200ul;

    stWmaInfo.u16FormatTag = 353;
    _pu8ASFPayloadHeader[WMA_ASF_PACKET_HEADER_SIZE] = 5;
    _u32PayloadWriteLeft = 10;

    stWmaInfo.u8NumPayloads = 1;
    stWmaInfo.u32TotalPacket = 571;
    stWmaInfo.u8NumPayloads = 571;

	U32 _return  = MApp_WMA_AddASFPacketForDSP(_dwReqAddress, _u32ReqBytes);

	CPPTEST_ASSERT_INTEGER_EQUAL(0, _return);
	CPPTEST_ASSERT_INTEGER_EQUAL(0x02, _pu8ASFPayloadHeader[0]);
	CPPTEST_ASSERT_INTEGER_EQUAL(0x80, _pu8ASFPayloadHeader[1]);
	CPPTEST_ASSERT_INTEGER_EQUAL(0xFD, _pu8ASFPayloadHeader[2]);
	CPPTEST_ASSERT_INTEGER_EQUAL(0x7F, _pu8ASFPayloadHeader[3]);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_AddASFPacketForDSP_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_TimeOutCheck */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_TimeOutCheck(void) */
void TestSuite_mapp_wma_test_MApp_WMA_TimeOutCheck()
{
	enWmaPlayStatus =  WMA_STATUS_PLAYING;

        /* Tested function call */
        BOOLEAN _return  = MApp_WMA_TimeOutCheck();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_TimeOutCheck */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_CollectInfo_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_CollectInfo(ST_WMA_INFO *) */
/*
void TestSuite_mapp_wma_test_MApp_WMA_CollectInfo_case1()
{
	ST_WMA_INFO stWmaInfoTemp;
	stWmaInfoTemp.bHeaderFound = 1;
    ST_WMA_INFO * _pWmaInfo  = &stWmaInfoTemp ;

    stWmaInfo.u32TotalPacket = 1;

	BOOLEAN _return  = MApp_WMA_CollectInfo(_pWmaInfo);

	CPPTEST_ASSERT_BOOL_EQUAL(FALSE, _return);
}
*/
/* CPPTEST_TEST_CASE_END test_MApp_WMA_CollectInfo_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_UpdatePlayTime_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_UpdatePlayTime(void) */
void TestSuite_mapp_wma_test_MApp_WMA_UpdatePlayTime_case1()
{
	//case fail
	{
		bProcessFfRew  = 1;
		u32WmaFileHandle = INVALID_DATA_STREAM_HDL;
		MApp_WMA_UpdatePlayTime();
		CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
	}

	//case true
	{
		bProcessFfRew  = 1;
		u32WmaFileHandle = 0;
		MApp_WMA_UpdatePlayTime();
		CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
	}

}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_UpdatePlayTime_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetCurrentTime */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_WMA_GetCurrentTime(void) */
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime()
{
	enWmaState = STATE_WMA_INPUT;

 	U16 _return  = MApp_WMA_GetCurrentTime();
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);

}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetCurrentTime */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetCurrentTimeMs */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_GetCurrentTimeMs(void) */
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTimeMs()
{
	enWmaState = STATE_WMA_INPUT;
        /* Tested function call */
	U32 _return  = MApp_WMA_GetCurrentTimeMs();
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetCurrentTimeMs */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Initial_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_Initial(void) */
void TestSuite_mapp_wma_test_MApp_WMA_Initial_case1()
{
	stWmaInfo.u16FormatTag = CODEC_FORMAT_WMA_PRO;
	stWmaInfo.bWMADRCFound = 1;

	/* Tested function call */
	BOOLEAN _return  = MApp_WMA_Initial();
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(TRUE,_return);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Initial_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_CloseFile */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_CloseFile(void) */
void TestSuite_mapp_wma_test_MApp_WMA_CloseFile()
{

	u32WmaFileHandle  = 0ul;

	MApp_WMA_CloseFile();

	CPPTEST_ASSERT_INTEGER_EQUAL(INVALID_DATA_STREAM_HDL, ( u32WmaFileHandle ));
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_CloseFile */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Stop */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_Stop(void) */
void TestSuite_mapp_wma_test_MApp_WMA_Stop()
{
	MApp_WMA_Stop();

	CPPTEST_ASSERT_INTEGER_EQUAL(u8MusicFFFWMode, ( u8MusicFFFWMode ));
	CPPTEST_ASSERT_INTEGER_EQUAL( STATE_WMA_STANDBY, ( enWmaState ) );
	CPPTEST_ASSERT_INTEGER_EQUAL( WMA_STATUS_STOP, ( enWmaPlayStatus ) );
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Stop */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_OpenFile */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_OpenFile(void) */
void TestSuite_mapp_wma_test_MApp_WMA_OpenFile()
{
	u32WmaFileHandle  = 0ul;
	_enWMA_ErrCode  = E_WMA_ERR_NONE;

	BOOLEAN _return  = MApp_WMA_OpenFile();

	CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_OpenFile */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Input */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_Input(void) */
void TestSuite_mapp_wma_test_MApp_WMA_Input()
{
	enWmaPlayStatus = WMA_STATUS_PLAYING;

	MApp_WMA_Input();
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(WMA_STATUS_PLAYING,enWmaPlayStatus);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Input */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_LoadDspCodec */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_LoadDspCodec(En_DVB_decSystemType) */
void TestSuite_mapp_wma_test_MApp_WMA_LoadDspCodec()
{
	En_DVB_decSystemType _enDecSystem = MSAPI_AUD_DVB_MP3;
	bReloadDsp  = 0;

	BOOLEAN _return  = MApp_WMA_LoadDspCodec(_enDecSystem);
	/* Post-condition check */
	CPPTEST_ASSERT_BOOL_EQUAL(TRUE,_return);
	CPPTEST_ASSERT_INTEGER_EQUAL( MSAPI_AUD_DVB_MP3, ( enCurrentDecSystem ) );
	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( bReloadDsp ));
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_LoadDspCodec */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Play */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_Play(void) */
void TestSuite_mapp_wma_test_MApp_WMA_Play()
{

    //test case 1
	{
		enWmaPlayStatus = WMA_STATUS_PLAYING;

		MApp_WMA_Play();

		CPPTEST_ASSERT_INTEGER_EQUAL(0, ( u32WmaFileHandle ));
		CPPTEST_ASSERT_INTEGER_EQUAL( STATE_WMA_WAIT, ( enWmaState ) );
		CPPTEST_ASSERT_INTEGER_EQUAL( WMA_STATUS_STOP, ( enWmaPlayStatus ) );
	}

    //test case 2
	{
		enWmaPlayStatus = WMA_STATUS_STOP;

		MApp_WMA_Play();

		CPPTEST_ASSERT_INTEGER_EQUAL(0, ( u32WmaFileHandle ));
		CPPTEST_ASSERT_INTEGER_EQUAL( STATE_WMA_INIT, ( enWmaState ) );
		CPPTEST_ASSERT_INTEGER_EQUAL( WMA_STATUS_PLAYING, ( enWmaPlayStatus ) );
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Play */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetPayloadIndexFromIndexTable_case1 */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_WMA_GetPayloadIndexFromIndexTable(U32, U32, ST_WMA_INDEX_TABLE *) */
void TestSuite_mapp_wma_test_MApp_WMA_GetPayloadIndexFromIndexTable_case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32CurrentPayload) */ 

	u32WMAPayloadTableAddr  = (U32)0;
    U32 _u32CurrentPayload  = 0ul;
    U32 _u32GotoTimeMs  = 7000ul;
    ST_WMA_INDEX_TABLE stWMAIndexTableTemp2;
    memset(&stWMAIndexTableTemp2,0,sizeof(ST_WMA_INDEX_TABLE));
    ST_WMA_INDEX_TABLE * _pstWMAIndexTableReturn  = &stWMAIndexTableTemp2 ;

    stWmaInfo.u32TotalPayloads = 5;

	U32 _return  = MApp_WMA_GetPayloadIndexFromIndexTable(_u32CurrentPayload, _u32GotoTimeMs, _pstWMAIndexTableReturn);
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(2,_return);
	CPPTEST_ASSERT_INTEGER_EQUAL(6500, _pstWMAIndexTableReturn->u32WMAPayloadPTime);
    CPPTEST_ASSERT_INTEGER_EQUAL(50, _pstWMAIndexTableReturn->u32WMAPayloadFilePos);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetPayloadIndexFromIndexTable_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ProcessFfRew_case1 */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_WMA_ProcessFfRew(void) */
void TestSuite_mapp_wma_test_MApp_WMA_ProcessFfRew_case1()
{
	//test FF case1
	{
	    u8MusicFFFWMode = WMA_FF_Mode;
	    bProcessFfRew = 0;
	    stWmaInfo.u32CurrentPlayTime = 300000;
	    stWmaInfo.u32Duration = 300;
	    stWmaInfo.u8FirstNumPayloads = 1;

        /* Tested function call */
        MApp_WMA_ProcessFfRew();
        /* Post-condition check */
        //CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
    }

	//test FF case2
	{
	    u8MusicFFFWMode = WMA_FF_Mode;
	    bProcessFfRew = 0;
	    stWmaInfo.u32CurrentPlayTime = 300;
	    stWmaInfo.u32Duration = 300;
	    stWmaInfo.u8FirstNumPayloads = 1;

        /* Tested function call */
        MApp_WMA_ProcessFfRew();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
    }

	//test FB case1
	{
		u8MusicFFFWMode = WMA_FW_Mode;
		bProcessFfRew = 0;
		stWmaInfo.u32CurrentPlayTime = 0;
		stWmaInfo.u32Duration = 300;
		stWmaInfo.u8FirstNumPayloads = 1;

		/* Tested function call */
		MApp_WMA_ProcessFfRew();
		/* Post-condition check */
		CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
	}

	//test FB case2
	{
		u8MusicFFFWMode = WMA_FW_Mode;
		bProcessFfRew = 0;
		stWmaInfo.u32CurrentPlayTime = 4000;
		stWmaInfo.u32Duration = 300;
		stWmaInfo.u8FirstNumPayloads = 1;

		/* Tested function call */
		MApp_WMA_ProcessFfRew();
		/* Post-condition check */
		CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
	}

}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ProcessFfRew_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetInfoString */
/* CPPTEST_TEST_CASE_CONTEXT U8 * MApp_WMA_GetInfoString(EN_WMA_INFO) */
void TestSuite_mapp_wma_test_MApp_WMA_GetInfoString()
{

	//test WMA_INFO_BITRATE
	{
        EN_WMA_INFO _enInfo  = WMA_INFO_BITRATE;
        stWmaInfo.u32BitRate = 44800;
        U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
        CPPTEST_ASSERT_INTEGER_EQUAL(52, ( *_return ));
    }

	//test WMA_INFO_SAMPLINGRATE
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_SAMPLINGRATE;
		stWmaInfo.u32SampleRate = 44800;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL(52, ( *_return ));
	}

	//test WMA_INFO_ALBUM
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_ALBUM;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL((U8*)stWmaInfo.u8Album,( _return ));
	}

	//test WMA_INFO_TITLE
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_TITLE;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL((U8*)stWmaInfo.u8Title,( _return ));
	}

	//test WMA_INFO_ARTIST
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_ARTIST;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL((U8*)stWmaInfo.u8Author,( _return ));
	}

	//test WMA_INFO_YEAR
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_YEAR;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL(stWmaInfo.u8Year,( _return ));
	}

	//test WMA_INFO_CHECK_FF_FB
	{
		EN_WMA_INFO _enInfo  = WMA_INFO_CHECK_FF_FB;
		stWmaInfo.bCheckFfFb = 1;
		U8 * _return  = MApp_WMA_GetInfoString(_enInfo);
		CPPTEST_ASSERT_INTEGER_EQUAL((U8*)&stWmaInfo.bCheckFfFb,( _return ));
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetInfoString */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Main_case1 */
/* CPPTEST_TEST_CASE_CONTEXT EN_RET MApp_WMA_Main(void) */
void TestSuite_mapp_wma_test_MApp_WMA_Main_case1()
{

	//test STATE_WMA_STANDBY
	{
		enWmaState = STATE_WMA_STANDBY;

        EN_RET _return  = MApp_WMA_Main();
        CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_TRAN_STANDBY,_return);
    }

	//test STATE_WMA_INIT
	{
		enWmaState = STATE_WMA_INIT;

		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_INIT,_return);
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_OPEN_FILE,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_NORMAL_MODE,u8MusicFFFWMode);
		CPPTEST_ASSERT_INTEGER_EQUAL(EN_WMA_SPEED_X1,enWmaPlaySpeed);
	}

	//test STATE_WMA_OPEN_FILE
	{
		enWmaState = STATE_WMA_OPEN_FILE;

		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_DECODING,_return);
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_EXIT,enWmaState);
	}

	//test STATE_WMA_INPUT
	{
		enWmaState = STATE_WMA_INPUT;

		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_DECODING,_return);
	}

	//test STATE_WMA_WAIT_DECODE_DONE
	{
		enWmaState = STATE_WMA_WAIT_DECODE_DONE;
		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_WAIT,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_DECODING,_return);
	}

	//test STATE_WMA_WAIT
	{
		enWmaState = STATE_WMA_WAIT;
		enWmaPlayStatus = WMA_STATUS_PLAYING;
		u32WmaTimeOutDefault = 0;
		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_WAIT,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_DECODING,_return);
	}

	//test STATE_WMA_SKIP_PLAY_NEXT
	{
		enWmaState = STATE_WMA_SKIP_PLAY_NEXT;
		enWmaPlayStatus = WMA_STATUS_PLAYING;
		u32WmaTimeOutDefault = 0;
		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_INIT,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_WAIT,_return);
	}

	//test STATE_WMA_SKIP_PLAY_PREV
	{
		enWmaState = STATE_WMA_SKIP_PLAY_PREV;
		enWmaPlayStatus = WMA_STATUS_PLAYING;
		u32WmaTimeOutDefault = 0;
		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_INIT,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_STATUS_STOP,enWmaPlayStatus);
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_WAIT_PLAY_PREV,_return);
	}

	//test STATE_WMA_EXIT
	{
		enWmaState = STATE_WMA_EXIT;
		enWmaPlayStatus = WMA_STATUS_PLAYING;
		u32WmaTimeOutDefault = 0;
		EN_RET _return  = MApp_WMA_Main();
		CPPTEST_ASSERT_INTEGER_EQUAL(STATE_WMA_STANDBY,enWmaState);
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_STATUS_STOP,enWmaPlayStatus);
		CPPTEST_ASSERT_INTEGER_EQUAL(EXIT_WMA_EXIT,_return);
	}

}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Main_case1 */

/* CPPTEST_TEST_CASE_BEGIN test__MApp_WMA_TimeOffset */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN _MApp_WMA_TimeOffset(U32) */
void TestSuite_mapp_wma_test__MApp_WMA_TimeOffset()
{

	U32 _u32GotoTimeMs = 300;

	bProcessFfRew = 1;
	stWmaInfo.u32Duration = 300;
	stWmaInfo.u32TotalPayloads = 500;

	BOOLEAN _return  = _MApp_WMA_TimeOffset(_u32GotoTimeMs);

	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test__MApp_WMA_TimeOffset */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_ProcessTimeOffset_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_ProcessTimeOffset(U32) */
void TestSuite_mapp_wma_test_MApp_WMA_ProcessTimeOffset_case1()
{
    U32 _u32GotoTimeMs  = 0ul;
    enWmaState = STATE_WMA_WAIT_DECODE_DONE ;
    stWmaInfo.u32Duration = 300;

	BOOLEAN _return  = MApp_WMA_ProcessTimeOffset(_u32GotoTimeMs);

	CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
	CPPTEST_ASSERT_INTEGER_EQUAL(0,stWmaInfo.u32CurrentPlayTime);
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_ProcessTimeOffset_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_FastForwardBackward */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_FastForwardBackward(BOOLEAN, EN_WMA_SPEED) */
void TestSuite_mapp_wma_test_MApp_WMA_FastForwardBackward()
{
	//test case1
	{
		enWmaState = STATE_WMA_WAIT_DECODE_DONE;
		U8 _bForward  = 1;
		EN_WMA_SPEED _eSpeed  = EN_WMA_SPEED_X1;

		BOOLEAN _return  = MApp_WMA_FastForwardBackward(_bForward, _eSpeed);

		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_NORMAL_MODE,u8MusicFFFWMode);
		CPPTEST_ASSERT_INTEGER_EQUAL(EN_WMA_SPEED_X1,enWmaPlaySpeed);
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_STATUS_PLAYING,enWmaPlayStatus);
	}

	//test case2
	{
		enWmaState = STATE_WMA_WAIT_DECODE_DONE;
		U8 _bForward  = 1;
		EN_WMA_SPEED _eSpeed  = EN_WMA_SPEED_X2;
		u8MusicFFFWMode = WMA_FF_Mode;

		BOOLEAN _return  = MApp_WMA_FastForwardBackward(_bForward, _eSpeed);

		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
		CPPTEST_ASSERT_INTEGER_EQUAL(WMA_FF_Mode,u8MusicFFFWMode);
		CPPTEST_ASSERT_INTEGER_EQUAL(EN_WMA_SPEED_X2,enWmaPlaySpeed);
	}

	//test case3
	{
		enWmaState = STATE_WMA_WAIT_DECODE_DONE;
		U8 _bForward  = 0;
		EN_WMA_SPEED _eSpeed  = EN_WMA_SPEED_X2;
		u8MusicFFFWMode = WMA_FF_Mode;
		enWmaPlayStatus = WMA_STATUS_PLAYING;

		BOOLEAN _return  = MApp_WMA_FastForwardBackward(_bForward, _eSpeed);
		CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
		CPPTEST_ASSERT_INTEGER_EQUAL(EN_WMA_SPEED_X2,enWmaPlaySpeed);
	}
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_FastForwardBackward */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_Probe_case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_WMA_Probe(U32, ST_WMA_PROBE_INFO *, U32) */
void TestSuite_mapp_wma_test_MApp_WMA_Probe_case1()
{

    U32 _u32Hdl  = 0ul;

    ST_WMA_PROBE_INFO stWmaProbeInfoTemp;
    ST_WMA_PROBE_INFO * _pstWmaProbeInfo  = &stWmaProbeInfoTemp ;

    U32 _u32InfoAttr  = E_MUSIC_INFO_DURATION;

	BOOLEAN _return  = MApp_WMA_Probe(_u32Hdl, _pstWmaProbeInfo, _u32InfoAttr);

	CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_Probe_case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Wma_GetErrCode */
/* CPPTEST_TEST_CASE_CONTEXT EN_WMA_ERRCODE MApp_Wma_GetErrCode(void) */
void TestSuite_mapp_wma_test_MApp_Wma_GetErrCode()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enWMA_ErrCode */ 
    {
         _enWMA_ErrCode  = E_WMA_ERR_NONE;
    }
    {
        /* Tested function call */
        EN_WMA_ERRCODE _return  = MApp_Wma_GetErrCode();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL( E_WMA_ERR_NONE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Wma_GetErrCode */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_Wma_StopAfterFBBegin_enable */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_Wma_StopAfterFBBegin(BOOLEAN) */
void TestSuite_mapp_wma_test_MApp_Wma_StopAfterFBBegin_enable()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnabled) */ 
    U8 _bEnabled  = 1;
    /* Initializing global variable bStop_After_FB_To_Begin_Wma */ 
    {
         bStop_After_FB_To_Begin_Wma  = 0;
    }
    {
        /* Tested function call */
        MApp_Wma_StopAfterFBBegin(_bEnabled);
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL(_bEnabled,  bStop_After_FB_To_Begin_Wma);
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_Wma_StopAfterFBBegin_enable */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetFfRewSpeed */
/* CPPTEST_TEST_CASE_CONTEXT EN_WMA_SPEED MApp_WMA_GetFfRewSpeed(void) */
void TestSuite_mapp_wma_test_MApp_WMA_GetFfRewSpeed()
{
    /* Pre-condition initialization */
    /* Initializing global variable u8MusicFFFWMode */ 
    {
         u8MusicFFFWMode  = WMA_NORMAL_MODE;
    }
    /* Initializing global variable enWmaPlaySpeed */ 
    {
         enWmaPlaySpeed  = EN_WMA_SPEED_X2;
    }
    {
        /* Tested function call */
        EN_WMA_SPEED _return  = MApp_WMA_GetFfRewSpeed();
        /* Post-condition check */
        CPPTEST_ASSERT_INTEGER_EQUAL( EN_WMA_SPEED_X1, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetFfRewSpeed */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_WMA_GetCurrentTime_return0 */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_WMA_GetCurrentTime(void) */
void TestSuite_mapp_wma_test_MApp_WMA_GetCurrentTime_return0()
{
	enWmaState = STATE_WMA_INIT;

 	U16 _return  = MApp_WMA_GetCurrentTime();
	/* Post-condition check */
	CPPTEST_ASSERT_INTEGER_EQUAL(0,_return);

}
/* CPPTEST_TEST_CASE_END test_MApp_WMA_GetCurrentTime_return0 */
