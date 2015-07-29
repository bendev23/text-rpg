CXX=c++
CXX_FLAGS=-pedantic -Wall -std=c++11 -g -O2

SRC_DIR=src
BIN_DIR=bin
CPP_FILES := $(wildcard $(SRC_DIR)/*.cc)
OBJ_FILES := $(addprefix $(SRC_DIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
BIN=$(BIN_DIR)/rpg
else
BIN=$(BIN_DIR)/rpg.exe
endif

all: $(BIN)

$(BIN): $(OBJ_FILES)
	g++ $(CXX_FLAGS) -o $@ $^

obj/%.o: src/%.cc
	g++ $(CXX_FLAGS) -c -o $@ $<

run:
	./bin/rpg
