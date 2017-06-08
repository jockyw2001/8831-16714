

#include "hal_misc.h"
#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
#include "msAPI_Timer.h"
#include "msAPI_Global.h"
#endif
void MDrv_Sys_StopCpu(MS_BOOL bEnable)
{
    if(bEnable)
    {
        printf("[FORCE STOP]MDrv_Sys_StopCpu\n");
        while(1);
    }
}

void MDrv_SysInit_CheckSbootUseTime(void)
{
    //for auto test recording booting time from Sboot to Ck3
    //U32 PiuTick = MDrv_Read2Byte(0x3048);
    //PiuTick |= (MDrv_Read2Byte(0x304a) << 16);
    U32 u32PiuTick = MHAL_PIU_TIMER_Get_CurTick(PIU_TIMER_1);

    //printf("PiuTick= 0x%X\n", PiuTick);
    U32 u32SbootUseTimeMs = ((float)u32PiuTick / 12000000ul)*1000 ;  //ms


#if (ENABLE_AUTOTEST || ENABLE_BOOTTIME)
    PRINT_AUTOTEST_TIME("start sysinit", u32SbootUseTimeMs);
    INIT_AUTOTEST_CHECKPT(u32SbootUseTimeMs);
#endif

    printf("sboot use %ums\n", u32SbootUseTimeMs);
}


#ifdef __aeon__
void Aeon_Exception_Handler(MHAL_SavedRegisters *regs, MS_U32 vector)
{
    printf("\nException: %d\n", vector);

    printf("r0 : %08X  r1 : %08X  r2 : %08X  r3 : %08X\n", regs->r[0],  regs->r[1],  regs->r[2],  regs->r[3]);
    printf("r4 : %08X  r5 : %08X  r6 : %08X  r7 : %08X\n", regs->r[4],  regs->r[5],  regs->r[6],  regs->r[7]);
    printf("r8 : %08X  r9 : %08X  r10: %08X  r11: %08X\n", regs->r[8],  regs->r[9],  regs->r[10], regs->r[11]);
    printf("r12: %08X  r13: %08X  r14: %08X  r15: %08X\n", regs->r[12], regs->r[13], regs->r[14], regs->r[15]);
    printf("r16: %08X  r17: %08X  r18: %08X  r19: %08X\n", regs->r[16], regs->r[17], regs->r[18], regs->r[19]);
    printf("r20: %08X  r21: %08X  r22: %08X  r23: %08X\n", regs->r[20], regs->r[21], regs->r[22], regs->r[23]);
    printf("r24: %08X  r25: %08X  r26: %08X  r27: %08X\n", regs->r[24], regs->r[25], regs->r[26], regs->r[27]);
    printf("r28: %08X  r29: %08X  r30: %08X  r31: %08X\n", regs->r[28], regs->r[29], regs->r[30], regs->r[31]);

    printf("sr : %08X  pc : %08X  eear: %08X\n", regs->sr, regs->pc, regs->eear);

#if( ENABLE_R2_BACKTRACE )
    r2_online_except_bt(regs->r[1], regs->pc, regs->r[9]);
#endif

    // CPU Stay in here
    MDrv_Sys_StopCpu(ENABLE);
}
#endif


