#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/api/scaler_front/apiXC_Sys.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/api/scaler_front/apiXC_Sys.c");

CPPTEST_TEST_SUITE(TestSuite_apiXC_Sys);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_DEFAULT);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_VGA);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI2);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI3);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_TV);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_CVBS);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_DTV);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_STORAGE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_DEFAULT);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_R);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_G);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_B);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_DEFAULT);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_R);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_G);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_B);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_MAINWINDOW);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_SUBWINDOW);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_LOW);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_MID);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_AUTO);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_Do_HPD);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_TRUE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_FALSE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_TRUE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_FALSE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_DDCRam_Init);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_TRUE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_FALSE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_Start_no_return);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__NONE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__RESET_HDMI);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_OK);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_HDMI_PowerOff);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_msAPI_VE_GetTtxReadDoneStatus);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_msAPI_Scaler_IPAutoCoastHandler);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetSrcIsHD);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_IsSrcHD);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_HPosition);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_VPosition);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_if);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_else);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_if);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_else);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_ReduceBW_ForOSD);
CPPTEST_TEST(TestSuite_apiXC_Sys_test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction);
CPPTEST_TEST(TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_ForceOff);
CPPTEST_TEST_SUITE_END();


void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_DEFAULT();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_VGA();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI2();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI3();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_TV();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_CVBS();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_DTV();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_STORAGE();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_DEFAULT();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_R();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_G();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_B();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_DEFAULT();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_R();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_G();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_B();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_MAINWINDOW();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_SUBWINDOW();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_LOW();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_MID();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_AUTO();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_Do_HPD();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_TRUE();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_FALSE();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_TRUE();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_FALSE();
void TestSuite_apiXC_Sys_test__MApi_XC_DDCRam_Init();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_TRUE();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_FALSE();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_Start_no_return();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__NONE();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__RESET_HDMI();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY();
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_OK();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_HDMI_PowerOff();
void TestSuite_apiXC_Sys_test_msAPI_VE_GetTtxReadDoneStatus();
void TestSuite_apiXC_Sys_test_msAPI_Scaler_IPAutoCoastHandler();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetSrcIsHD();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_IsSrcHD();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_HPosition();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_VPosition();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_if();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_else();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_if();
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_else();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_ReduceBW_ForOSD();
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction();
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_ForceOff();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_apiXC_Sys);

void TestSuite_apiXC_Sys_setUp()
{
}

void TestSuite_apiXC_Sys_tearDown()
{
}

// By daniel: For variable init
void UT_memset (void * __dest, int __ch, size_t __len)
{
	char* pcData = (char*)__dest;


	if( pcData == NULL )
		return;

	while(__len)
	{
		*pcData = __ch;
		pcData += 1;
		__len -= 1;
	}
}


