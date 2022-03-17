cmake_minimum_required(VERSION $ENV{CMAKE_VERSION})
#cmake_minimum_required(VERSION 3.22)
project(logur VERSION $ENV{VERSION} DESCRIPTION "lib for logging" LANGUAGES C)
#project(logur VERSION 0.0.1 DESCRIPTION "lib for logging" LANGUAGES C)
include(GNUInstallDirs)

add_library(logur SHARED 
	../src/logur.c
)


set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set_target_properties(
	logur PROPERTIES 
	VERSION ${PROJECT_VERSION} 
	SOVERSION 1 
	PUBLIC_HEADER ../api/logur.h
	LIBRARY_OUTPUT_DIRECTORY "../lib"
)

target_include_directories(logur PRIVATE ../include)
target_compile_options(logur PRIVATE -Wall 
	-Wextra
	-pedantic 
	-fsanitize=undefined
)

install(TARGETS logur
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


# CTest
add_executable(logur_test                                                                                     
    ../tests/logur_test.c                                                                                       
) 
include(FetchCMocka.cmake)
set_target_properties(
	logur_test PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..tests"
)
target_include_directories(logur_test PRIVATE ../include)                                                     
target_compile_options(logur_test PRIVATE  -Wall                                                              
    -Wextra                                                                                                   
    -pedantic                                                                                                 
    -fsanitize=undefined                                                                                      
) 
target_link_libraries(logur_test PRIVATE cmocka-static)
target_link_libraries(logur_test PRIVATE logur)
enable_testing()
add_test(NAME logur_test COMMAND logur_test)


# Doxygen
option(BUILD_DOC "Build documentation" ON)
find_package(Doxygen)
if (DOXYGEN_FOUND)
	set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/../docs/Doxyfile.in)
	set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

	configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")

	add_custom_target( doc_doxygen ALL
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM )
else(DOXYGEN_FOUND)
	message("Doxygen need to be installed to generate the doxygen documentation")
endif (DOXYGEN_FOUND)

# CPack
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME "liblogur")
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Donatas Vaytukaytis")
set(CPACK_PACKAGE_VENDOR "opusdv.online")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}-$ENV{CI_PIPELINE_ID}")
include(CPack)
