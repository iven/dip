
#ifndef  bmp_config_INC
#define  bmp_config_INC

#ifdef  BUILD_FOR_WIN
    typedef unsigned char Byte;
    typedef unsigned int Word;
    typedef unsigned long Dword;
    typedef long Long;
#else      /* -----  not BUILD_FOR_WIN  ----- */
    typedef unsigned char Byte;
    typedef unsigned short Word;
    typedef unsigned int Dword;
    typedef int Long;
#endif     /* -----  not BUILD_FOR_WIN  ----- */

#endif   /* ----- #ifndef bmp_config_INC  ----- */
