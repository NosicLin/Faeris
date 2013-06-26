# Normal Information 
CC=gcc
FLAGS= -g -Wall 
FILE_EXT=c

#Project infor 
PROJECT_PATH=../../../build/linux/
PROJECT=libpng
# User Config Information 
LIB_DIR=$(PROJECT_PATH)prebuild/debug
OBJ_DIR=$(PROJECT_PATH)obj/$(PROJECT)
SRC_DIR=./
INCLUDE_DIR= -I./ -I../../thirdparty/linux/zlib

#Source File 
SRC=  png.c \
	  pngerror.c \
	  pngget.c \
	  pngset.c \
	  pngmem.c \
	  pngtrans.c \
	  pngpread.c \
	  pngread.c \
	  pngrio.c \
	  pngrtran.c \
	  pngrutil.c \
	  pngwio.c \
	  pngwrite.c \
	  pngwtran.c \
	  pngwutil.c \

#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.c=%.o) 
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
	rm -rf $(OBJ_NAME_WITH_PATH);\
	rm -rf $(LIB_DIR)/lib$(PROJECT).a	


