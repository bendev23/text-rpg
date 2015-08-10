CXX=c++
CXX_FLAGS=-pedantic -Wall -std=c++11 -g -O2
CXX_FLAGS_AFTER=

SRC_DIR=src
BIN_DIR=bin
CPP_FILES := $(wildcard *.cc)
OBJ_FILES_PROJECT := $(filter-out ../main.o,$(wildcard ../*.o))
OBJ_FILES := $(addprefix ./,$(notdir $(CPP_FILES:.cc=.o)))

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
BIN=$(BIN_DIR)/rpg
CXX_FLAGS_AFTER=-ldl
else
BIN=$(BIN_DIR)/rpg.exe
endif

all: $(OBJ_FILES)
	echo "done"

clean:
	rm *.o

%.o: %.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $< $(CXX_FLAGS_AFTER) && $(CXX) $(CXX_FLAGS) $@ -o ../../bin/$(basename $@) $(OBJ_FILES_PROJECT) $(CXX_FLAGS_AFTER)

run:
	./bin/rpg