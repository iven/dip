/*
 * =====================================================================================
 *
 *       Filename:  bmp_file_header.cpp
 *
 *    Description:  BmpFileHeader class implementation.
 *
 *        Version:  1.0
 *        Created:  2009年04月11日 02时27分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<iostream>
#include	"bmp_file_header.h"

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

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpFileHeader
 *      Method:  write
 * Description:  Write data members to file.
 *--------------------------------------------------------------------------------------
 */
    void
BmpFileHeader::write (ofstream &file)
{
    file.write ((char *) &bf_type, sizeof (Word));
    file.write ((char *) &bf_size, sizeof (Dword));
    file.write ((char *) &bf_reserved1, sizeof (Word));
    file.write ((char *) &bf_reserved2, sizeof (Word));
    file.write ((char *) &bf_off_bits, sizeof (Dword));
    return ;
}		/* -----  end of method BmpFileHeader::write  ----- */

