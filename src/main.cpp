#include	<iostream>  
#include	"bmp_info_header.h"
#include	"bmp_file_header.h"

using namespace std;

// ===  FUNCTION  ======================================================================
//         Name:  main
//  Description:  main function
// =====================================================================================
	int
main ( int argc, char *argv[] )
{
    ifstream ifile (DIP_PIXMAPS_DIR "original.bmp", ios::in | ios::binary);
    BmpFileHeader f_header (ifile);
    BmpInfoHeader i_header (ifile);
    ifile.close ();
    f_header.output ();
    i_header.output ();

	return 0;
}		// ----------  end of function main  ---------- 

