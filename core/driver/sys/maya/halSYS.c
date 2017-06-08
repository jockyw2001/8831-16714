

#include "hwreg.h"

void HAL_SYS_WholeChipReset(void)
{
   WRITE_BYTE( 0xe5c, 0x79 );
}
