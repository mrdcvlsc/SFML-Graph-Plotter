CC:=clang
CXX:=clang++

INCLUDE:=./include/
SRC:=src

# LIBS:=-lX11 -lXrandr -lXcursor -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system -fsanitize=address -g3
LIBS:=-lX11 -lXrandr -lXcursor -lsfml-graphics -lsfml-window -lsfml-system -fsanitize=address -g3

CXX_STANDARD:=-std=c++17
FLAGS:=-Wall -Wextra
DFLAGS:=

default:
	cmake --build build && ./build/SFML-Graph-Plotter

dev:
	$(strip $(CXX) $(CXX_STANDARD) $(FLAGS) -I"$(INCLUDE)" $(DFLAGS) src/grid.cpp main.cpp -o main.out $(LIBS))
	./main.out

style:
	@echo fixing code format and code style...
	@clang-format -i -style=file main.cpp include/*.hpp src/*.cpp
	@echo done fixing style format.

clean:
	rm -r build