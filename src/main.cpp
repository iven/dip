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

    ifile.open (DIP_PIXMAPS_DIR "lena.bmp", ios::in | ios::binary);
    pixmap = new BmpPixmap (ifile);
    ifile.close ();
    
    pixmap->output ();
//    pixmap->fill (100, 160, 180);

    BmpPixmap *pixmap_sp = &pixmap->salt_pepper (.005, .01);

    ofile.open (DIP_PIXMAPS_DIR "output.bmp", ios::out | ios::binary);
    pixmap_sp->write (ofile);
    ofile.close ();

    BmpPixmap *pixmap_mf = &pixmap_sp->median_filter (3);

    ofile.open (DIP_PIXMAPS_DIR "output2.bmp", ios::out | ios::binary);
    pixmap_mf->write (ofile);
    ofile.close ();

    delete pixmap;
    delete pixmap_sp;
    delete pixmap_mf;

	return 0;
}		// ----------  end of function main  ---------- 

