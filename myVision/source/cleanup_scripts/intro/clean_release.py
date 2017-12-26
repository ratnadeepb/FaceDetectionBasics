# The script should be run only as part of Makefile from source/introBuild/
# Otherwise, you will get errors
import os

files = os.listdir(".")
for f in files:
	if f[-3:] not in ['hpp', 'cpp'] and f != "cleanup.py" and f != "Makefile":
		os.remove(f)

files = os.listdir("../../build/Release/introBuild")
cleaned = []
for f in files:
#	if os.access(f, os.X_OK):
	cleaned.append(f)
	d = "../../build/Release/introBuild/" + f
	os.remove(d)
	print("%s removed!" %f)

if len(cleaned) == 0:
	print("Nothing to remove")
