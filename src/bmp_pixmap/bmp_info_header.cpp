/*
 * =====================================================================================
 *
 *       Filename:  bmp_info_header.cpp
 *
 *    Description:  BmpInfoHeader class implementation.
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
#include	"bmp_info_header.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  BmpInfoHeader
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BmpInfoHeader::BmpInfoHeader (ifstream &file) 
{
    file.read ((char *) &bi_size, sizeof (Dword));
    file.read ((char *) &bi_width, sizeof (Long));
    file.read ((char *) &bi_height, sizeof (Long));
    file.read ((char *) &bi_planes, sizeof (Word));
    file.read ((char *) &bi_bit_count, sizeof (Word));
    file.read ((char *) &bi_compression, sizeof (Dword));
    file.read ((char *) &bi_size_image, sizeof (Dword));
    file.read ((char *) &bi_x_pels_per_meter, sizeof (Long));
    file.read ((char *) &bi_y_pels_per_meter, sizeof (Long));
    file.read ((char *) &bi_clr_used, sizeof (Dword));
    file.read ((char *) &bi_clr_important, sizeof (Dword));
}  /* -----  end of method BmpInfoHeader::BmpInfoHeader  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  BmpInfoHeader
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
BmpInfoHeader::BmpInfoHeader (const BmpInfoHeader &other)
{
    bi_size = other.bi_size;
    bi_width = other.bi_width;
    bi_height = other.bi_height;
    bi_planes = other.bi_planes;
    bi_bit_count = other.bi_bit_count;
    bi_compression = other.bi_compression;
    bi_size_image = other.bi_size_image;
    bi_x_pels_per_meter = other.bi_x_pels_per_meter;
    bi_y_pels_per_meter = other.bi_y_pels_per_meter;
    bi_clr_used = other.bi_clr_used;
    bi_clr_important = other.bi_clr_important;
}  /* -----  end of method BmpInfoHeader::BmpInfoHeader  (copy constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  ~BmpInfoHeader
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
BmpInfoHeader::~BmpInfoHeader (void)
{
}  /* -----  end of method BmpInfoHeader::~BmpInfoHeader  (destructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    const BmpInfoHeader&
BmpInfoHeader::operator = (const BmpInfoHeader &other)
{
    if ( this != &other ) {
        bi_size = other.bi_size;
        bi_width = other.bi_width;
        bi_height = other.bi_height;
        bi_planes = other.bi_planes;
        bi_bit_count = other.bi_bit_count;
        bi_compression = other.bi_compression;
        bi_size_image = other.bi_size_image;
        bi_x_pels_per_meter = other.bi_x_pels_per_meter;
        bi_y_pels_per_meter = other.bi_y_pels_per_meter;
        bi_clr_used = other.bi_clr_used;
        bi_clr_important = other.bi_clr_important;
    }
    return *this;
}  /* -----  end of method BmpInfoHeader::operator =  (assignment operator)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  output
 * Description:  Output the data members.
 *--------------------------------------------------------------------------------------
 */
    void
BmpInfoHeader::output (void) {
    cout	<< "bi_size: " << bi_size << endl;
    cout	<< "bi_width: " << bi_width << endl;
    cout	<< "bi_height: " << bi_height << endl;
    cout	<< "bi_planes: " << bi_planes << endl;
    cout	<< "bi_bit_count: " << bi_bit_count << endl;
    cout	<< "bi_compression: " << bi_compression << endl;
    cout	<< "bi_size_image: " << bi_size_image << endl;
    cout	<< "bi_x_pels_per_meter: " << bi_x_pels_per_meter << endl;
    cout	<< "bi_y_pels_per_meter: " << bi_y_pels_per_meter << endl;
    cout	<< "bi_clr_used: " << bi_clr_used << endl;
    cout	<< "bi_clr_important: " << bi_clr_important << endl;
    return ;
}		/* -----  end of method BmpInfoHeader::output  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  write
 * Description:  Write data members to file.
 *--------------------------------------------------------------------------------------
 */
    void
BmpInfoHeader::write (ofstream &file)
{
    file.write ((char *) &bi_size, sizeof (Dword));
    file.write ((char *) &bi_width, sizeof (Long));
    file.write ((char *) &bi_height, sizeof (Long));
    file.write ((char *) &bi_planes, sizeof (Word));
    file.write ((char *) &bi_bit_count, sizeof (Word));
    file.write ((char *) &bi_compression, sizeof (Dword));
    file.write ((char *) &bi_size_image, sizeof (Dword));
    file.write ((char *) &bi_x_pels_per_meter, sizeof (Long));
    file.write ((char *) &bi_y_pels_per_meter, sizeof (Long));
    file.write ((char *) &bi_clr_used, sizeof (Dword));
    file.write ((char *) &bi_clr_important, sizeof (Dword));
    return ;
}		/* -----  end of method BmpInfoHeader::write  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  get_bi_width
 *--------------------------------------------------------------------------------------
 */
    Long
BmpInfoHeader::get_bi_width (void)
{
    return bi_width;
}		/* -----  end of method BmpInfoHeader::get_bi_width  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  set_bi_width
 *--------------------------------------------------------------------------------------
 */
    void
BmpInfoHeader::set_bi_width (Long value)
{
    bi_width	= value;
    return ;
}		/* -----  end of method BmpInfoHeader::set_bi_width  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  get_bi_height
 *--------------------------------------------------------------------------------------
 */
    Long
BmpInfoHeader::get_bi_height (void)
{
    return bi_height;
}		/* -----  end of method BmpInfoHeader::get_bi_height  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpInfoHeader
 *      Method:  set_bi_height
 *--------------------------------------------------------------------------------------
 */
    void
BmpInfoHeader::set_bi_height (Long value)
{
    bi_height	= value;
    return ;
}		/* -----  end of method BmpInfoHeader::set_bi_height  ----- */

