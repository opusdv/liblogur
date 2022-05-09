#cmake_minimum_required(VERSION $ENV{CMAKE_VERSION})
cmake_minimum_required(VERSION 3.22)
#project(logur VERSION $ENV{VERSION} DESCRIPTION "lib for logging" LANGUAGES C)
project(logur VERSION 0.0.1 DESCRIPTION "lib for logging" LANGUAGES C)
include(GNUInstallDirs)

add_library(logur SHARED 
	../src/logur.c
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -fsanitize=leak -fsanitize=undefined -g")

set_target_properties(
	logur PROPERTIES 
	VERSION ${PROJECT_VERSION} 
	SOVERSION 1 
	PUBLIC_HEADER ../api/logur.h
	LIBRARY_OUTPUT_DIRECTORY "../lib"
)

target_include_directories(logur PRIVATE ../include)
target_compile_options(logur PRIVATE -Wall -Wextra -pedantic -Werror)

install(TARGETS logur
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# Example
add_executable(main	
		../examples/main.c
)
set_target_properties(                                                                                        
  main PROPERTIES                                                                                       
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}" 
)
target_include_directories(main PRIVATE ../include)
target_link_libraries(main PRIVATE logur)
target_compile_options(main PRIVATE -Wall -Wextra -pedantic -Werror)

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
target_link_libraries(logur_test PRIVATE cmocka-static)
target_link_libraries(logur_test PRIVATE logur)
target_compile_options(logur_test PRIVATE -Wall -Wextra -pedantic -Werror)
enable_testing()
add_test(NAME logur_test COMMAND logur_test)
set(ENV{CTEST_OUTPUT_ON_FAILURE} 1)

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