/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_NUM;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 0, ( _u8port_count ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_VGA */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_VGA()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_VGA;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 2, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_VGA_MUX, ( _port_ids[0] ) );
        CPPTEST_ASSERT_EQUAL( INPUT_VGA_SYNC_MUX, ( (_port_ids[1]) ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_VGA */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_YPBPR;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_YPBPR_MUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_HDMI;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_HDMI1_MUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI2 */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI2()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_HDMI2;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_HDMI2_MUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI2 */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI3 */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI3()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_HDMI3;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_HDMI3_MUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_HDMI3 */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_TV */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_TV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_TV;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_TV_YMUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_TV */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_CVBS */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_CVBS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_CVBS;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_AV_YMUX, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_CVBS */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_DTV */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_DTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_DTV;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_PORT_MVOP, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_STORAGE */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_YPBPR */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_InputSource_InputPort_Mapping(INPUT_SOURCE_TYPE_t, E_MUX_INPUTPORT *, MS_U8 *) */
void TestSuite_apiXC_Sys_test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_STORAGE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (src_ids) */
    INPUT_SOURCE_TYPE_t _src_ids  = INPUT_SOURCE_STORAGE;
    /* Initializing argument 2 (port_ids) */
    E_MUX_INPUTPORT _port_ids[2]  = {0} ;
    /* Initializing argument 3 (u8port_count) */
    MS_U8  _u8port_count  = 0 ;
    {
        /* Tested function call */
        _MApi_XC_Sys_InputSource_InputPort_Mapping(_src_ids, &_port_ids, &_u8port_count);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( 1, ( _u8port_count ) );
        CPPTEST_ASSERT_EQUAL( INPUT_PORT_MVOP, ( _port_ids[0] ) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_InputSource_InputPort_Mapping_case_INPUT_SOURCE_STORAGE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transferRGB_Bri_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transferRGB_Bri(MS_U16, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U16 _u16Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = 3;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transferRGB_Bri(_u16Brightness, _u8Brightnesstype);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transferRGB_Bri_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_R */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transferRGB_Bri(MS_U16, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_R()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U16 _u16Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_R;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transferRGB_Bri(_u16Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u16Brightness, ( su16Red_ADJ_Brightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_R */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_G */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transferRGB_Bri(MS_U16, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_G()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U16 _u16Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_G;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transferRGB_Bri(_u16Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u16Brightness, ( su16Green_ADJ_Brightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_G */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_B */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transferRGB_Bri(MS_U16, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_B()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U16 _u16Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_B;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transferRGB_Bri(_u16Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u16Brightness, ( su16Blue_ADJ_Brightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transferRGB_Bri_case_BRIGHTNESS_B */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transfer_Bri_case_DEFAULT */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transfer_Bri(MS_U18, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_DEFAULT()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U8 _u8Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = 3;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transfer_Bri(_u8Brightness, _u8Brightnesstype);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transfer_Bri_case_DEFAULT */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_R */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transfer_Bri(MS_U18, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_R()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U8 _u8Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_R;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transfer_Bri(_u8Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u8Brightness, ( su8RedBrightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_R */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_G */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transfer_Bri(MS_U18, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_G()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U8 _u8Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_G;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transfer_Bri(_u8Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u8Brightness, ( su8GreenBrightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_G */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_B */
/* CPPTEST_TEST_CASE_CONTEXT MS_U16 MApi_XC_Sys_ACE_transfer_Bri(MS_U18, MS_U8) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_B()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16Brightness) */
    MS_U8 _u8Brightness  = 0;
    /* Initializing argument 2 (u8Brightnesstype) */
    MS_U8 _u8Brightnesstype  = BRIGHTNESS_B;
    /* Initializing global variable su16Red_ADJ_Brightness */
    {
         su16Red_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8RedBrightness */
    {
         su8RedBrightness  = 0;
    }
    /* Initializing global variable su16Green_ADJ_Brightness */
    {
         su16Green_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8GreenBrightness */
    {
         su8GreenBrightness  = 0;
    }
    /* Initializing global variable su16Blue_ADJ_Brightness */
    {
         su16Blue_ADJ_Brightness  = 0u;
    }
    /* Initializing global variable su8BlueBrightness */
    {
         su8BlueBrightness  = 0;
    }
    {
        /* Tested function call */
        MS_U16 _return  = MApi_XC_Sys_ACE_transfer_Bri(_u8Brightness, _u8Brightnesstype);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _u8Brightness, ( su8BlueBrightness ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_ACE_transfer_Bri_case_BRIGHTNESS_B */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_MAINWINDOW */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_MAINWINDOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_OFF;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_MAINWINDOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_SUBWINDOW */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_SUBWINDOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_OFF;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = SUB_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_SUBWINDOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_LOW */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_LOW()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_LOW;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_LOW */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_MID */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_MID()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_MID;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_MID */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_HIGH;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_HIGH */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_AUTO */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_AUTO()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_AUTO;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_case_E_XC_PQ_3D_NR_AUTO */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_Do_HPD */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_Do_HPD(INPUT_SOURCE_TYPE_t) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_Do_HPD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (enInputSourceType) */
    INPUT_SOURCE_TYPE_t _enInputSourceType  = INPUT_SOURCE_VGA;
    {
        /* Tested function call */
        MApi_XC_Sys_Do_HPD(_enInputSourceType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_Do_HPD */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_SetHPD_ALL_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_SetHPD_ALL(MS_BOOL) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    MS_BOOL _bEnable  = 1;
    {
        /* Tested function call */
        MApi_XC_Sys_SetHPD_ALL(_bEnable);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_SetHPD_ALL_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_SetHPD_ALL_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_SetHPD_ALL(MS_BOOL) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_ALL_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    MS_BOOL _bEnable  = 0;
    {
        /* Tested function call */
        MApi_XC_Sys_SetHPD_ALL(_bEnable);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_SetHPD_ALL_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_SetHPD_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_SetHPD(MS_BOOL, E_MUX_INPUTPORT) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_TRUE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    MS_BOOL _bEnable  = 1;
    /* Initializing argument 2 (enInputPortType) */
    E_MUX_INPUTPORT _enInputPortType  = INPUT_PORT_NONE_PORT;
    {
        /* Tested function call */
        MApi_XC_Sys_SetHPD(_bEnable, _enInputPortType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_SetHPD_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_SetHPD_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_SetHPD(MS_BOOL, E_MUX_INPUTPORT) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetHPD_FALSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bEnable) */
    MS_BOOL _bEnable  = 0;
    /* Initializing argument 2 (enInputPortType) */
    E_MUX_INPUTPORT _enInputPortType  = INPUT_PORT_NONE_PORT;
    {
        /* Tested function call */
        MApi_XC_Sys_SetHPD(_bEnable, _enInputPortType);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_SetHPD_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_DDCRam_Init */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_DDCRam_Init(void) */
void TestSuite_apiXC_Sys_test__MApi_XC_DDCRam_Init()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        _MApi_XC_DDCRam_Init();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_DDCRam_Init */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Is_Task_Working_TRUE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApi_XC_HPD_Is_Task_Working(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_TRUE()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__SET_HPD_DISABLE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApi_XC_HPD_Is_Task_Working();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( _return ) );
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Is_Task_Working_TRUE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Is_Task_Working_FALSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApi_XC_HPD_Is_Task_Working(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Is_Task_Working_FALSE()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__NONE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApi_XC_HPD_Is_Task_Working();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( FALSE, ( _return ) );
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Is_Task_Working_FALSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_Start_no_return */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task_Start(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_Start_no_return()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable bIMMESWITCH_InitHPD */
    {
         bIMMESWITCH_InitHPD  = 0;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__NONE;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task_Start(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( TRUE, ( bIMMESWITCH_InitHPD ) );
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__SET_HPD_DISABLE, ( s_Hdmi_Hpd_State ) );
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_Start_no_return */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__NONE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__NONE()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__NONE;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__NONE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__SET_HPD_DISABLE;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__SET_HPD_DISABLE_DELAY, ( s_Hdmi_Hpd_State ) );
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__SET_HPD_DISABLE_DELAY;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__RESET_HDMI, ( s_Hdmi_Hpd_State ) )
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_DISABLE_DELAY */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__RESET_HDMI */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__RESET_HDMI()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__RESET_HDMI;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__HPD_DELAY, ( s_Hdmi_Hpd_State ) )
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__RESET_HDMI */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__HPD_DELAY;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__SET_HPD_ENABLE, ( s_Hdmi_Hpd_State ) )
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_DELAY */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__SET_HPD_ENABLE;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__SET_HPD_ENABLE_DELAY, ( s_Hdmi_Hpd_State ) )
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__SET_HPD_ENABLE_DELAY;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( E_HPD_STATE__HPD_OK, ( s_Hdmi_Hpd_State ) )
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__SET_HPD_ENABLE_DELAY */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_OK */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_HPD_Task(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_OK()
{
#if( ENABLE_HDMI_HPD_TASK )
    /* Pre-condition initialization */
    /* Initializing global variable s_u32Hdmi_Hpd_DelayStartTime */
    {
         s_u32Hdmi_Hpd_DelayStartTime  = 0ul;
    }
    /* Initializing global variable s_Hdmi_Hpd_State */
    {
         s_Hdmi_Hpd_State  = E_HPD_STATE__HPD_OK;
    }
    {
        /* Tested function call */
        MApi_XC_HPD_Task(FALSE);
        /* Post-condition check */
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_HPD_Task_case_E_HPD_STATE__HPD_OK */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_HDMI_PowerOff */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_HDMI_PowerOff(void) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_HDMI_PowerOff()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MApi_XC_Sys_HDMI_PowerOff();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_HDMI_PowerOff */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_VE_GetTtxReadDoneStatus */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL msAPI_VE_GetTtxReadDoneStatus(void) */
void TestSuite_apiXC_Sys_test_msAPI_VE_GetTtxReadDoneStatus()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MS_BOOL _return  = msAPI_VE_GetTtxReadDoneStatus();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_VE_GetTtxReadDoneStatus */

/* CPPTEST_TEST_CASE_BEGIN test_msAPI_Scaler_IPAutoCoastHandler */
/* CPPTEST_TEST_CASE_CONTEXT void msAPI_Scaler_IPAutoCoastHandler(void) */
void TestSuite_apiXC_Sys_test_msAPI_Scaler_IPAutoCoastHandler()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        msAPI_Scaler_IPAutoCoastHandler();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_msAPI_Scaler_IPAutoCoastHandler */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_SetSrcIsHD */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_SetSrcIsHD(MS_BOOL, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_SetSrcIsHD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (bIsHd) */
    MS_BOOL _bIsHd  = 1;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Sys_SetSrcIsHD(_bIsHd, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( _bIsHd, ( bSrcIsHD[_eWindow] ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_SetSrcIsHD */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_IsSrcHD */
/* CPPTEST_TEST_CASE_CONTEXT MS_BOOL MApi_XC_Sys_IsSrcHD(SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_IsSrcHD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    bSrcIsHD[_eWindow] = 1;
    {
        /* Tested function call */
        MS_BOOL _return  = MApi_XC_Sys_IsSrcHD(_eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( bSrcIsHD[_eWindow], ( _return ) )
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_IsSrcHD */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_PC_HPosition */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_PC_HPosition(U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_HPosition()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16HPosition) */
    U16 _u16HPosition  = 0u;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Set_PC_HPosition(_u16HPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_PC_HPosition */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_PC_VPosition */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_PC_VPosition(U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_PC_VPosition()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16VPosition) */
    U16 _u16VPosition  = 0u;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Set_PC_VPosition(_u16VPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_PC_VPosition */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_Ypbpr_HPosition_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_Ypbpr_HPosition(U16, U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PrePosition) */
    U16 _u16PrePosition  = 0u;
    /* Initializing argument 2 (u16NewPosition) */
    U16 _u16NewPosition  = _u16PrePosition+1;
    /* Initializing argument 3 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Set_Ypbpr_HPosition(_u16PrePosition, _u16NewPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_Ypbpr_HPosition_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_Ypbpr_HPosition_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_Ypbpr_HPosition(U16, U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_HPosition_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PrePosition) */
    U16 _u16PrePosition  = 0u;
    /* Initializing argument 2 (u16NewPosition) */
    U16 _u16NewPosition  = 0u;
    /* Initializing argument 3 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
    	MApi_XC_Set_Ypbpr_HPosition(_u16PrePosition, _u16NewPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_Ypbpr_HPosition_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_Ypbpr_VPosition_if */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_Ypbpr_VPosition(U16, U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_if()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PrePosition) */
    U16 _u16PrePosition  = 0u;
    /* Initializing argument 2 (u16NewPosition) */
    U16 _u16NewPosition  = _u16PrePosition+1;
    /* Initializing argument 3 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
        MApi_XC_Set_Ypbpr_VPosition(_u16PrePosition, _u16NewPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_Ypbpr_HPosition_if */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Set_Ypbpr_VPosition_else */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Set_Ypbpr_VPosition(U16, U16, SCALER_WIN) */
void TestSuite_apiXC_Sys_test_MApi_XC_Set_Ypbpr_VPosition_else()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16PrePosition) */
    U16 _u16PrePosition  = 0u;
    /* Initializing argument 2 (u16NewPosition) */
    U16 _u16NewPosition  = 0u;
    /* Initializing argument 3 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;
    {
        /* Tested function call */
    	MApi_XC_Set_Ypbpr_VPosition(_u16PrePosition, _u16NewPosition, _eWindow);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Set_Ypbpr_VPosition_else */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_ReduceBW_ForOSD */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_ReduceBW_ForOSD(MS_U8, MS_BOOL) */
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_ReduceBW_ForOSD()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PqWin) */
    MS_U8 _PqWin  = 0;
    /* Initializing argument 2 (bOSD_On) */
    MS_BOOL _bOSD_On  = 0;
    {
        /* Tested function call */
        MApi_XC_Sys_PQ_ReduceBW_ForOSD(_PqWin, _bOSD_On);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_ReduceBW_ForOSD */


/* CPPTEST_TEST_CASE_BEGIN test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction */
/* CPPTEST_TEST_CASE_CONTEXT void _MApi_XC_Sys_Init_PQ(XC_INITDATA *) */
extern MS_U8 g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result;

void TestSuite_apiXC_Sys_test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pstXC_InitData) */
	//MS_PQ_Init_Info sXC_PQ_InitData;
	XC_INITDATA sXC_InitData;

//	char abc[240];
//    printf("address of sXC_PQ_InitData = %x\n", (unsigned long)(&sXC_PQ_InitData));
//    memset(abc, 0, 132);

	UT_memset(&sXC_InitData, 0, sizeof(XC_INITDATA));
    //UT_memset(&sXC_PQ_InitData, 0, sizeof(MS_PQ_Init_Info));

//    memset(&sXC_PQ_InitData, 0, 132);

    //sXC_PQ_InitData.stPanelInfo.u16Width  = 1920;
    //sXC_PQ_InitData.stPanelInfo.u16VTotal = 1126;
	sXC_InitData.stPanelInfo.u16Width  = 1920;
	sXC_InitData.stPanelInfo.u16VTotal = 1126;


    /* Initializing global variable  */

    g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result = 0;

    {
        /* Tested function call */
        //_MApi_XC_Sys_Init_PQ(_pstXC_InitData);
    	_MApi_XC_Sys_Init_PQ(&sXC_InitData);

        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("XC_INITDATA * _pstXC_InitData ", ( _pstXC_InitData ));
        //CPPTEST_POST_CONDITION_UINTEGER("MS_U16 U16PQSrcType", ( U16PQSrcType ));
    	CPPTEST_ASSERT_UINTEGER_EQUAL( 1, (g_CppTest_Stub_MApi_XC_PQ_LoadFunction_u8Result) );
    }
}
/* CPPTEST_TEST_CASE_END test__MApi_XC_Sys_Init_PQ_call_MApi_XC_PQ_LoadFunction */

/* CPPTEST_TEST_CASE_BEGIN test_MApi_XC_Sys_PQ_SetNR_ForceOff */
/* CPPTEST_TEST_CASE_CONTEXT void MApi_XC_Sys_PQ_SetNR(E_XC_PQ_3D_NR, SCALER_WIN) */
extern PQ_3D_NR_FUNCTION_TYPE g_PQ_e3DNRType;
extern MS_BOOL g_XC_bIsMemoryFormat422;
extern MS_BOOL g_XC_bIsFBL;
void TestSuite_apiXC_Sys_test_MApi_XC_Sys_PQ_SetNR_ForceOff()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (en3DNRType) */
    E_XC_PQ_3D_NR _en3DNRType  = E_XC_PQ_3D_NR_HIGH;
    /* Initializing argument 2 (eWindow) */
    SCALER_WIN _eWindow  = MAIN_WINDOW;

    { // Test memory format is FB_444
    	g_XC_bIsMemoryFormat422 = 0;
    	g_XC_bIsFBL = 0;

        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( PQ_3D_NR_OFF, (g_PQ_e3DNRType) );
    }

    { // Test memory format is FBL_422
       	g_XC_bIsMemoryFormat422 = 1;
       	g_XC_bIsFBL = 1;

        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( PQ_3D_NR_OFF, (g_PQ_e3DNRType) );
    }
#if 0
    { // Test memory format is FB_422
       	g_XC_bIsMemoryFormat422 = 1;
       	g_XC_bIsFBL = 0;

        /* Tested function call */
        MApi_XC_Sys_PQ_SetNR(_en3DNRType, _eWindow);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( PQ_3D_NR_OFF, (g_PQ_e3DNRType) );
    }
#endif
}
/* CPPTEST_TEST_CASE_END test_MApi_XC_Sys_PQ_SetNR_ForceOff */
