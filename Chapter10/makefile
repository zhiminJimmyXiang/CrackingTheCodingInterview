Chapter10: Chapter10.o Chapter10_test.o
	cd ../DataStructure; make; cd ../Chapter10; g++ -o Chapter10 Chapter10.o Chapter10_test.o ../DataStructure/DataStructure.o

Chapter10.o: Chapter10.cc Chapter10.h

Chapter10_test.o: Chapter10_test.cc Chapter10.h

.PHONY clean:
	rm Chapter10; rm *.o; cd ../DataStructure; make clean;
