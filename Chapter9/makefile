Chapter9: Chapter9.o Chapter9_test.o Box.o
	cd ../DataStructure; make; cd ../Chapter9; g++ -o Chapter9 Chapter9.o Chapter9_test.o ../DataStructure/DataStructure.o Box.o

Chapter9.o: Chapter9.cc Chapter9.h

Chapter9_test.o: Chapter9_test.cc Chapter9.h

Box.o: Box.cc Chapter9.h

.PHONY clean:
	rm *.o Chapter9; cd ../DataStructure; make clean;
