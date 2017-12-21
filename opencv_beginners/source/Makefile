#Author: Ratnadeep Bhattacharya <ratnadeep.bhattacharya1983@gmail.com>

CC = g++

.PHONY: release debug

debug:
	@cd basicImgOps
	@make -j `nproc`
	@cd -

release:
	@cd basicImgOps
	@make -j `nproc` release
	@cd -

clean:
	@cd basicImgOps
	@make clean
	@cd -
