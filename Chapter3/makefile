Chapter3: Chapter3.o Chapter3_test.o
	cd ../DataStructure; make; cd ../Chapter3; g++ -o Chapter3 Chapter3.o Chapter3_test.o ../DataStructure/DataStructure.o

Chapter3.o: Chapter3.cc Chapter3.h

Chapter3_test.o: Chapter3_test.cc Chapter3.h

.PHONY clean:
	rm *.o Chapter3; cd ../DataStructure; make clean;
