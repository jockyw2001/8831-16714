#include "cpptest.h"

CPPTEST_CONTEXT("/UTProject/app/MApp_CADTV_Proc.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/app/MApp_CADTV_Proc.c");

CPPTEST_TEST_SUITE(TestSuite_MApp_CADTV_Proc);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseQamType);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseQamType);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CATV_RestoreManutuning_settingDefault_SUCCESS);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetFrequency_SUCCESS);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case1);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case2);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetSymbol_SUCCESS);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetQamType_SUCCESS);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_IF);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_ELSE);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetNID_SUCCESS);
CPPTEST_TEST(TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetNID_SUCESS);
CPPTEST_TEST_SUITE_END();
        

void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseQamType();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseQamType();
void TestSuite_MApp_CADTV_Proc_test_MApp_CATV_RestoreManutuning_settingDefault_SUCCESS();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetFrequency_SUCCESS();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case1();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case2();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetSymbol_SUCCESS();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetQamType_SUCCESS();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_IF();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_ELSE();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetNID_SUCCESS();
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetNID_SUCESS();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuite_MApp_CADTV_Proc);

void TestSuite_MApp_CADTV_Proc_setUp()
{
}

void TestSuite_MApp_CADTV_Proc_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_IncreaseQamType */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_IncreaseQamType(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseQamType()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */ 
    {
         _enCadtvManualTuningQamType  = CAB_QAM16;
    }
    {
        /* Tested function call */
    	BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM32, ( _enCadtvManualTuningQamType ) );
    }

    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */
    {
         _enCadtvManualTuningQamType  = CAB_QAM32;
    }
    {
        /* Tested function call */
    	BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM64, ( _enCadtvManualTuningQamType ) );
    }

    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */
    {
         _enCadtvManualTuningQamType  = CAB_QAM64;
    }
    {
        /* Tested function call */
    	BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM128, ( _enCadtvManualTuningQamType ) );
    }

    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */
    {
         _enCadtvManualTuningQamType  = CAB_QAM128;
    }
    {
        /* Tested function call */
    	BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM256, ( _enCadtvManualTuningQamType ) );
    }

    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */
    {
         _enCadtvManualTuningQamType  = CAB_QAM256;
    }
    {
        /* Tested function call */
    	BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _enCadtvManualTuningQamType ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_IncreaseQamType */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_DecreaseQamType */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_DecreaseQamType(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseQamType()
{
	    {
	         _enCadtvManualTuningQamType  = CAB_QAM16;
	    }
	    {
	        /* Tested function call */
	    	BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseQamType();
	        /* Post-condition check */
	        CPPTEST_ASSERT_EQUAL( CAB_QAM256, ( _enCadtvManualTuningQamType ) );
	        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
	    }
	    /* Pre-condition initialization */
	       /* Initializing global variable _enCadtvManualTuningQamType */
	       {
	            _enCadtvManualTuningQamType  = CAB_QAM32;
	       }
	       {
	           /* Tested function call */
			   BOOLEAN _return  =  MApp_CadtvManualTuning_DecreaseQamType();
	           /* Post-condition check */
	           CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _enCadtvManualTuningQamType ) );
	           CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
	       }

	       /* Pre-condition initialization */
	       /* Initializing global variable _enCadtvManualTuningQamType */
	       {
	            _enCadtvManualTuningQamType  = CAB_QAM64;
	       }
	       {
	           /* Tested function call */
	           BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseQamType();
	           /* Post-condition check */
	           CPPTEST_ASSERT_EQUAL( CAB_QAM32, ( _enCadtvManualTuningQamType ) );
	           CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
	       }

	       /* Pre-condition initialization */
	       /* Initializing global variable _enCadtvManualTuningQamType */
	       {
	            _enCadtvManualTuningQamType  = CAB_QAM128;
	       }
	       {
	           /* Tested function call */
	       	BOOLEAN _return  =  MApp_CadtvManualTuning_DecreaseQamType();
	           /* Post-condition check */
	           CPPTEST_ASSERT_EQUAL( CAB_QAM64, ( _enCadtvManualTuningQamType ) );
	           CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
	       }

	       /* Pre-condition initialization */
	       /* Initializing global variable _enCadtvManualTuningQamType */
	       {
	            _enCadtvManualTuningQamType  = CAB_QAM256;
	       }
	       {
	           /* Tested function call */
	       	   BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseQamType();
	           /* Post-condition check */
	           CPPTEST_ASSERT_EQUAL( CAB_QAM128, ( _enCadtvManualTuningQamType ) );
	           CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
	       }

}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_DecreaseQamType */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CATV_RestoreManutuning_settingDefault_SUCCESS */
/* CPPTEST_TEST_CASE_CONTEXT void MApp_CATV_RestoreManutuning_settingDefault(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CATV_RestoreManutuning_settingDefault_SUCCESS()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = 0u;
    }
    /* Initializing global variable _enCadtvManualTuningQamType */ 
    {
         _enCadtvManualTuningQamType  = CAB_QAM16;
    }
    /* Initializing global variable _u16CadtvNetworkTuningNetworkID */ 
    {
         _u16CadtvNetworkTuningNetworkID  = 0u;
    }
    {
        /* Tested function call */
        MApp_CATV_RestoreManutuning_settingDefault();
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CATV_RestoreManutuning_settingDefault_SUCCESS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_IncreaseFrequency_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_IncreaseFrequency(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_IF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseFrequency();
        CPPTEST_ASSERT_UINTEGER_EQUAL( 500, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_IncreaseFrequency_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_IncreaseFrequency_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_IncreaseFrequency(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseFrequency_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = MAX_DVBC_FREQUENCY;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseFrequency();
        CPPTEST_ASSERT_UINTEGER_EQUAL( MIN_DVBC_FREQUENCY, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_IncreaseFrequency_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_DecreaseFrequency_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_DecreaseFrequency(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_IF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
    	_u32CadtvManualTuningFrequency  = MIN_DVBC_FREQUENCY+500;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseFrequency();
        CPPTEST_ASSERT_UINTEGER_EQUAL( MIN_DVBC_FREQUENCY, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_DecreaseFrequency_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_DecreaseFrequency_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_DecreaseFrequency(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseFrequency_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = MIN_DVBC_FREQUENCY;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseFrequency();
        CPPTEST_ASSERT_UINTEGER_EQUAL(MAX_DVBC_FREQUENCY, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        /* Post-condition check */

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_DecreaseFrequency_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_GetFrequency_SUCCESS */
/* CPPTEST_TEST_CASE_CONTEXT U32 MApp_CadtvManualTuning_GetFrequency(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetFrequency_SUCCESS()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    {
        /* Tested function call */
        U32 _return  = MApp_CadtvManualTuning_GetFrequency();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_GetFrequency_SUCCESS */

/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetFrequency_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetFrequency_IF_Case1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetFrequency(U32) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case1()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32freq) */ 
    U32 _u32freq  = MAX_DVBC_FREQUENCY;
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetFrequency(_u32freq);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MAX_DVBC_FREQUENCY, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetFrequency_IF_Case1 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetFrequency_IF_Case2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetFrequency(U32) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_IF_Case2()
{
    /* Pre-condition initialization */
	/* Initializing argument 1 (u32freq) */
	U32 _u32freq  = MIN_DVBC_FREQUENCY;
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetFrequency(_u32freq);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( MIN_DVBC_FREQUENCY, ( _u32CadtvManualTuningFrequency ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );

     }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetFrequency_IF_Case2 */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetFrequency_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetFrequency(U32) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetFrequency_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u32freq) */ 
    U32 _u32freq  = MAX_DVBC_FREQUENCY+1;
    /* Initializing global variable _u32CadtvManualTuningFrequency */ 
    {
         _u32CadtvManualTuningFrequency  = 0ul;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetFrequency(_u32freq);
        /* Post-condition check */

        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetFrequency_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_IncreaseSymbol_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_IncreaseSymbol(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_IF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = 0u;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseSymbol();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(1, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_IncreaseSymbol_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_IncreaseSymbol_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_IncreaseSymbol(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_IncreaseSymbol_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = MAX_DVBC_SYMBOL_RATE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_IncreaseSymbol();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MIN_DVBC_SYMBOL_RATE, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_IncreaseSymbol_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_DecreaseSymbol_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_DecreaseSymbol(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_IF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = MAX_DVBC_SYMBOL_RATE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseSymbol();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MAX_DVBC_SYMBOL_RATE-1, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_DecreaseSymbol_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_DecreaseSymbol_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_DecreaseSymbol(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_DecreaseSymbol_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = MIN_DVBC_SYMBOL_RATE;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_DecreaseSymbol();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MAX_DVBC_SYMBOL_RATE, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_DecreaseSymbol_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_GetSymbol_SUCCESS */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_CadtvManualTuning_GetSymbol(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetSymbol_SUCCESS()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = 0u;
    }
    {
        /* Tested function call */
        U16 _return  = MApp_CadtvManualTuning_GetSymbol();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(0, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_GetSymbol_SUCCESS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetSymbol_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetSymbol(U16) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_IF()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = 0u;
    }
    {
		/* Initializing argument 1 (u16Sym) */
		U16 _u16Sym  = MAX_DVBC_SYMBOL_RATE;
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetSymbol(_u16Sym);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MAX_DVBC_SYMBOL_RATE, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }

    {
		/* Initializing argument 1 (u16Sym) */
    	U16 _u16Sym  = MIN_DVBC_SYMBOL_RATE;
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetSymbol(_u16Sym);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL(MIN_DVBC_SYMBOL_RATE, (  _u16CadtvManualTuningSymbo ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetSymbol_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetSymbol_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetSymbol(U16) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetSymbol_ELSE()
{
    /* Pre-condition initialization */

    /* Initializing global variable _u16CadtvManualTuningSymbo */ 
    {
         _u16CadtvManualTuningSymbo  = 0u;
    }
    {
		/* Initializing argument 1 (u16Sym) */
	    U16 _u16Sym  = MAX_DVBC_SYMBOL_RATE+1;
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetSymbol(_u16Sym);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
    {
    	 /* Initializing argument 1 (u16Sym) */
    	 U16 _u16Sym  = MIN_DVBC_SYMBOL_RATE-1;
         /* Tested function call */
         BOOLEAN _return  = MApp_CadtvManualTuning_SetSymbol(_u16Sym);
         /* Post-condition check */
         CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetSymbol_ELSE */


/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_GetQamType_SUCCESS */
/* CPPTEST_TEST_CASE_CONTEXT EN_CAB_CONSTEL_TYPE MApp_CadtvManualTuning_GetQamType(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetQamType_SUCCESS()
{
    /* Pre-condition initialization */
    /* Initializing global variable _enCadtvManualTuningQamType */ 
    {
         _enCadtvManualTuningQamType  = CAB_QAM16;
    }
    {
        /* Tested function call */
        EN_CAB_CONSTEL_TYPE _return  = MApp_CadtvManualTuning_GetQamType();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _return ) );
        CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _enCadtvManualTuningQamType ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_GetQamType_SUCCESS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetQamType_IF */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetQamType(EN_CAB_CONSTEL_TYPE) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_IF()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eQAM) */ 

    /* Initializing global variable _enCadtvManualTuningQamType */ 
    {
         _enCadtvManualTuningQamType  = CAB_QAM16;
    }
    {
	    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM256;
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( CAB_QAM256, ( _enCadtvManualTuningQamType ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
    }
    {
    	    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM128;
            /* Tested function call */
            BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
            /* Post-condition check */
            CPPTEST_ASSERT_EQUAL( CAB_QAM128, ( _enCadtvManualTuningQamType ) );
            CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
        }
    {
       	    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM64;
               /* Tested function call */
               BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( CAB_QAM64, ( _enCadtvManualTuningQamType ) );
               CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
           }
    {
       	    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM32;
               /* Tested function call */
               BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( CAB_QAM32, ( _enCadtvManualTuningQamType ) );
               CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
           }
    {
       	    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM16;
               /* Tested function call */
               BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
               /* Post-condition check */
               CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _enCadtvManualTuningQamType ) );
               CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );
           }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetQamType_IF */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetQamType_ELSE */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetQamType(EN_CAB_CONSTEL_TYPE) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetQamType_ELSE()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eQAM) */ 
    EN_CAB_CONSTEL_TYPE _eQAM  = CAB_QAM256+1;
    /* Initializing global variable _enCadtvManualTuningQamType */ 
    {
         _enCadtvManualTuningQamType  = CAB_QAM16;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetQamType(_eQAM);
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL( CAB_QAM16, ( _enCadtvManualTuningQamType ) );
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ) );
    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetQamType_ELSE */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_GetNID_SUCCESS */
/* CPPTEST_TEST_CASE_CONTEXT U16 MApp_CadtvManualTuning_GetNID(void) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_GetNID_SUCCESS()
{
    /* Pre-condition initialization */
    /* Initializing global variable _u16CadtvNetworkTuningNetworkID */ 
    {
         _u16CadtvNetworkTuningNetworkID  = 0u;
    }

    {
        /* Tested function call */
        U16 _return  = MApp_CadtvManualTuning_GetNID();
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0, _return );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_GetNID_SUCCESS */

/* CPPTEST_TEST_CASE_BEGIN test_MApp_CadtvManualTuning_SetNID_SUCESS */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MApp_CadtvManualTuning_SetNID(U16) */
void TestSuite_MApp_CADTV_Proc_test_MApp_CadtvManualTuning_SetNID_SUCESS()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u16NID) */
    U16 _u16NID  = 0u;
    /* Initializing global variable _u16CadtvNetworkTuningNetworkID */
    {
         _u16CadtvNetworkTuningNetworkID  = 0u;
    }
    {
        /* Tested function call */
        BOOLEAN _return  = MApp_CadtvManualTuning_SetNID(_u16NID);
        /* Post-condition check */
        CPPTEST_ASSERT_UINTEGER_EQUAL( 0, ( _u16CadtvNetworkTuningNetworkID ) );
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ) );

    }
}
/* CPPTEST_TEST_CASE_END test_MApp_CadtvManualTuning_SetNID_SUCESS */
