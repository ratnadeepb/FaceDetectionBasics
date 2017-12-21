# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: install clean readWrite cropResize all

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`
TESTDIR = ../../test/basicImgOpsTests/
DOCDIR = ../../Docs/

readWrite:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testRW.cpp readWriteDisplay.cpp readWriteDisplay.hpp $(HEADERS) -o readWrite

cropResize:
	@$(CC) --std=$(STD) $(CFLAGS) $(TESTDIR)testCR.cpp cropResize.hpp cropResize.cpp $(HEADERS) -o cropResize

all: readWrite cropResize

clean:
	@python cleanup.py

help:
	@less $(DOCDIR)help.txt
