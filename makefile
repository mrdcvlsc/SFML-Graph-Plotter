default:
	cmake --build build && ./build/SFML-Graph-Plotter

style:
	@echo fixing code format and code style...
	@clang-format -i -style=file main.cpp include/*.hpp src/*.cpp
	@echo done fixing style format.

clean:
	rm -r build