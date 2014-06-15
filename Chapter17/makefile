Chapter17: Chapter17.o Chapter17_test.o
	cd ../DataStructure; make; cd ../Chapter17; g++ -o Chapter17 Chapter17.o Chapter17_test.o ../DataStructure/DataStructure.o;

Chapter17.o: Chapter17.cc Chapter17.h

Chapter17_test.o: Chapter17_test.cc Chapter17.h

.PHONY clean:
	rm Chapter17; rm *.o; cd ../DataStructure; make clean;
