Chapter2: Chapter2.o Chapter2_test.o
	cd ../DataStructure; make; cd ../Chapter2; g++ -o Chapter2 Chapter2.o Chapter2_test.o ../DataStructure/DataStructure.o

Chapter2.o: Chapter2.cc Chapter2.h

Chapter2_test.o: Chapter2_test.cc Chapter2.h

.PHONY clean:
	rm *.o Chapter2; cd ../DataStructure; make clean;
