# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: 

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`
TESTDIR = ../../test/basicVideoOpsTests/
DOCDIR = ../../Docs/
DEBUGDIR = ../../build/Debug/basicVideoOps/
RELEASEDIR = ../../build/Release/basicVideoOps/
CLEANDIR = ../cleanup_scripts/basicVideoOpsClean/

# DEBUG BUILD - Default build

debug: DvideoRead DvideoWrite

DvideoRead: $(TESTDIR)testVideoRead.cpp videoRead.hpp videoRead.cpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testVideoRead.cpp videoRead.hpp videoRead.cpp $(HEADERS) -o $(DEBUGDIR)videoRead

DvideoWrite: $(TESTDIR)testVideoWrite.cpp videoWrite.hpp videoWrite.cpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testVideoWrite.cpp videoWrite.hpp videoWrite.cpp $(HEADERS) -o $(DEBUGDIR)videoWrite

# RELEASE BUILD

release: RvideoRead RvideoWrite

RvideoRead: $(TESTDIR)testVideoRead.cpp videoRead.hpp videoRead.cpp
	@$(CC) --std=$(STD) $(TESTDIR)testVideoRead.cpp videoRead.hpp videoRead.cpp  $(HEADERS) -o $(RELEASEDIR)videoRead

RvideoWrite: $(TESTDIR)testVideoWrite.cpp videoWrite.hpp videoWrite.cpp
	@$(CC) --std=$(STD) $(TESTDIR)testVideoWrite.cpp videoWrite.hpp videoWrite.cpp $(HEADERS) -o $(RELEASEDIR)videoWrite

# Build both Debug and Release
all: debug release

clean_all:
	@python $(CLEANDIR)cleanall.py

clean_debug:
	@python $(CLEANDIR)clean_debug.py

clean_release:
	@python $(CLEANDIR)clean_release.py

help:
	@less $(DOCDIR)make_help.txt
