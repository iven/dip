/*
 * =====================================================================================
 *
 *       Filename:  bmp_pixmap_noise_salt_pepper.cpp
 *
 *    Description:  Add salt and pepper noise to the pixmap.
 *
 *        Version:  1.0
 *        Created:  2009年04月11日 19时09分39秒
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
 *      Method:  salt_pepper
 * Description:  Add salt and pepper noise to the pixmap.
 *--------------------------------------------------------------------------------------
 */
    void
BmpPixmap::salt_pepper (double salt, double pepper)
{
    double temp;
    /*-----------------------------------------------------------------------------
     *  Salt & Pepper should be between 0 and 1.
     *-----------------------------------------------------------------------------*/
    salt -= int (salt);
    pepper -= int (pepper);
    /*-----------------------------------------------------------------------------
     *  Init the random seed with time.
     *-----------------------------------------------------------------------------*/
    srand (time (NULL));
    /*-----------------------------------------------------------------------------
     *  Salt & Pepper.
     *-----------------------------------------------------------------------------*/
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            temp = double (rand ()) / RAND_MAX;
            if (temp > 1 - salt) {
                pdata [i][j]->set (255, 255, 255);
            } else if (temp < pepper) {
                pdata [i][j]->set (0, 0, 0);
            }
        }
    }
    return ;
}		/* -----  end of method BmpPixmap::salt_pepper  ----- */

