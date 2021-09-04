slither: main.cpp
	g++ main.cpp -o slither
clear: 
	rm -f ./slither
do_all: main.cpp ui.cpp game.cpp snake.cpp food.cpp
	g++ -std=c++17 main.cpp ui.cpp game.cpp snake.cpp food.cpp -lncurses -o slither && ./slither