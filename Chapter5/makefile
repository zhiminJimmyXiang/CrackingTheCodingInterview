Chapter5: Chapter5.o Chapter5_test.o
	cd ../DataStructure; make; cd ../Chapter5; g++ -o Chapter5 Chapter5.o Chapter5_test.o ../DataStructure/DataStructure.o

Chapter5.o: Chapter5.cc Chapter5.h

Chapter5_test.o: Chapter5_test.cc Chapter5.h

.PHONY clean:
	rm *.o Chapter5; cd ../DataStructure; make clean;
