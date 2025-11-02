Compiler = g++

Yahtzee: main.o Dice.o Hand.o Game.o
		${Compiler} $^ -o $@

main.o: main.cpp
		${Compiler} -c $^ -o $@

Dice.o: Dice.cpp 
		${Compiler} -c $^ -o $@

Hand.o: Hand.cpp	
		${Compiler} -c $^ -o $@

Game.o: Game.cpp
		${Compiler} -c $^ -o $@

clean:
		rm -f *.o output