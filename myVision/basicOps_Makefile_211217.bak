# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: install clean readWrite cropResize all

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`
TESTDIR = ../../test/basicImgOpsTests/
DOCDIR = ../../Docs/
DEBUGDIR = ../../build/Debug/basicImgOpsBuild/
RELEASEDIR = ../../build/Release/basicImgOpsBuild/

# DEBUG BUILD

DreadWrite:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(DEBUGDIR)readWrite

DcropResize:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(DEBUGDIR)cropResize

Drotate:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(DEBUGDIR)rotate

debug: DreadWrite DcropResize Drotate

# RELEASE BUILD

RreadWrite:
	@$(CC) --std=$(STD) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(RELEASEDIR)readWrite

RcropResize:
	@$(CC) --std=$(STD) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(RELEASEDIR)cropResize

Rrotate:
	@$(CC) --std=$(STD) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(RELEASEDIR)rotate

release: RreadWrite RcropResize Rrotate
clean:
	@python cleanup.py

help:
	@less $(DOCDIR)help.txt
