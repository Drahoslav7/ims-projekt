NAME := simulation

build: $(NAME)

$(NAME): main.cpp
	[ -d ../bin ] || mkdir ../bin
	g++ -std=c++11 -o ../bin/$@ $^