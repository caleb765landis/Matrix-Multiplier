CXX = g++
GFLAGS = -g -std=c++11
OBJECTS = driver.o MatrixMultiplier.o matrix/matrix.o
FILES = driver.cpp MatrixMultiplier.cpp matrix.cc

driver: driver.o matrix/matrix.o
	$(CXX) $(GFLAGS) -o driver $(OBJECTS)

driver.o: driver.cpp MatrixMultiplier.o
	$(CXX) $(GFLAGS) -c driver.cpp

MatrixMultiplier.o: MatrixMultiplier.h MatrixMultiplier.cpp
	$(CXX) $(GFLAGS) -c MatrixMultiplier.cpp

clean:
	rm -f driver
	rm *.o
	rm matrix/matrix.o

run: driver
	./driver

valgrind: driver
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./driver