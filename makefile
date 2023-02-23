CXX = g++ -pthread
GFLAGS = -g -std=c++11
OBJECTS = driver.o MatrixMultiplier.o TimeInterval.o matrix/matrix.o
FILES = driver.cpp MatrixMultiplier.cpp TimeInterval.cpp matrix.cc

driver: driver.o matrix/matrix.o
	$(CXX) $(GFLAGS) -o driver $(OBJECTS)

driver.o: driver.cpp MatrixMultiplier.o TimeInterval.o
	$(CXX) $(GFLAGS) -c driver.cpp

MatrixMultiplier.o: MatrixMultiplier.h MatrixMultiplier.cpp
	$(CXX) $(GFLAGS) -c MatrixMultiplier.cpp

TimeInterval.o: TimeInterval.h TimeInterval.cpp
	$(CXX) $(GFLAGS) -c TimeInterval.cpp

clean:
	rm -f driver
	rm *.o
	rm matrix/matrix.o

run: driver
	./driver

valgrind: driver
	valgrind --tool=memcheck --leak-check=yes --show-reachable=yes --num-callers=20 --track-fds=yes ./driver
