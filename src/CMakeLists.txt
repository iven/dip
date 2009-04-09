ADD_DEFINITIONS ("-g -Wall")

SET (SRC_LIST main bmp_info_header bmp_file_header)

ADD_EXECUTABLE (main ${SRC_LIST})
