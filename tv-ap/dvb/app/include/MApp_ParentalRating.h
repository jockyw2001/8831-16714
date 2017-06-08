#ifndef _MAPP_PARENTAL_RATING_H_
#define _MAPP_PARENTAL_RATING_H_


#include "Board.h"


void MApp_Set_MonitorParental(BOOLEAN bEnable);
BOOLEAN MApp_Get_MonitorParental(void);

#if(ENABLE_DTV)
BOOLEAN MApp_Get_ParentalBlock_state(void);
void MApp_Set_ParentalBlock_state(BOOLEAN bEnable);
void MApp_ParentalRating_PasswordInputMessageHandle(BOOL ActOnOff);
void MApp_ParentalRating_BlockStatus_Monitor(void);
#endif

#endif

