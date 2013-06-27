# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -Werror -DLINUX
FLAGS_RELEASE= -O3 -DLINUX

#Project infor 
PROJECT_PATH= ../../../library/linux/
PROJECT=audio

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \
			-I../../../lib3rdparty/fmod/include \


#Source File 
SRC=  FsAudioEngine.cc  \
	  FsAudioPlayer.cc \


include ../../../MK_BUILD_STATIC_LIB 

