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
CLEANDIR = ../cleanup_scripts/basicImgOpsClean/

# DEBUG BUILD

debug: DreadWrite DcropResize Drotate DimageDraw

DreadWrite: $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(DEBUGDIR)readWrite

DcropResize: $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(DEBUGDIR)cropResize

Drotate: $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(DEBUGDIR)rotate

DimageDraw: $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp $(HEADERS) -o $(DEBUGDIR)imageDraw

DhighguiMouse:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testHighguiMouse.cpp highguiMouse.hpp highguiMouse.cpp $(HEADERS) -o $(DEBUGDIR) highguiMouse

# RELEASE BUILD

release: RreadWrite RcropResize Rrotate RimageDraw

RreadWrite: $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp
	@$(CC) --std=$(STD) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o $(RELEASEDIR)readWrite

RcropResize: $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp
	@$(CC) --std=$(STD) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o $(RELEASEDIR)cropResize

Rrotate: $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp
	@$(CC) --std=$(STD) $(TESTDIR)testRot.cpp rotation.hpp rotation.cpp $(HEADERS) -o $(RELEASEDIR)rotate

RimageDraw: $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp
	@$(CC) --std=$(STD) $(TESTDIR)testDraw.cpp imageDraw.hpp imageDraw.cpp $(HEADERS) -o $(RELEASEDIR)imageDraw

RhighguiMouse:
	@$(CC) --std=$(STD) $(TESTDIR)testHighguiMouse.cpp highguiMouse.hpp highguiMouse.cpp $(HEADERS) -o $(RELEASEDIR)highguiMouse

# Build both Debug and Release
all: debug release

clean_all:
	@python $(CLEANDIR)cleanall.py

clean_debug:
	@python $(CLEANDIR)clean_debug.py

clean_release:
	@python $(CLEANDIR)clean_release.py

help:
	@less $(DOCDIR)help.txt
