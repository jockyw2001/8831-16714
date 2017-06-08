
#ifndef _MMAP_CHECK_COMMON_H_
#define _MMAP_CHECK_COMMON_H_


#if( defined(VDEC_BITSTREAM_SD_ADR) )
    #if( VDEC_BITSTREAM_ADR != VDEC_BITSTREAM_SD_ADR )
        #error "VDEC_BITSTREAM_ADR != VDEC_BITSTREAM_SD_ADR"
    #endif
#endif


#endif // _MMAP_CHECK_COMMON_H_

