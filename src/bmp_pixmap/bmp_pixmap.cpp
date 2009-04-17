/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap.cpp
 *
 *    Description:  BmpPixmap class implementation.
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
#include	"bmp_pixmap.h"
/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  BmpPixmap
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
BmpPixmap::BmpPixmap (ifstream &file)
{
    fheader = new BmpFileHeader (file);
    iheader = new BmpInfoHeader (file);
    create_data (file);
}  /* -----  end of method BmpPixmap::BmpPixmap  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  BmpPixmap
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
BmpPixmap::BmpPixmap (const BmpPixmap &other)
{
    fheader = new BmpFileHeader (* other.fheader);
    iheader = new BmpInfoHeader (* other.iheader);
    create_data (other.pdata);
}  /* -----  end of method BmpPixmap::BmpPixmap  (copy constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  ~BmpPixmap
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
BmpPixmap::~BmpPixmap (void)
{
    destroy ();
}  /* -----  end of method BmpPixmap::~BmpPixmap  (destructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
    const BmpPixmap&
BmpPixmap::operator = (const BmpPixmap &other)
{
    if (this != &other) {
        destroy ();
        fheader = new BmpFileHeader (* other.fheader);
        iheader = new BmpInfoHeader (* other.iheader);
        create_data (other.pdata);
    }
    return *this;
}  /* -----  end of method BmpPixmap::operator =  (assignment operator)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  create_data
 * Description:  Create pixels data from file stream.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::create_data (ifstream &file)
{
    width = iheader->get_bi_width ();
    height = iheader->get_bi_height ();
    width = width > 0 ? width : -width;
    height = height > 0 ? height : -height;
    pdata = new BmpPixel ** [height];
    for (i = 0; i < height; i++) {
        pdata [i] = new BmpPixel * [width];
        for (j = 0; j < width; j++) {
            pdata [i][j] = new BmpPixel (file);
        }
    }
    return ;
}		/* -----  end of method BmpPixmap::create_data  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  create_data
 * Description:  Create pixels data from pdata.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::create_data (BmpPixel ***p)
{
    width = iheader->get_bi_width ();
    height = iheader->get_bi_height ();
    width = width > 0 ? width : -width;
    height = height > 0 ? height : -height;
    pdata = new BmpPixel ** [height];
    for (i = 0; i < height; i++) {
        pdata [i] = new BmpPixel * [width];
        for (j = 0; j < width; j++) {
            pdata [i][j] = new BmpPixel (* p [i][j]);
        }
    }
    return ;
}		/* -----  end of method BmpPixmap::create_data  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  destroy
 * Description:  Distroy the class.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::destroy (void)
{
    width = iheader->get_bi_width ();
    height = iheader->get_bi_height ();
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            delete pdata [i][j];
        }
        delete [] pdata [i];
    }
    delete [] pdata;
    delete iheader;
    delete fheader;
    return ;
}		/* -----  end of method BmpPixmap::destroy  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  cmp_Byte
 * Description:  Comparing method for qsort.
 *--------------------------------------------------------------------------------------
 */
    int
BmpPixmap::cmp_Byte (const void *p1, const void *p2)
{
    return (* (Byte *) p1 - * (Byte *) p2);
}		/* -----  end of method BmpPixmap::cmp_Byte  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  output
 * Description:  Output the data members.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::output (void)
{
    fheader->output ();
    iheader->output ();
    return ;
}		/* -----  end of method BmpPixmap::output  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  write
 * Description:  Write pixmap to file.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::write (ofstream &file)
{
    fheader->write (file);
    iheader->write (file);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pdata [i][j]->write (file);
        }
    }
    return ;
}		/* -----  end of method BmpPixmap::write  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  get_fheader
 *--------------------------------------------------------------------------------------
 */
    BmpFileHeader &
BmpPixmap::get_fheader (void)
{
    return *fheader;
}		/* -----  end of method BmpPixmap::get_fheader  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  get_iheader
 *--------------------------------------------------------------------------------------
 */
    BmpInfoHeader &
BmpPixmap::get_iheader (void)
{
    return *iheader;
}		/* -----  end of method BmpPixmap::get_iheader  ----- */

