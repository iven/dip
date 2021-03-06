/*
 * =====================================================================================
 *
 *       Filename:  bmp_info_header.h
 *
 *    Description:  BmpInfoHeader Class.
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

#ifndef  bmp_info_header_INC
#define  bmp_info_header_INC

#include	<fstream>
#include	"bmp_config.h"

using namespace std;

/*
 * =====================================================================================
 *        Class:  BmpInfoHeader
 *  Description:  Bmp information header class.
 * =====================================================================================
 */
class BmpInfoHeader
{
    public:

        /* ====================  LIFECYCLE     ======================================= */
        BmpInfoHeader (ifstream &file);                             /* constructor      */
        BmpInfoHeader (const BmpInfoHeader &other);   /* copy constructor */
        ~BmpInfoHeader (void);                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        Long get_bi_width (void);
        Long get_bi_height (void);
        void output (void);
        void write (ofstream &file);

        /* ====================  MUTATORS      ======================================= */
        void set_bi_width (Long value);
        void set_bi_height (Long value);

        /* ====================  OPERATORS     ======================================= */
        const BmpInfoHeader& operator = (const BmpInfoHeader &other); /* assignment operator */

    protected:

    private:
        /* ====================  DATA MEMBERS  ======================================= */
        Dword bi_size;
        Long bi_width;
        Long bi_height;
        Word bi_planes;
        Word bi_bit_count;
        Dword bi_compression;
        Dword bi_size_image;
        Long bi_x_pels_per_meter;
        Long bi_y_pels_per_meter;
        Dword bi_clr_used;
        Dword bi_clr_important;

}; /* -----  end of class BmpInfoHeader  ----- */

#endif   /* ----- #ifndef bmp_info_header_INC  ----- */
