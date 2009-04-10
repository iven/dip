
#ifndef  bmp_file_header_INC
#define  bmp_file_header_INC

#include	<fstream>
#include	"config.h"

using namespace std;

/*
 * =====================================================================================
 *        Class:  BmpFileHeader
 *  Description:  Bmp file header class.
 * =====================================================================================
 */
class BmpFileHeader
{
    public:

        /* ====================  LIFECYCLE     ======================================= */
        BmpFileHeader (ifstream &file);                             /* constructor      */
        BmpFileHeader (const BmpFileHeader &other);   /* copy constructor */
        ~BmpFileHeader (void);                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */
        void output (void);
        void write (ofstream &file);

        /* ====================  MUTATORS      ======================================= */

        /* ====================  OPERATORS     ======================================= */
        const BmpFileHeader& operator = (const BmpFileHeader &other); /* assignment operator */

    protected:

    private:
        /* ====================  DATA MEMBERS  ======================================= */
        Word bf_type;
        Dword bf_size;
        Word bf_reserved1;
        Word bf_reserved2;
        Dword bf_off_bits;

}; /* -----  end of class BmpFileHeader  ----- */

#endif   /* ----- #ifndef bmp_file_header_INC  ----- */
