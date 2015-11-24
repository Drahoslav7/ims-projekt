# Model dopravního uzlu
# 
# IMS - Modelování a simulace
# 2015/2016
#
# Autoři:
# (xbalvi00) David Balvín
# (xbedna55) Drahoslav Bednář

NAME := simulation

build:
	make -C src/

run:
	./bin/($NAME)



clean: clear
clear: rm -r bin

pack:
	tar -cvzf 06_xbalvi00_xbedna55.tar.gz Makefile src/* dokumentace.pdf
