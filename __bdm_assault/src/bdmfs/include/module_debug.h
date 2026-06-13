#ifndef _MODULE_DEBUG_H
#define _MODULE_DEBUG_H


#define M_PRINTF(format, args...) printf("USBHDFSD: " format, ##args)

#ifdef DEBUG
#define M_DEBUG M_PRINTF
#else
#define M_DEBUG(format, args...)
#endif

#endif
