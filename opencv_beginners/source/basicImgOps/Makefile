# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: Dreadwrite DcropResize Drotate DimageDraw debug RreadWrite RcropResize Rrotate RimageDraw release clean_all clean_debug clean_release help

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`
TESTDIR = ../../test/basicImgOpsTests/
DOCDIR = ../../Docs/
DEBUGDIR = ../../build/Debug/basicImgOps/
RELEASEDIR = ../../build/Release/basicImgOps/

# DEBUG BUILD

debug: DreadWrite DcropResize Drotate DimageDraw

DreadWrite: $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(DEBUGDIR)readWrite

DcropResize:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(DEBUGDIR)cropResize

Drotate:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(DEBUGDIR)rotate

DimageDraw:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp $(HEADERS) -o $(DEBUGDIR)imageDraw

#debug: DreadWrite DcropResize Drotate DimageDraw

# RELEASE BUILD

RreadWrite:
	@$(CC) --std=$(STD) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(RELEASEDIR)readWrite

RcropResize:
	@$(CC) --std=$(STD) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(RELEASEDIR)cropResize

Rrotate:
	@$(CC) --std=$(STD) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(RELEASEDIR)rotate

RimageDraw:
	@$(CC) --std=$(STD) $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp $(HEADERS) -o $(RELEASEDIR)imageDraw

release: RreadWrite RcropResize Rrotate RimageDraw

clean_all:
	@python ../cleanup_scripts/basicImgOpsClean/cleanall.py

clean_debug:
	@python ../cleanup_scripts/basicImgOpsClean/clean_debug.py

clean_release:
	@python ../cleanup_scripts/basicImgOpsClean/clean_release.py

help:
	@less $(DOCDIR)help.txt
