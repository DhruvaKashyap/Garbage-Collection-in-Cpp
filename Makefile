CXX=g++
CPPFLAGS = -O3 -Wall -std=c++20 -pedantic -I include/

all: a.out

.PHONY: clean

clean:
	@rm -f a.out debug.out test.out