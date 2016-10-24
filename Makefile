inc = ./include
src := $(wildcard source/*.cpp)
obj := $(notdir $(src:.cpp=.o))

CC = g++ -Wall -std=c++11 -I $(inc)

all: Prueba1 Prueba2

Prueba1: pruebas/prueba_iteraciones.cpp $(obj)
	$(CC) $^ -o pruebas/Prueba1.out

Prueba2: pruebas/prueba_steps.cpp $(obj)
	$(CC) $^ -o pruebas/Prueba2.out

%.o: source/%.cpp
	$(CC) -c -o $@ $<

clean:
	rm -f *.o *.out pruebas/*.out Resultados/*.txt

run: all
	@echo "Corriendo Prueba1 ..."
	@./pruebas/Prueba1.out 500 1
	@./pruebas/Prueba1.out 500 2
	@./pruebas/Prueba1.out 500 3
	@./pruebas/Prueba1.out 500 4
	@echo "Listo Prueba1!"
	@echo "Corriendo Prueba2 ..."
	@./pruebas/Prueba2.out 500 1
	@./pruebas/Prueba2.out 500 2
	@./pruebas/Prueba2.out 500 3
	@./pruebas/Prueba2.out 500 4
	@echo "Listo Prueba2!"
	@mv prueba_*.txt Resultados
