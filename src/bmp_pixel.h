
#ifndef  bmp_pixel_INC
#define  bmp_pixel_INC

#include	<fstream>
#include	"config.h"

using namespace std;
/*
 * =====================================================================================
 *        Class:  BmpPixel
 *  Description:  Pixel class of a bmp file.
 * =====================================================================================
 */
class BmpPixel
{
    public:

        /* ====================  LIFECYCLE     ======================================= */
        BmpPixel (Byte b,Byte g,Byte r);                             /* constructor      */
        BmpPixel (ifstream &file);                             /* constructor      */
        BmpPixel (const BmpPixel &other);   /* copy constructor */
        ~BmpPixel (void);                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        void output (void);
        void write (ofstream &file);
        Byte get_blue (void);
        Byte get_green (void);
        Byte get_red (void);
        void set_blue (Byte value);
        void set_green (Byte value);
        void set_red (Byte value);
        void set (Byte b, Byte g, Byte r);

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */
        const BmpPixel& operator = (const BmpPixel &other); /* assignment operator */

    protected:

    private:
        /* ====================  DATA MEMBERS  ======================================= */
        Byte blue, green, red;

}; /* -----  end of class BmpPixel  ----- */

#endif   /* ----- #ifndef bmp_pixel_INC  ----- */
