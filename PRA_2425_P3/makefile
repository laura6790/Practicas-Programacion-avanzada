bin/testTableEntry: testTableEntry.cpp TableEntry.h
	mkdir -p bin
	g++ -o bin/testTableEntry testTableEntry.cpp
bin/testHashTable: testHashTable.cpp HashTable.h TableEntry.h Dict.h
	mkdir -p bin
	g++ -I../PRA_2425_P1 -o bin/testHashTable testHashTable.cpp
bin/testBSTree: testBSTree.cpp BSTree.h BSNode.h
	mkdir -p bin
	g++ -o bin/testBSTree testBSTree.cpp

bin/testBSTreeDict: testBSTreeDict.cpp BSTreeDict.h TableEntry.h Dict.h BSNode.h BSTree.h
	mkdir -p bin
	g++ -o bin/testBSTreeDict testBSTreeDict.cpp


clean:
	rm -rf *.o *.gch bin
