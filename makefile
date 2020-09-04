all: driver

driver: Driver.cpp proj2aux.o AugmentedBinarySearchTree.o
	g++ -o proj2.out -std=c++11 Driver.cpp proj2aux.o AugmentedBinarySearchTree.o

proj2aux.o: proj2aux.cpp proj2aux.h Exception.h AugmentedBinarySearchTree.h
	g++ -Wall -c -std=c++11 proj2aux.cpp

AugmentedBinarySearchTree.o: AugmentedBinarySearchTree.cpp AugmentedBinarySearchTree.h Exception.h
	g++ -Wall -c -std=c++11 AugmentedBinarySearchTree.cpp

run:
	./proj2.out $(FILE) $(COMMANDS)

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

valgrind:
	valgrind ./proj2.out $(FILE) $(COMMANDS)
