all: run

run:
	g++ -I 'include' main.cpp ./source/cache.cpp ./source/Bloque.cpp -o tarea1.o 

clean:
	rm -f *.o