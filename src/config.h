
#ifndef  config_INC
#define  config_INC

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

#define DIP_PIXMAPS_DIR "/home/iven/Workspace/DIP/pixmaps/"

#endif   /* ----- #ifndef config_INC  ----- */
