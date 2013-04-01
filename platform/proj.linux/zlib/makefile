# Normal Information 
CC=gcc
FLAGS= -g -Wall 
FILE_EXT=c

#Project infor 
PROJECT_PATH=../../../build/linux
PROJECT=zlib

# User Config Information 
LIB_DIR=$(PROJECT_PATH)/prebuild/debug
OBJ_DIR=$(PROJECT_PATH)/obj
SRC_DIR=./
INCLUDE_DIR= -I./  -I../../thirdparty/linux/zlib



#Source File 
SRC=  adler32.c \
	  compress.c \
	  crc32.c \
	  deflate.c \
	  gzclose.c \
	  gzlib.c \
	  gzread.c \
	  gzwrite.c \
	  infback.c \
	  inffast.c \
	  inflate.c \
	  inftrees.c \
	  trees.c \
	  uncompr.c \
	  zutil.c  \


#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.$(FILE_EXT)=%.o) 
OBJ_NAME_WITH_PATH=$(addprefix $(OBJ_DIR)/,$(OBJ_NAME))

ALL_OBJ_DIR=$(sort $(dir $(OBJ_NAME_WITH_PATH)))



main:$(LIB_DIR)/lib$(PROJECT).a

$(LIB_DIR)/lib$(PROJECT).a: $(ALL_OBJ_DIR) $(OBJ_NAME_WITH_PATH) 
	echo $(ALL_OBJ_DIR)
	ar cr $@ $(OBJ_NAME_WITH_PATH)

$(ALL_OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(FILE_EXT)
	$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE_DIR) 


clean:
	rm -rf $(OBJ_DIR)/*





