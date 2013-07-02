# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -Werror -DLINUX
FLAGS_RELEASE= -O3 -DLINUX

#Project infor 
PROJECT_PATH= ../../../library/linux/
PROJECT=network

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \
			-I../../../lib3rdparty/fmod/include \
			-I../../../lib3rdparty/curl/include \


#Source File 
SRC=  FsHttpEngine.cc \
	  FsHttpReponse.cc \
	  FsHttpRequest.cc \


include ../../../MK_BUILD_STATIC_LIB 

