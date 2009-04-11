/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Main function.
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
#include	"config.h"
#include	"bmp_pixmap/bmp_pixmap.h"

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main (int argc, char *argv[])
{
    ifstream ifile;
    ofstream ofile;
    BmpPixmap *pixmap;
    BmpPixel pixel (200, 160, 180);

    ifile.open (DIP_PIXMAPS_DIR "original.bmp", ios::in | ios::binary);
    pixmap = new BmpPixmap (ifile);
    ifile.close ();
    
    pixmap->output ();
    pixmap->fill (pixel);

    ofile.open (DIP_PIXMAPS_DIR "output.bmp", ios::out | ios::binary);
    pixmap->write (ofile);
    ofile.close ();

    delete pixmap;

	return 0;
}		// ----------  end of function main  ---------- 

