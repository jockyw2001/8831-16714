#include "cpptest.h"

//$ Hal & CPU
#include "hwreg.h" //"hwreg_S4LE.h" //2009/06/18
//$ Utility
#include "drvGlobal.h"
#include "drvTSP.h"
#include "drvpower_if.h"
#include "MsCommon.h"
#include "MsIRQ.h"
#include "MsOS.h"

CPPTEST_CONTEXT("/UTProject/power/emerald/drvPower.c");
CPPTEST_TEST_SUITE_INCLUDED_TO("/UTProject/power/emerald/drvPower.c");

CPPTEST_TEST_SUITE(TestSuit_drvPower);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForAdcRgbBiasCurrentControlSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForAdcSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Get_Power_Flag);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForAudio);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForBandGapBiasSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForCvbsBufOutSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForCytlifSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForDacCvbsSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForDcSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForFastBlankingSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForGmcSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForLvdsSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForMvdM4vSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForRvdSet);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveForStrld);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForATV);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForAV);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForComponent);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForDTV);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForHDMI);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForRGB);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForSV);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForScart);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForStorage);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_CheckAnalogIP);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_CheckDigitIP);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_GetVerInfo);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_Init);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_Is1STBootUp);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_Saving_Mode);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_Set_PDMode);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_Set_HwClock);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_PsPrintIndi);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S1);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S2);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S3);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S4);
CPPTEST_TEST(TestSuit_drvPower_test_MDrv_Power_IsPowerDown_default);
CPPTEST_TEST_SUITE_END();


void TestSuit_drvPower_test_MDrv_PowerSaveForAdcRgbBiasCurrentControlSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForAdcSet();
void TestSuit_drvPower_test_MDrv_Get_Power_Flag();
void TestSuit_drvPower_test_MDrv_PowerSaveForAudio();
void TestSuit_drvPower_test_MDrv_PowerSaveForBandGapBiasSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForCvbsBufOutSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForCytlifSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForDacCvbsSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForDcSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForFastBlankingSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForGmcSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForLvdsSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForMvdM4vSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForRvdSet();
void TestSuit_drvPower_test_MDrv_PowerSaveForStrld();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForATV();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForAV();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForComponent();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForDTV();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForHDMI();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForRGB();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForSV();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForScart();
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForStorage();
void TestSuit_drvPower_test_MDrv_Power_CheckAnalogIP();
void TestSuit_drvPower_test_MDrv_Power_CheckDigitIP();
void TestSuit_drvPower_test_MDrv_Power_GetVerInfo();
void TestSuit_drvPower_test_MDrv_Power_Init();
void TestSuit_drvPower_test_MDrv_Power_Is1STBootUp();
void TestSuit_drvPower_test_MDrv_Power_Saving_Mode();
void TestSuit_drvPower_test_MDrv_Power_Set_PDMode();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown();
void TestSuit_drvPower_test_MDrv_Power_Set_HwClock();
void TestSuit_drvPower_test_MDrv_PsPrintIndi();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S1();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S2();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S3();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S4();
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_default();
CPPTEST_TEST_SUITE_REGISTRATION(TestSuit_drvPower);

void TestSuit_drvPower_setUp()
{
}

void TestSuit_drvPower_tearDown()
{
}


/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForAdcRgbBiasCurrentControlSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForAdcRgbBiasCurrentControlSet(PowerSaveIndi_t) */


