import os
files = os.listdir(".")
cleaned = []
for f in files:
	if os.access(f, os.X_OK) and f != "cleanup.py":
		cleaned.append(f)
		os.remove(f)
		print("%s removed!" %f)

if len(cleaned) == 0:
	print("Nothing to remove")
