/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap.h
 *
 *    Description:  BmpPixmap Class.
 *
 *        Version:  1.0
 *        Created:  2009年04月11日 16时49分31秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#ifndef  bmp_pixmap_INC
#define  bmp_pixmap_INC

#include	<fstream>
#include	"bmp_config.h"
#include	"bmp_file_header.h"
#include	"bmp_info_header.h"
#include	"bmp_pixel.h"

using namespace std;

/*
 * =====================================================================================
 *        Class:  BmpPixmap
 *  Description:  Bmp pixmap class.
 * =====================================================================================
 */
class BmpPixmap
{
    public:

        /* ====================  LIFECYCLE     ======================================= */
        BmpPixmap (ifstream &file);                             /* constructor      */
        BmpPixmap (const BmpPixmap &other);   /* copy constructor */
        ~BmpPixmap (void);                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        BmpFileHeader &get_fheader (void);
        BmpInfoHeader &get_iheader (void);
        void output (void);
        void write (ofstream &file);

        /* ====================  MUTATORS      ======================================= */
        void fill (const BmpPixel &pixel);
        void fill (Byte b, Byte g, Byte r);
        void salt_pepper (double salt, double pepper);

        /* ====================  OPERATORS     ======================================= */
        const BmpPixmap& operator = (const BmpPixmap &other); /* assignment operator */

    protected:

    private:
        void create_data (ifstream &file);
        void create_data (BmpPixel ***p);
        void destroy (void);
        /* ====================  DATA MEMBERS  ======================================= */
        BmpFileHeader *fheader;
        BmpInfoHeader *iheader;
        BmpPixel ***pdata;
        Long i, j, width, height;

}; /* -----  end of class BmpPixmap  ----- */

#endif   /* ----- #ifndef bmp_pixmap_INC  ----- */
