# Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: clean

STD = c++11
CFLAGS = -g -Wall -Wextra
HEADERS= `pkg-config --libs --cflags opencv`

install:
	#@$(CC) --std=$(STD) $(CFLAGS) main.cpp picture1.cpp picture1.hpp $(HEADERS) -o my_cv
	@$(CC) --std=$(STD) $(CFLAGS) main.cpp video2.cpp video2.hpp $(HEADERS) -o my_cv

clean:
	rm -rf my_cv