void TestSuit_drvPower_test_MDrv_PowerSaveForAdcRgbBiasCurrentControlSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t  _PsIndi ;
    unsigned long a[0x3000] ;

    RIU_MAP = a;
    _PsIndi.AdcRgbBiasCurrentControl = 1;
    {
        /* Tested function call */
        MDrv_PowerSaveForAdcRgbBiasCurrentControlSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.AdcRgbBiasCurrentControl = 0;
    {
        /* Tested function call */
        MDrv_PowerSaveForAdcRgbBiasCurrentControlSet(_PsIndi);
        /* Post-condition check */
    }


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForAdcRgbBiasCurrentControlSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForAdcSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForAdcSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForAdcSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.AdcR = 1 ;_PsIndi.AdcG = 1 ; _PsIndi.AdcB = 1 ;_PsIndi.AdcY= 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForAdcSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.AdcR = 0;_PsIndi.AdcG =0 ; _PsIndi.AdcB = 0 ;_PsIndi.AdcY= 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForAdcSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForAdcSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Get_Power_Flag */
/* CPPTEST_TEST_CASE_CONTEXT U8 MDrv_Get_Power_Flag(U8) */
void TestSuit_drvPower_test_MDrv_Get_Power_Flag()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Flag) */ 
    unsigned long a[0x3000] ;

    RIU_MAP = a;
    U8 _u8Flag  = 0;
    {
        /* Tested function call */
        U8 _return  = MDrv_Get_Power_Flag(_u8Flag);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Get_Power_Flag */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForAudio */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForAudio(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForAudio()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Audio = 1;
    {
        /* Tested function call */
        MDrv_PowerSaveForAudio(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.Audio = 0;
    {
        /* Tested function call */
        MDrv_PowerSaveForAudio(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForAudio */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForBandGapBiasSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForBandGapBiasSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForBandGapBiasSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.VRefPdn = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForBandGapBiasSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.VRefPdn = 0;
    {
        /* Tested function call */
        MDrv_PowerSaveForBandGapBiasSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForBandGapBiasSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForCvbsBufOutSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForCvbsBufOutSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForCvbsBufOutSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.CvbsBufOut = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForCvbsBufOutSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.CvbsBufOut = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForCvbsBufOutSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForCvbsBufOutSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForCytlifSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForCytlifSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForCytlifSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Cytlif = 1;
    {
        /* Tested function call */
        MDrv_PowerSaveForCytlifSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForCytlifSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForDacCvbsSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForDacCvbsSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForDacCvbsSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.DacCvbs = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForDacCvbsSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.DacCvbs = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForDacCvbsSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForDacCvbsSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForDcSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForDcSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForDcSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Dc = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForDcSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForDcSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForFastBlankingSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForFastBlankingSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForFastBlankingSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.FastBlanking = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForFastBlankingSet(_PsIndi);
        /* Post-condition check */
    }
    _PsIndi.FastBlanking = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForFastBlankingSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForFastBlankingSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForGmcSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForGmcSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForGmcSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Vd = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForGmcSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForGmcSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForLvdsSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForLvdsSet(void) */
void TestSuit_drvPower_test_MDrv_PowerSaveForLvdsSet()
{
    unsigned long a[0x3000] ;

    RIU_MAP = a;
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_PowerSaveForLvdsSet();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForLvdsSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForMvdM4vSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForMvdM4vSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForMvdM4vSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.MvdM4V = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForMvdM4vSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForMvdM4vSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForRvdSet */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForRvdSet(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForRvdSet()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Rvd = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForRvdSet(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForRvdSet */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveForStrld */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveForStrld(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PowerSaveForStrld()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    _PsIndi.Strld = 1 ;
    {
        /* Tested function call */
        MDrv_PowerSaveForStrld(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveForStrld */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForATV */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForATV(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForATV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForATV(_pPsIndi);
        /* Post-condition check */

    }

    PowerSaveIndi_t st_temp;
    _pPsIndi  = &st_temp;
    MDrv_PowerSaveSetFlagForATV(_pPsIndi);

}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForATV */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForAV */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForAV(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForAV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForAV(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp;
    _pPsIndi = &st_temp;
    MDrv_PowerSaveSetFlagForAV(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForAV */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForComponent */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForComponent(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForComponent()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForComponent(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForComponent(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForComponent */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForDTV */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForDTV(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForDTV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForDTV(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForDTV(_pPsIndi);

}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForDTV */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForHDMI */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForHDMI(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForHDMI()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForHDMI(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForHDMI(_pPsIndi);

}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForHDMI */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForRGB */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForRGB(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForRGB()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForRGB(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForRGB(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForRGB */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForSV */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForSV(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForSV()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForSV(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForSV(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForSV */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForScart */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForScart(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForScart()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForScart(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = &st_temp ;
    MDrv_PowerSaveSetFlagForScart(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForScart */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PowerSaveSetFlagForStorage */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PowerSaveSetFlagForStorage(PowerSaveIndi_t *) */
void TestSuit_drvPower_test_MDrv_PowerSaveSetFlagForStorage()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (pPsIndi) */ 
    PowerSaveIndi_t * _pPsIndi  = 0 ;
    {
        /* Tested function call */
        MDrv_PowerSaveSetFlagForStorage(_pPsIndi);
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_PTR("PowerSaveIndi_t * _pPsIndi ", ( _pPsIndi ));
    }
    PowerSaveIndi_t st_temp ;
    _pPsIndi = & st_temp ;
    MDrv_PowerSaveSetFlagForStorage(_pPsIndi);


}
/* CPPTEST_TEST_CASE_END test_MDrv_PowerSaveSetFlagForStorage */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_CheckAnalogIP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_CheckAnalogIP(void) */
void TestSuit_drvPower_test_MDrv_Power_CheckAnalogIP()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_CheckAnalogIP();
        /* Post-condition check */
        CPPTEST_ASSERT_EQUAL(ANALOG_IP, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_CheckAnalogIP */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_CheckDigitIP */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_CheckDigitIP(void) */
void TestSuit_drvPower_test_MDrv_Power_CheckDigitIP()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_CheckDigitIP();
        /* Post-condition check */
        //CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
        CPPTEST_ASSERT_EQUAL(DIGITAL_IP, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_CheckDigitIP */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_GetVerInfo */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Power_GetVerInfo(U8 **) */
void TestSuit_drvPower_test_MDrv_Power_GetVerInfo()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (ppVerInfo) */ 
    U8 temp ;
    U8 *p_temp = &temp ;
    U8 ** _ppVerInfo  = &p_temp ;
    {
        /* Tested function call */
        MDrv_Power_GetVerInfo(_ppVerInfo);
        /* Post-condition check */
        // CPPTEST_POST_CONDITION_PTR("U8 ** _ppVerInfo ", ( _ppVerInfo ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_GetVerInfo */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_Init */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Power_Init(void) */
void TestSuit_drvPower_test_MDrv_Power_Init()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        MDrv_Power_Init();
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_Init */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_Is1STBootUp */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_Is1STBootUp(U8, U32) */
void TestSuit_drvPower_test_MDrv_Power_Is1STBootUp()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Chk1stBootMode) */ 

    unsigned long a[0x3000];
    RIU_MAP = a ;
    ///////////////////////////////////////////////////////if
    U8 _u8Chk1stBootMode  = CHECK_RTC_OCLOCK;
    /* Initializing argument 2 (u32SysTime) */ 
    U32 _u32SysTime  = 0ul;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_Is1STBootUp(_u8Chk1stBootMode, _u32SysTime);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
    /////////////////////////////////////////////////////////else
    _u8Chk1stBootMode =  CHECK_PM_OFF_FLAG;
    {
        BOOLEAN  _return  = MDrv_Power_Is1STBootUp(_u8Chk1stBootMode, _u32SysTime);
        CPPTEST_ASSERT_BOOL_EQUAL(TRUE, ( _return ));
    }
    //////////////////////////////////////////////////// return false
    _u8Chk1stBootMode =  0;
    {
        BOOLEAN   _return  = MDrv_Power_Is1STBootUp(_u8Chk1stBootMode, _u32SysTime);
        CPPTEST_ASSERT_BOOL_EQUAL(FALSE, ( _return ));
    }

}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_Is1STBootUp */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_Saving_Mode */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Power_Saving_Mode(U8, BOOLEAN, BOOLEAN) */
void TestSuit_drvPower_test_MDrv_Power_Saving_Mode()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Flag) */ 
    U8 _u8Flag  = PSM_MPEG;
    /* Initializing argument 2 (bEnable) */ 
    U8 _bEnable  = 1;//////////////////////////////////////////////if
    /* Initializing argument 3 (bPwrSaveT) */ 
    U8 _bPwrSaveT  = 0;
    {
        /* Tested function call */
        MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);
        /* Post-condition check */
    }
    _u8Flag  = PSM_DEMUX;
    MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);
    _u8Flag  = PSM_GE;
    MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);

    _bEnable  = 0;//////////////////////////////////////////////else
    _u8Flag  = PSM_DEMUX;

    MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);
    _u8Flag  = PSM_GE;
    MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);
    _u8Flag  = PSM_MPEG;
    MDrv_Power_Saving_Mode(_u8Flag, _bEnable, _bPwrSaveT);


}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_Saving_Mode */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_Set_PDMode */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_Power_Set_PDMode(U8) */
void TestSuit_drvPower_test_MDrv_Power_Set_PDMode()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (u8Mode) */ 
    unsigned long a[0x3000];
    RIU_MAP = a ;

    U8 _u8Mode;
    _u8Mode = POWERMODE_S1;
    MDrv_Power_Set_PDMode(_u8Mode);
    _u8Mode = POWERMODE_S2;
    MDrv_Power_Set_PDMode(_u8Mode);
    _u8Mode = POWERMODE_S3;
    MDrv_Power_Set_PDMode(_u8Mode);
    _u8Mode = POWERMODE_S4;
    MDrv_Power_Set_PDMode(_u8Mode);
    _u8Mode = 2*POWERMODE_S4;
    MDrv_Power_Set_PDMode(_u8Mode);


}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_Set_PDMode */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown()
{
    /* Pre-condition initialization */
    unsigned int a[0x3000];
    RIU_MAP = a ;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown */



/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_Set_HwClock */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_Set_HwClock(HW_MODULE_CLOCK_SETTING, int) */
void TestSuit_drvPower_test_MDrv_Power_Set_HwClock()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (eModule) */ 
    HW_MODULE_CLOCK_SETTING _eModule  = E_HWCLK_USB_ONOFF;
    /* Initializing argument 2 (eValue) */ 
    int _eValue  = 0;
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    }
    _eModule =  E_HWCLK_MCU_SETTING;
    BOOLEAN _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_AEON_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_MIU_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_TSP_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_TS0_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_TS2_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule =  E_HWCLK_TSOUT_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule  =E_HWCLK_STC0_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    //////////////
    _eModule  =E_HWCLK_MVD_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_MVDBOOT_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_M4V_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_DC0_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_DHC_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule  =E_HWCLK_GE_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule  =E_HWCLK_GOP0_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_GOP0_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    _eModule  =E_HWCLK_GOP1_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    _eModule  =E_HWCLK_GOPD_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    _eModule  =E_HWCLK_VD_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    _eModule  =E_HWCLK_VE_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    _eModule = E_HWCLK_STRLD_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_DDR_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_DAC_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_USB_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));
    
    _eModule  =E_HWCLK_PCMCIA_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_FCIE_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_FCLK_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_FMCLK_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_ODCLK_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_FICLKF2_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_IDCLK2_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));

    _eModule = E_HWCLK_TCK_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(1, ( _return ));



    _eModule = 2*E_HWCLK_FMCLK_ONOFF;
    _return  = MDrv_Power_Set_HwClock(_eModule, _eValue);
    CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));






}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_Set_HwClock */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_PsPrintIndi */
/* CPPTEST_TEST_CASE_CONTEXT void MDrv_PsPrintIndi(PowerSaveIndi_t) */
void TestSuit_drvPower_test_MDrv_PsPrintIndi()
{
    /* Pre-condition initialization */
    /* Initializing argument 1 (PsIndi) */ 
    PowerSaveIndi_t _PsIndi ;
    memset(&_PsIndi , 0 , sizeof(PowerSaveIndi_t));
    {
        /* Tested function call */
        MDrv_PsPrintIndi(_PsIndi);
        /* Post-condition check */
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_PsPrintIndi */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown_S1 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S1()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}

/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown_S1 */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown_S2 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S2()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown_S2 */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown_S3 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S3()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown_S3 */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown_S4 */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_S4()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_ASSERT_BOOL_EQUAL(0, ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown_S4 */

/* CPPTEST_TEST_CASE_BEGIN test_MDrv_Power_IsPowerDown_default */
/* CPPTEST_TEST_CASE_CONTEXT BOOLEAN MDrv_Power_IsPowerDown(void) */
void TestSuit_drvPower_test_MDrv_Power_IsPowerDown_default()
{
    /* Pre-condition initialization */
    {
        /* Tested function call */
        BOOLEAN _return  = MDrv_Power_IsPowerDown();
        /* Post-condition check */
        CPPTEST_POST_CONDITION_UINTEGER("U8 _return", ( _return ));
    }
}
/* CPPTEST_TEST_CASE_END test_MDrv_Power_IsPowerDown_default */
