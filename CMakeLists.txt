cmake_minimum_required (VERSION 2.8.9)
project ("Penetrate")

set (CMAKE_CXX_STANDARD 11)
set (PRJ ${PROJECT_SOURCE_DIR})
set (FILELIST ${PRJ}/sources.src)

message (STATUS "PRJ : ${PRJ}")
message (STATUS "FILELIST : ${FILELIST}")

include_directories (${PRJ}/src)
file (READ ${FILELIST} SRC)

string (REGEX REPLACE "#.*$" "" SRC ${SRC})
string (REGEX REPLACE "\n" ";" SRC ${SRC})

foreach (f ${SRC})
	set_source_files_properties (${f} PROPERTIES LANGUAGE CXX)
endforeach(f)

add_executable (${PROJECT_NAME} ${SRC})

include (FindPkgConfig)
pkg_search_module (SDL2 REQUIRED sdl2)
pkg_search_module (SDL2IMAGE REQUIRED SDL2_image)
include_directories (${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIRS})

target_link_libraries ( ${PROJECT_NAME}
	${SDL2_LIBRARIES}
	${SDL2IMAGE_LIBRARIES}
	)
