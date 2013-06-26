# Normal Information 
CC=gcc
FLAGS= -g -Wall  -Werror -DLINUX
FILE_EXT=cc

#Project infor 
PROJECT_PATH=../../../build/linux/
PROJECT=audio

# User Config Information 
LIB_DIR=$(PROJECT_PATH)prebuild/debug
OBJ_DIR=$(PROJECT_PATH)obj/$(PROJECT)
SRC_DIR=../src
INCLUDE_DIR=-I../src \
		   	-I./ \
			-I../../../libfaeris/src \
			-I../../../platform/thirdparty/linux


#Source File 
SRC=  FsAudioEngine.cc  \
	  FsAudioPlayer.cc \

#full src name 
SRC_NAME_WITH_PATH=$(addprefix $(SRC_DIR)/,$(SRC))

#obj name 
OBJ_NAME=$(SRC:%.cc=%.o) 
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























