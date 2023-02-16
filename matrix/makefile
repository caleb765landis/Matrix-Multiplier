CC	= g++
CXX     = g++
CFLAGS	= -g
CXXFLAGS= $(CFLAGS)
TARGETS	= mread 

mread: mread.o matrix.o

.PHONY: clean cleanall all

clean:
	@$(RM) *.o *~ 

cleanall: clean
	@$(RM) $(TARGETS)

