OBJS = 	src/mm/mm.o src/policy/first_fit.o src/policy/best_fit.o src/collector/collector.o\
 	   	src/memsingleton/memsingleton.o src/policy/policy.o
CLIENT = client.cpp
CXX = g++
CPPFLAGS = -Wall -std=c++20 -g -pedantic -I include/

all: a.out

a.out: client.o libgc.a
	$(CXX) $(CPPFLAFGS) client.o -L. -lgc

libgc.a: $(OBJS)
	ar -rc libgc.a $(OBJS)   

client.o: $(CLIENT) include/gc.h

src/mm/mm.o: include/mm/mm.h include/meta/meta.h include/policy/policy.h include/policy/best_fit.h include/policy/first_fit.h src/mm/mm.cpp

src/policy/first_fit.o: include/policy/policy.h include/policy/first_fit.h src/policy/first_fit.cpp

src/policy/best_fit.o: include/policy/policy.h include/policy/best_fit.h src/policy/best_fit.cpp

src/collector/collector.o: include/collector/collector.h include/meta/meta.h src/collector/collector.cpp

src/memsingleton/memsingleton.o: include/memsingleton/memsingleton.h src/memsingleton/memsingleton.cpp

src/policy/policy.o: include/policy/policy.h src/policy/policy.cpp

.PHONY: clean

clean:
	@rm -f a.out $(OBJS) client.o
