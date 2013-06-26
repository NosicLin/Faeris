# Normal Information 
CC=gcc
FLAGS= -g -Wall -Werror
FILE_EXT=c

#Project infor 
PROJECT_PATH= ../../../build/linux/
PROJECT=lua

# User Config Information 
LIB_DIR=$(PROJECT_PATH)prebuild/debug
OBJ_DIR=$(PROJECT_PATH)obj/$(PROJECT)
SRC_DIR=./
INCLUDE_DIR= -I./

#Source File 
SRC= lapi.c \
	 lauxlib.c \
	 lbaselib.c \
	 lcode.c \
	 ldblib.c \
	 ldebug.c \
	 ldo.c \
	 ldump.c \
	 lfunc.c \
	 lgc.c \
	 linit.c \
	 liolib.c \
	 llex.c \
	 lmathlib.c \
	 lmem.c \
	 loadlib.c \
	 lobject.c \
	 lopcodes.c \
	 loslib.c \
	 lparser.c \
	 lstate.c \
	 lstring.c \
	 lstrlib.c \
	 ltable.c \
	 ltablib.c \
	 ltm.c \
	 lundump.c \
	 lvm.c \
	 lzio.c \
	 print.c \


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


