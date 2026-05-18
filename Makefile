game: TicTacToe.o
	gcc TicTacToe.o -o game

TicTacToe.o: TicTacToe.c
	gcc -Wall -Werror -pedantic -c TicTacToe.c

