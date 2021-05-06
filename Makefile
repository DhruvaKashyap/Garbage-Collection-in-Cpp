CXX=g++
CPPFLAGS = -Wall -std=c++20 -g -pedantic

all: a.out

a.out: alloctest.o collector.o memsingleton.o mm.o best_fit.o 
	$(CXX) $(CPPFLAFGS) alloctest.o collector.o memsingleton.o mm.o best_fit.o 

alloctest.o: include/alloc/alloc.h src/alloc/alloctest.cpp
	$(CXX) $(CPPFLAGS) -c src/alloc/alloctest.cpp

collector.o: include/collector/collector.h src/collector/collector.cpp
	$(CXX) $(CPPFLAGS) -c src/collector/collector.cpp

memsingleton.o: include/memsingleton/memsingleton.h src/memsingleton/memsingleton.cpp
	$(CXX) $(CPPFLAGS) -c src/memsingleton/memsingleton.cpp

mm.o: include/mm/mm.h src/mm/mm.cpp
	$(CXX) $(CPPFLAGS) -c src/mm/mm.cpp

best_fit.o: include/policy/best_fit.h include/policy/policy.h src/policy/best_fit.cpp
	$(CXX) $(CPPFLAGS) -c src/policy/best_fit.cpp

.PHONY: clean

clean:
	@rm -f a.out *.o
