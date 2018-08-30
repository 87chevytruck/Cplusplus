cmake_minimum_required(VERSION 3.6)
project(CppTest)

include(ExternalProject)
find_package(Git REQUIRED)

#ExternalProject_Add(
        #catch
        #PREFIX ${CMAKE_CURRENT_SOURCE_DIR}/catch
        #GIT_REPOSITORY https://github.com/philsquared/Catch.git
        #TIMEOUT 10
        #UPDATE_COMMAND ${GIT_EXECUTABLE} pull
        #CONFIGURE_COMMAND ""
        #BUILD_COMMAND ""
        #INSTALL_COMMAND ""
        #LOG_DOWNLOAD ON
#)
#
#ExternalProject_Get_Property(catch source_dir)

set(CATCH_INCLUDE_DIR ${source_dir}/include CACHE INTERNAL "${CMAKE_BINARY_DIR}/catch")
set(CATCH_INC "${CMAKE_CURRENT_SOURCE_DIR}/catch/src/catch/single_include")


set_property(DIRECTORY PROPERTY VS_STARTUP_PROJECT NQueens)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES src/main.cpp ${CATCH_INC} src/GraderCode.cpp src/StudentCode.cpp src/tests.cpp include/GraderCode.hpp include/StudentCode.hpp)
add_executable(NQueens ${SOURCE_FILES})
target_include_directories(NQueens PUBLIC "include")

#set(FakeSolitaire_SOURCE_FILES src/card.cpp src/frenchdeck.cpp src/grader.cpp src/pile.cpp src/StudentCodeFS.cpp include/card.h include/deck.h include/frenchdeck.h include/grader.h include/pile.h include/ranksuitenum.h)
#add_executable(FakeSolitaire ${FakeSolitaire_SOURCE_FILES})
#target_include_directories(FakeSolitaire PUBLIC "include")