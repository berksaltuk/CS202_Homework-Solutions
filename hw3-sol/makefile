simulator: simulator.o Heap.o PriorityQueue.o Printer.o KeyedItem.o main.o
			g++ simulator.o Heap.o PriorityQueue.o Printer.o KeyedItem.o main.o -o simulator

simulator.o : simulator.cpp
		g++ -c simulator.cpp

Heap.o : Heap.cpp
		g++ -c Heap.cpp

PriorityQueue.o : PriorityQueue.cpp
		g++ -c PriorityQueue.cpp

Printer.o : Printer.cpp
		g++ -c Printer.cpp

KeyedItem.o : KeyedItem.cpp
		g++ -c KeyedItem.cpp

main.o : main.cpp
		g++ -c main.cpp