#ifndef _MSAPI_DTV_DB_RAMDISK_H_
#define _MSAPI_DTV_DB_RAMDISK_H_


#include "Board.h"

#if(ENABLE_DTV)

#include <stddef.h>     /* offsetof */

#include "msAPI_DTV_Common.h"
#include "msAPI_DTVSystem.h"
#include "msAPI_MW_GlobalSt.h"

#include "MApp_SaveData.h"


// RamDisk Address - DVBT/DTMB/DVBC
#define BASEADDRESS_PR_DATA                         RM_DTV_CHSET_START_ADDR//START_ADDRESS_OF_DTVDATA_STRUCTURE
#define BASEADDRESS_PR_SERIALNO                     ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bSerialNum)))
#define BASEADDRESS_PR_IDENT                        ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wID)))
//#define BASEADDRESS_COUNTRY                         ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, eCountry)))
#define BASEADDRESS_PR_IS_LCN_ARRANGED              ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bIsLogicalChannelNumberArranged)))
#if (NTV_FUNCTION_ENABLE)
#define BASEADDRESS_PR_FAVORITE_REGION              ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bFavorite_Region)))
#endif

#define BASEADDRESS_PR_DTVPRTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVChannelTableMap)))
#define BASEADDRESS_PR_DTVPRTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDTVChannelTable)))
#define BASEADDRESS_PR_DTVIDTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVIDtableMap)))
#define BASEADDRESS_PR_DTVIDTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvIDTable)))
#define BASEADDRESS_PR_DTVNETWORK                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvNetwork)))
#define END_ADDRESS_OF_DTVDATA_STRUCTURE            ( BASEADDRESS_PR_DATA + (sizeof(DTV_CHANNEL_DATA_STRUCTURE)) )


// RamDisk Address - DVBC
#if DVB_T_C_DIFF_DB
    #define BASEADDRESS_DTV_DVBC_START               RM_DTV_C_CHSET_START_ADDR //START_ADDRESS_OF_DTVDATA_STRUCTURE
    #define BASEADDRESS_DTV_DVBC_SERIALNO           ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bSerialNum)) )
    #define BASEADDRESS_DTV_DVBC_IDENT              ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, wID)) )
    #define BASEADDRESS_DTV_DVBC_IS_LCN_ARRANGED    ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bIsLogicalChannelNumberArranged)) )
  #if (NTV_FUNCTION_ENABLE)
    #define BASEADDRESS_PR_FAVORITE_REGION_DVBC     (BASEADDRESS_DTV_DVBC_START + offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bFavorite_Region) )
  #endif
    #define BASEADDRESS_PR_DTV_C_PRTABLEMAP         ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bDTV_C_ChannelTableMap)))
    #define BASEADDRESS_PR_DTV_C_PRTABLE            ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDTV_C_ChannelTable)))
    #define BASEADDRESS_PR_DTV_C_IDTABLEMAP         ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bDTV_C_IDtableMap)))
    #define BASEADDRESS_PR_DTV_C_IDTABLE            ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDtv_C_IDTable)))
    #define BASEADDRESS_PR_DTV_C_DTVNETWORK         ( BASEADDRESS_DTV_DVBC_START + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDtv_C_Network)))
    #define END_ADDRESS_OF_DTVDATA_STRUCTURE_DVBC   ( BASEADDRESS_DTV_DVBC_START + (sizeof(DTV_C_CHANNEL_DATA_STRUCTURE)) )
#endif


