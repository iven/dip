/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap_fill.cpp
 *
 *    Description:  Fill the whole bmp with one color.
 *
 *        Version:  1.0
 *        Created:  2009年04月11日 16时45分26秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	"bmp_pixmap.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  fill
 * Description:  Fill the whole bmp with one color.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::fill (const BmpPixel &pixel)
{
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            *pdata [i][j] = pixel;
        }
    }
    return ;
}		/* -----  end of method BmpPixmap::fill  ----- */

