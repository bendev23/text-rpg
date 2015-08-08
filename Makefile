CXX=c++
CXX_FLAGS=-pedantic -Wall -std=c++11 -g -O2
CXX_FLAGS_AFTER=

SRC_DIR=src
BIN_DIR=bin
CPP_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(addprefix $(SRC_DIR)/,$(notdir $(CPP_FILES:.cc=.o)))

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
BIN=$(BIN_DIR)/rpg
CXX_FLAGS_AFTER=-ldl
else
BIN=$(BIN_DIR)/rpg.exe
endif

all: $(BIN)

$(BIN): $(OBJ_FILES)
	$(CXX) $(CXX_FLAGS) -o $@ $^ $(CXX_FLAGS_AFTER)

%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(CXX_FLAGS_AFTER)

run:
	./bin/rpg
