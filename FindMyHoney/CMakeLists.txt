cmake_minimum_required (VERSION 2.8 FATAL_ERROR)

set (GCC_COVERAGE_COMPILE_FLAGS "-std=c++11")

set (SOURCES
	stdafx.h
	stdafx.cpp
	FindMyHoney.cpp
	Game.cpp
	Game.h
	GameEntity.cpp
	GameEntity.h
	GameObject.cpp
	GameObject.h
	GameObjectManager.cpp
	GameObjectManager.h
	Honey.cpp
	Honey.h
	Thug.cpp
	Thug.h
	MainMenu.cpp
	MainMenu.h
	ScoreScreen.cpp
	ScoreScreen.h
	SplashScreen.cpp
	SplashScreen.h
	targetver.h
	)

set (SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/SFML-2.3.2/")

set (LIBRARIES
	${SFML_DIR}lib/libjpeg.so.8
	${SFML_DIR}lib/libsfml-system.so
	${SFML_DIR}lib/libsfml-graphics.so
	${SFML_DIR}lib/libsfml-audio.so
	${SFML_DIR}lib/libsfml-network.so
	${SFML_DIR}lib/libsfml-window.so
	)

set (EXECUTABLE_NAME "FindMyHoney")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

project (${EXECUTABLE_NAME})

include_directories ("${SFML_DIR}/include/")
link_directories ("${SFML_DIR}/lib/")

add_executable (${EXECUTABLE_NAME} ${SOURCES})
target_link_libraries (${EXECUTABLE_NAME} ${LIBRARIES})
