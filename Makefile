CXX=c++
CXXFLAGS=-pedantic -Wall -std=c++11 -g -O2

SRCDIR=src
DSTDIR=bin
CPP_FILES := $(wildcard $(SRCDIR)/*.cc)
OBJ_FILES := $(addprefix $(SRCDIR)/,$(notdir $(CPP_FILES:.cpp=.o)))

UNAME := $(shell uname)
ifeq ($(UNAME), Linux)
BIN=$(DSTDIR)/rpg
else
BIN=$(DSTDIR)/rpg.exe
endif

all: $(BIN)

$(BIN): $(OBJ_FILES)
	g++ $(CXXFLAGS) -o $@ $^

obj/%.o: src/%.cc
	g++ $(CXXFLAGS) -c -o $@ $<