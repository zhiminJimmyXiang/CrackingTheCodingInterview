Chapter4: Chapter4.o Chapter4_test.o
	cd ../DataStructure; make; cd ../Chapter4; g++ -o Chapter4 Chapter4.o Chapter4_test.o ../DataStructure/DataStructure.o

Chapter4.o: Chapter4.cc Chapter4.h

Chapter4_test.o: Chapter4_test.cc Chapter4.h

.PHONY clean:
	rm *.o Chapter4; cd ../DataStructure; make clean;
