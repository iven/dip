ADD_DEFINITIONS ("-g -Wall")

SET (SRC_LIST main bmp_info_header bmp_file_header bmp_pixel bmp_pixmap)

ADD_EXECUTABLE (main ${SRC_LIST})
