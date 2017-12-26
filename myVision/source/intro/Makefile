# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: clean_all clean_debug clean_release

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`
TESTDIR = ../../test/introTests/
DOCDIR = ../../Docs/
DEBUGDIR = ../../build/Debug/introBuild/
RELEASEDIR = ../../build/Release/introBuild/
CLEANDIR = ../cleanup_scripts/intro/

# DEBUG BUILD

debug: DvideoCopy DdownSampleVid DdownSampleImg

DvideoCopy: $(TESTDIR)testCP.cpp videoCopy.cpp videoCopy.hpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testCP.cpp videoCopy.cpp videoCopy.hpp $(HEADERS) -o $(DEBUGDIR)vidCP

DdownSampleVid: $(TESTDIR)testDS.cpp videoDownSample.cpp videoDownSample.hpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testDS.cpp videoDownSample.cpp videoDownSample.hpp $(HEADERS) -o $(DEBUGDIR)vidDS

DdownSampleImg: $(TESTDIR)testImgDS.cpp imgDownSample.hpp imgDownSample.hpp
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testImgDS.cpp imgDownSample.hpp imgDownSample.hpp $(HEADERS) -o $(DEBUGDIR)imgDS

# RELEASE BUILD

release: RvideoCopy RdownSampleVid RdownSampleImg

RvideoCopy: $(TESTDIR)testCP.cpp videoCopy.cpp videoCopy.hpp
	@$(CC) --std=$(STD) $(TESTDIR)testCP.cpp videoCopy.cpp videoCopy.hpp $(HEADERS) -o $(RELEASEDIR)vidCP

RdownSampleVid: $(TESTDIR)testDS.cpp videoDownSample.cpp videoDownSample.hpp
	@$(CC) --std=$(STD) $(TESTDIR)testDS.cpp videoDownSample.cpp videoDownSample.hpp $(HEADERS) -o $(RELEASEDIR)vidDS

RdownSampleImg: $(TESTDIR)testImgDS.cpp imgDownSample.hpp imgDownSample.hpp
	@$(CC) --std=$(STD) $(TESTDIR)testImgDS.cpp imgDownSample.hpp imgDownSample.hpp $(HEADERS) -o $(RELEASEDIR)imgDS

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