#if 0 // Old
//---PROGRAM MAP---
#if (!ENABLE_API_DTV_SYSTEM_2015)
#if DVB_T_C_DIFF_DB
    #define BASEADDRESS_PR_DATA                         RM_DTV_CHSET_START_ADDR//START_ADDRESS_OF_DTVDATA_STRUCTURE
    #define BASEADDRESS_PR_SERIALNO                     ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bSerialNum)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bSerialNum)) ))
    #define BASEADDRESS_PR_IDENT                        ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, wID)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wID)) ))
    #define BASEADDRESS_COUNTRY                         ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, eCountry)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, eCountry)) ))
    #define BASEADDRESS_PR_IS_LCN_ARRANGED              ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bIsLogicalChannelNumberArranged))) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bIsLogicalChannelNumberArranged))))
    #if (EEPROM_DB_STORAGE == EEPROM_SAVE_NONE)
    #define BASEADDRESS_PR_CURRENTORDER_TV              ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, wCurOrderOfTV)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wCurOrderOfTV)) ))
    #define BASEADDRESS_PR_CURRENTORDER_RADIO           ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, wCurOrderOfRadio)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wCurOrderOfRadio)) ))
    #define BASEADDRESS_PR_CURRENTORDER_DATA            ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, wCurOrderOfData)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wCurOrderOfData)) ))
    #define BASEADDRESS_PR_CURRENT_SERVICETYPE          ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, eDTVCurrentServiceType)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, eDTVCurrentServiceType)) ))
    #endif
    #if (NTV_FUNCTION_ENABLE)
    #define BASEADDRESS_PR_FAVORITE_REGION              ((IsDVBCInUse()) ? ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bFavorite_Region)) ) : ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bFavorite_Region)) ))
    #endif

    #define BASEADDRESS_PR_DTVPRTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVChannelTableMap)))
    #define BASEADDRESS_PR_DTVPRTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDTVChannelTable)))
    #define BASEADDRESS_PR_DTVIDTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVIDtableMap)))
    #define BASEADDRESS_PR_DTVIDTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvIDTable)))
    #define BASEADDRESS_PR_DTVNETWORK                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvNetwork)))
    #define BASEADDRESS_PR_UNSUPPORT_LANGCODE_COUNT     ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bUnsupportedLangCode_Count)))
    #define BASEADDRESS_PR_NSUPPORT_LANGCODE            ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, abUnsupportedLangCode)))

    #define BASEADDRESS_PR_DTV_C_PRTABLEMAP             ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bDTV_C_ChannelTableMap)))
    #define BASEADDRESS_PR_DTV_C_PRTABLE                ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDTV_C_ChannelTable)))
    #define BASEADDRESS_PR_DTV_C_IDTABLEMAP             ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, bDTV_C_IDtableMap)))
    #define BASEADDRESS_PR_DTV_C_IDTABLE                ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDtv_C_IDTable)))
    #define BASEADDRESS_PR_DTV_C_DTVNETWORK             ( BASEADDRESS_PR_DATA + (offsetof(DTV_C_CHANNEL_DATA_STRUCTURE, astDtv_C_Network)))
    #define END_ADDRESS_OF_DTVDATA_STRUCTURE            ( START_ADDRESS_OF_DTVDATA_STRUCTURE + (sizeof(DTV_CHANNEL_DATA_STRUCTURE)) + (sizeof(DTV_C_CHANNEL_DATA_STRUCTURE)))
#else
    #define BASEADDRESS_PR_DATA                         RM_DTV_CHSET_START_ADDR//START_ADDRESS_OF_DTVDATA_STRUCTURE
    #define BASEADDRESS_PR_SERIALNO                     ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bSerialNum)))
    #define BASEADDRESS_PR_IDENT                        ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, wID)))
    #define BASEADDRESS_COUNTRY                         ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, eCountry)))
    #define BASEADDRESS_PR_IS_LCN_ARRANGED              ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bIsLogicalChannelNumberArranged)))
    #if (NTV_FUNCTION_ENABLE)
    #define BASEADDRESS_PR_FAVORITE_REGION              ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bFavorite_Region)))
    #endif
    #define BASEADDRESS_PR_DTVPRTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVChannelTableMap)))
    #define BASEADDRESS_PR_DTVPRTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDTVChannelTable)))
    #define BASEADDRESS_PR_DTVIDTABLEMAP                ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bDTVIDtableMap)))
    #define BASEADDRESS_PR_DTVIDTABLE                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvIDTable)))
    #define BASEADDRESS_PR_DTVNETWORK                   ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, astDtvNetwork)))
    #define BASEADDRESS_PR_UNSUPPORT_LANGCODE_COUNT     ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, bUnsupportedLangCode_Count)))
    #define BASEADDRESS_PR_NSUPPORT_LANGCODE            ( BASEADDRESS_PR_DATA + (offsetof(DTV_CHANNEL_DATA_STRUCTURE, abUnsupportedLangCode)))
    #define END_ADDRESS_OF_DTVDATA_STRUCTURE            ( START_ADDRESS_OF_DTVDATA_STRUCTURE + (sizeof(DTV_CHANNEL_DATA_STRUCTURE)))
#endif
#endif

#endif



#endif // ENABLE_DTV
#endif // _MSAPI_DTV_DB_RAMDISK_H_

