#!/usr/bin/python
#Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

import sys
import os

try:
	option = sys.argv[1]
except IndexError, e:
	print e
	print "Usage: python build_project.py debug|release|clean" 
	sys.exit(1)
	
os.chdir("basicImgOps")

if option == "debug":
	os.system("make -j `nproc`")
elif option == "release":
	os.system("make -j `nproc` release")
elif option == "clean":	
	os.system("make -j `nproc` clean_all")
else:
	print "Usage: python build_project.py debug|release|clean" 

os.chdir("../")
