#include	<iostream>  
#include	"bmp_pixmap.h"

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

    ifile.open (DIP_PIXMAPS_DIR "original.bmp", ios::in | ios::binary);
    pixmap = new BmpPixmap (ifile);
    ifile.close ();
    
    pixmap->output ();

    ofile.open (DIP_PIXMAPS_DIR "output.bmp", ios::out | ios::binary);
    pixmap->write (ofile);
    ofile.close ();

    delete pixmap;

	return 0;
}		// ----------  end of function main  ---------- 

