CC		:= clang++
CFLAGS	:= -std=c++17 -ggdb -Wno-invalid-source-encoding
CFLAGS	+= -Wall -Wextra

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lglfw3dll
LIBRARIES	+= -lglad

EXECUTABLE	:= main.exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
LIBDIRS		:= $(LIB)

CINCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))
CLIBS		:= $(patsubst %,-L%, $(LIBDIRS:%/=%))

CPPSOURCES	:= $(wildcard $(patsubst %,%/*.cpp, $(SOURCEDIRS)))
CSOURCES	:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))
SOURCES     := $(CPPSOURCES) $(CSOURCES)

all: $(BIN)/$(EXECUTABLE)

.PHONY: clean
clean:
	del .\$(BIN)\$(EXECUTABLE)

run: all
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SOURCES)
	$(CC) $(CFLAGS) $(CINCLUDES) $(CLIBS) $^ -o $@ $(LIBRARIES)