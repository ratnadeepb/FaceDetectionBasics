# The script should be run only as part of Makefile from source/basicVideoOps/
# Otherwise, you will get errors
import os

#files = os.listdir("../../basicVideoOps/")
files = os.listdir(".")
for f in files:
	if f[-3:] not in ['hpp', 'cpp'] and f != "cleanup.py" and f != "Makefile":
		os.remove(f)

files = os.listdir("../../build/Debug/basicVideoOps")
cleaned = []
for f in files:
#	if os.access(f, os.X_OK):
	cleaned.append(f)
	d = "../../build/Debug/basicVideoOps/" + f
	os.remove(d)
	print("%s removed!" %f)

files = os.listdir("../../build/Release/basicVideoOps")
for f in files:
	cleaned.append(f)
	d = "../../build/Release/basicVideoOps/" + f
	os.remove(d)
	print("%s removed!" %f)

if len(cleaned) == 0:
	print("Nothing to remove")
