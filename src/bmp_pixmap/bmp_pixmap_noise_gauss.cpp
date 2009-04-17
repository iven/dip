/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap_noise_gauss.cpp
 *
 *    Description:  Add gauss noise to the pixmap.
 *
 *        Version:  1.0
 *        Created:  2009年04月17日 23时38分04秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Xu Lijian (ivenvd), ivenvd@gmail.com
 *        Company:  CUGB, China
 *
 * =====================================================================================
 */

#include	<cstdlib>
#include	<ctime>
#include	"bmp_pixmap.h"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  BmpPixmap
 *      Method:  gauss
 * Description:  Add gauss noise to the pixmap.
 *--------------------------------------------------------------------------------------
 */
    BmpPixmap &
BmpPixmap::gauss (int level)
{
    assert (level >= 0);

    BmpPixmap *temp = new BmpPixmap (*this);
    int k, rand_temp, pixel [3];
    /*-----------------------------------------------------------------------------
     *  Init the random seed with time.
     *-----------------------------------------------------------------------------*/
    srand (time (NULL));
    /*-----------------------------------------------------------------------------
     *  Salt & Pepper.
     *-----------------------------------------------------------------------------*/
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            rand_temp = rand () % level - level / 2;
            pixel [0] = temp->pdata [i][j]->get_blue () + rand_temp;
            pixel [1] = temp->pdata [i][j]->get_green () + rand_temp;
            pixel [2] = temp->pdata [i][j]->get_red () + rand_temp;
            for (k = 0; k < 3; k++) {
                if (pixel [k] < 0) {
                    pixel [k] = 0;
                } else if (pixel [k] > 255) {
                    pixel [k] = 255;
                }
            }
            temp->pdata [i][j]->set (pixel [0], pixel [1], pixel [2]);
        }
    }
    return *temp;
}		/* -----  end of method BmpPixmap::gauss  ----- */

