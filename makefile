
Laboratorio:
g++ -g -o testRiver FileReader/fileReader.cpp Hash/hashTable.cpp LinkedList/LinkedList.cpp  Operation/Operation.cpp Restriction/Restriction.cpp State/State.cpp RiverCrossing/RiverCrossing.cpp RiverCrossing/testRiver.cpp bitService/bitService.cpp	

State: State.o
	g++ State.o -o testState.out State/testState.cpp

State.o: State/State.cpp State/State.h
	g++ -c State/State.cpp

clean:
	rm -r **/*.out
	rm -r **/*.o

