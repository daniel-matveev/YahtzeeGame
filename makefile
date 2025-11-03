Compiler = g++

Yahtzee: main.o Game.o
		${Compiler} $^ -o $@

main.o: main.cpp
		${Compiler} -c $^ -o $@

Game.o: Game.cpp
		${Compiler} -c $^ -o $@

clean:
		rm -f *.o output