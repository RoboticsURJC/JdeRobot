SET ( LIBFREENECT_PATH $ENV{LIBFREENECT_ROOT})
IF (DEFINED LIBFREENECT_PATH)
    SET ( LIBFREENECT_PATH $ENV{LIBFREENECT_ROOT})
    message("-- libfreenect found")
ELSE()
    message("-- ${BoldYellow}libfreenect not found${ColourReset}")
ENDIF()
