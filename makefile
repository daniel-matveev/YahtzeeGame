Compiler = clang++
Flags = -g

Yahtzee: main.o Game.o HumanPlayer.o
		${Compiler} ${Flags} $^ -o $@

main.o: main.cpp
		${Compiler} ${Flags} -c $^ -o $@

Game.o: Game.cpp
		${Compiler} ${Flags} -c $^ -o $@

HumanPlayer.o: HumanPlayer.cpp
		${Compiler} ${Flags} -c $^ -o $@

clean:
		rm -f *.o output