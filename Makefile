inc = ./include
src := $(wildcard source/*.cpp)
obj := $(notdir $(src:.cpp=.o))

CC = g++ -Wall -std=c++11 -I $(inc)

all: pruebas

pruebas: Prueba1 Prueba2

Prueba1: pruebas/prueba_iteraciones.cpp $(obj)
	$(CC) $^ -o pruebas/Prueba1.out

Prueba2: pruebas/prueba_steps.cpp $(obj)
	$(CC) $^ -o pruebas/Prueba2.out

%.o: source/%.cpp
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.out pruebas/*.out

run: all
	@echo "Corriendo Prueba1 ..."
	./pruebas/Prueba1.out
	@echo "Listo!"
	@echo "Corriendo Prueba2 ..."
	./pruebas/Prueba2.out
	@echo "Listo!"
