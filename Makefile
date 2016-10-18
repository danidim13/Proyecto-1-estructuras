inc = ./include
src := $(wildcard src/*.cpp)
obj := $(notdir $(src:.cpp=.o))

CC = g++ -Wall -std=c++11 -I $(inc)

all: $(obj)

%.o: src/%.cpp
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.out 
