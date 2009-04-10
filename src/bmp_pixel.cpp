/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixel.cpp
 *
 *    Description:  BmpPixel class implementation.
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
#include	"bmp_pixel.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  BmpPixel
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BmpPixel::BmpPixel (Byte b, Byte g, Byte r) : blue (b), green (g), red (r)
{
}  /* -----  end of method BmpPixel::BmpPixel  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  BmpPixel
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BmpPixel::BmpPixel (ifstream &file)
{
    file.read ((char *) &blue, sizeof (Byte));
    file.read ((char *) &green, sizeof (Byte));
    file.read ((char *) &red, sizeof (Byte));
}  /* -----  end of method BmpPixel::BmpPixel  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  BmpPixel
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
BmpPixel::BmpPixel (const BmpPixel &other)
{
    blue = other.blue;
    green = other.green;
    red = other.red;
}  /* -----  end of method BmpPixel::BmpPixel  (copy constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  ~BmpPixel
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
BmpPixel::~BmpPixel (void)
{
}  /* -----  end of method BmpPixel::~BmpPixel  (destructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    const BmpPixel&
BmpPixel::operator = (const BmpPixel &other)
{
    if ( this != &other ) {
        blue = other.blue;
        green = other.green;
        red = other.red;
    }
    return *this;
}  /* -----  end of method BmpPixel::operator =  (assignment operator)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  output
 * Description:  Output the data members.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::output (void)
{
    cout	<< "blue: " << blue << endl;
    cout	<< "green: " << green << endl;
    cout	<< "red: " << red << endl;
    return ;
}		/* -----  end of method BmpPixel::output  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  write
 * Description:  Write the data members to file.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::write (ofstream &file)
{
    file.write ((char *) &blue, sizeof (Byte));
    file.write ((char *) &green, sizeof (Byte));
    file.write ((char *) &red, sizeof (Byte));
    return ;
}		/* -----  end of method BmpPixel::write  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  get_blue
 *--------------------------------------------------------------------------------------
 */
    Byte
BmpPixel::get_blue (void)
{
    return blue;
}		/* -----  end of method BmpPixel::get_blue  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  set_blue
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::set_blue (Byte value)
{
    blue	= value;
    return ;
}		/* -----  end of method BmpPixel::set_blue  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  get_green
 *--------------------------------------------------------------------------------------
 */
    Byte
BmpPixel::get_green (void)
{
    return green;
}		/* -----  end of method BmpPixel::get_green  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  set_green
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::set_green (Byte value)
{
    green	= value;
    return ;
}		/* -----  end of method BmpPixel::set_green  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  get_red
 *--------------------------------------------------------------------------------------
 */
    Byte
BmpPixel::get_red (void)
{
    return red;
}		/* -----  end of method BmpPixel::get_red  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  set_red
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::set_red (Byte value)
{
    red	= value;
    return ;
}		/* -----  end of method BmpPixel::set_red  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixel
 *      Method:  set
 * Description:  Set data members.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixel::set (Byte b, Byte g, Byte r)
{
    blue = b;
    green = g;
    red = r;
    return ;
}		/* -----  end of method BmpPixel::set  ----- */

