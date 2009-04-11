/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap_filter_median.cpp
 *
 *    Description:  Bmp pixmap median filter.
 *
 *        Version:  1.0
 *        Created:  2009年04月12日 00时06分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<iostream>
#include	<cstdlib>
#include	"bmp_pixmap.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  median_filter
 * Description:  Bmp pixmap median filter.
 *--------------------------------------------------------------------------------------
 */
    BmpPixmap &
BmpPixmap::median_filter (int n)
{
    assert (n >= 3 && n % 2);

    int ii, jj, nn;
    Byte model [3][n * n];
    BmpPixmap *temp = new BmpPixmap (*this);
    for (i = n / 2; i < height - n / 2; i++) {
        for (j = n / 2; j < width - n / 2; j++) {
            /*-----------------------------------------------------------------------------
             *  Put n*n pixels around current pixels to the model.
             *-----------------------------------------------------------------------------*/
            for (ii = i - n / 2, nn = 0; ii <= i + n / 2; ii++) {
                for (jj = j - n / 2; jj <= j + n / 2; jj++, nn++) {
                    model [0][nn] = pdata [ii][jj]->get_blue ();
                    model [1][nn] = pdata [ii][jj]->get_green ();
                    model [2][nn] = pdata [ii][jj]->get_red ();
                }
            }
            /*-----------------------------------------------------------------------------
             *  Sort the model.
             *-----------------------------------------------------------------------------*/
            qsort (model [0], nn, sizeof (Byte), cmp_Byte);
            qsort (model [1], nn, sizeof (Byte), cmp_Byte);
            qsort (model [2], nn, sizeof (Byte), cmp_Byte);

            if (pdata [i][j]->get_blue () == model [0][nn - 1] ||
                    pdata [i][j]->get_blue () == model [0][0] ||
                    pdata [i][j]->get_green () == model [1][nn - 1] ||
                    pdata [i][j]->get_green () == model [1][0] ||
                    pdata [i][j]->get_red () == model [2][nn - 1] ||
                    pdata [i][j]->get_red () == model [2][0])
            {
                temp->pdata [i][j]->set (model [0][nn / 2], model [1][nn / 2], model [2][nn / 2]);
            }
        }
    }
    return *temp;
}		/* -----  end of method BmpPixmap::median_filter  ----- */

