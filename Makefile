OBJS = 	src/mm/mm.o src/policy/first_fit.o src/policy/best_fit.o src/collector/collector.o\
 	   	src/memsingleton/memsingleton.o src/policy/policy.o
HEADERS = 	include/collector/collector.h include/memsingleton/memsingleton.h\
 		  	include/mm/mm.h include/policy/best_fit.h include/policy/first_fit.h include/policy/policy.h\
			include/gc.h
CLIENT = client.cpp
CXX = g++
CPPFLAGS = -Wall -std=c++20 -g -pedantic -I include/

all: a.out

a.out: client.o libgc.a
	$(CXX) $(CPPFLAFGS) client.o -L. -lgc

libgc.a: $(OBJS)
	ar -rc libgc.a $(OBJS)   

client.o: $(CLIENT) $(HEADERS)

$(OBJS):$(HEADERS)


.PHONY: clean

clean:
	@rm -f a.out $(OBJS) client.o
