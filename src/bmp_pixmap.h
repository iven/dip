
#ifndef  bmp_pixmap_INC
#define  bmp_pixmap_INC

#include	<fstream>
#include	"config.h"
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
        void output (void);
        void write (ofstream &file);
        BmpFileHeader &get_fheader (void);
        BmpInfoHeader &get_iheader (void);

        /* ====================  MUTATORS      ======================================= */

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
