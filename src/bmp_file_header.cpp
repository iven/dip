
#include	<iostream>
#include	"bmp_file_header.h"

using namespace std;

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  BmpFileHeader
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BmpFileHeader::BmpFileHeader (ifstream &file)
{
    file.read ((char *) &bf_type, sizeof (Word));
    file.read ((char *) &bf_size, sizeof (Dword));
    file.read ((char *) &bf_reserved1, sizeof (Word));
    file.read ((char *) &bf_reserved2, sizeof (Word));
    file.read ((char *) &bf_off_bits, sizeof (Dword));
}  /* -----  end of method BmpFileHeader::BmpFileHeader  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  BmpFileHeader
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
BmpFileHeader::BmpFileHeader (const BmpFileHeader &other)
{
    bf_type = other.bf_type;
    bf_size = other.bf_size;
    bf_reserved1 = other.bf_reserved1;
    bf_reserved2 = other.bf_reserved2;
    bf_off_bits = other.bf_off_bits;
}  /* -----  end of method BmpFileHeader::BmpFileHeader  (copy constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  ~BmpFileHeader
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
BmpFileHeader::~BmpFileHeader (void)
{
}  /* -----  end of method BmpFileHeader::~BmpFileHeader  (destructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    const BmpFileHeader&
BmpFileHeader::operator = (const BmpFileHeader &other)
{
    if ( this != &other ) {
        bf_type = other.bf_type;
        bf_size = other.bf_size;
        bf_reserved1 = other.bf_reserved1;
        bf_reserved2 = other.bf_reserved2;
        bf_off_bits = other.bf_off_bits;
    }
    return *this;
}  /* -----  end of method BmpFileHeader::operator =  (assignment operator)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  output
 * Description:  Output the data members.
 *--------------------------------------------------------------------------------------
 */
    void
BmpFileHeader::output (void) {
    cout	<< "bf_type: " << bf_type << endl;
    cout	<< "bf_size: " << bf_size << endl;
    cout	<< "bf_reserved1: " << bf_reserved1 << endl;
    cout	<< "bf_reserved2: " << bf_reserved2 << endl;
    cout	<< "bf_off_bits: " << bf_off_bits << endl;
    return ;
}		/* -----  end of method BmpFileHeader::output  ----- */

