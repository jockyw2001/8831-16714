

#if (ENABLE_MSTV_UART_DEBUG)

UartCommadType g_UartCommand; // Uart command struct

#endif // ENABLE_MSTV_UART_DEBUG

extern void putcharb(MS_U8 byte);	//Ray URT 2017.02.03
extern void dv_IntReadUART1Data(BYTE readData);	//Ray URT 2017.02.03

// Check uart protocal
bit IsUartCmdValid(U8* au8Buffer)
{
    BYTE i, ucLen;
    BYTE ucCS = 0;

    if( UART_EXT_Buf(au8Buffer) )
    {
        ucLen = UART_CMD_EXT_LENGTH_Buf(au8Buffer);
    }
    else
    {
        ucLen = UART_CMD_LENGTH_Buf(au8Buffer);
    }

    ucCS = 0;
    for( i = 0; i < ucLen; ++ i )
    {
        ucCS += au8Buffer[i];
    }

    if( ucCS == 0xFF )
        return 1;

    return 0;
}


//Ray URT 2017.02.03: Modified MDrv_UART_RecvHandler routine for SP-4096

void MDrv_UART_RecvHandler(int c, MS_U32 pHalReg)
{
    //Ray URT 2017.02.02: Transmit the received UART command for testing
    //putcharb((BYTE)(c&0xff));


    dv_IntReadUART1Data((BYTE)(c&0xff));			//Ray URT 2017.02.03: Put received data byte into buffer

    MsOS_EnableInterrupt(E_INT_IRQ_UART0);

}


//Ray URT 2017.02.03: Below is the original code of MDrv_UART_RecvHandler
/*
void MDrv_UART_RecvHandler(int c, MS_U32 pHalReg)
{	
#if 0//( ENABLE_R2_BACKTRACE )
    if( MDrv_R2BT_RecvDataHandler(c, pHalReg) )
    {
        return;
    }
#endif

#if( CHAKRA3_AUTO_TEST )
    MApp_AT_RecvDataHandler(c);

    if( MApp_AT_Is_NeedDisableOtherUartFunction() )
        return;
#endif

    g_Uart0CheckTick = 50;// time-out control ms

    if (g_UartCommand.Index >= _UART_CMD_LENGTH_)
    {
        g_UartCommand.Index = 0;
    }
    //Ray URT 2017.02.02: Transmit the received UART command
    putcharb((BYTE)(c&0xff));
    putcharb((BYTE)((c&0xff00)>>8));

    if( (c == 0x7F) && (g_UartCommand.Index==0) )// Press "Delete" to get PC & RA
    {
        MDrv_AeonR2_Backtrace(pHalReg);
    }

#if 0//(ENABLE_MMS)
    // detect dash
    if ((0x2D == c)&& (1 == DbgMenuMode))
    {
        InputPara = 1;
    }

    // recieve byte
    if (!InputPara)
    {
#endif
        UART_RX_BUF[g_UartCommand.Index] = c;
#if 0//(ENABLE_MMS)
    } else
    {
        MDrv_MMS_ParseCmdParm(c);
    }

    // receive for menu mode
    if (1 == DbgMenuMode)
    {
        MDrv_MMS_UARTRecvHandler(c);
        return;
    }

#endif

    // check command buffer index
    if (UART_EXT_Buf(UART_RX_BUF))
    {
        if (g_UartCommand.Index == 0) // check 1st data
        {
            g_UartCommand.Index++; // for get UART_CMD_EXT_LENGTH
        }
        else
        {
            if (g_UartCommand.Index < UART_CMD_EXT_LENGTH_Buf(UART_RX_BUF)) // still read command
            {
                g_UartCommand.Index++; // next index of command buffer
            }

            if (g_UartCommand.Index >= UART_CMD_EXT_LENGTH_Buf(UART_RX_BUF)) // read command ok
            {
                if( IsUartCmdValid((UART_RX_BUF)) )
                {
                    memcpy(g_UartCommand.Buffer, UART_RX_BUF, UART_CMD_EXT_LENGTH_Buf(UART_RX_BUF));
                    g_UartCommand.u8CmdLen = UART_CMD_EXT_LENGTH_Buf(UART_RX_BUF);
                    g_bUart0Detected = TRUE; // command  buffer recieve ok
                }

                g_UartCommand.Index = 0; // reset index of command buffer
                g_Uart0CheckTick = 0;
            }
        }
    }
    else
    {
        if (g_UartCommand.Index < UART_CMD_LENGTH_Buf(UART_RX_BUF)) // still read command
        {
            g_UartCommand.Index ++; // next index of command buffer
        }

        if (g_UartCommand.Index >= UART_CMD_LENGTH_Buf(UART_RX_BUF)) // read command ok
        {
            // check if Enter Key. (0x0D)
        #if 0//(ENABLE_MMS)
            if (g_UartCommand.Buffer[_UART_CMD_CODE_] == 0x0D) {

                //set flag to enter menu mode
                DbgMenuMode = 1;
                MDrv_LogoPrint();
                if (!(DbgMenuLevel ||CatMenuLevel || CfgMenuLevel || UntMenuLevel))
                    MDrv_MainPagePrint();
            }
        #endif

        #if 1//( ENABLE_UART_CHECKSUM )
            if( IsUartCmdValid((UART_RX_BUF)) )
        #endif
            {
                memcpy(g_UartCommand.Buffer, UART_RX_BUF, UART_CMD_LENGTH_Buf(UART_RX_BUF));
                g_bUart0Detected = TRUE; // command  buffer recieve ok
                g_UartCommand.u8CmdLen = UART_CMD_LENGTH_Buf(UART_RX_BUF);
            }

            g_UartCommand.Index = 0; // reset index of command buffer
            g_Uart0CheckTick = 0;
        }
    }
#if 1//defined(MIPS_CHAKRA) || defined(__AEONR2__)
    MsOS_EnableInterrupt(E_INT_IRQ_UART0);
#endif
}
*/
