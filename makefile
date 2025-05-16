prog: main.o banco.o
	g++ -o prog main.o banco.o 
	
main.o: main.cpp
	g++ -c main.cpp 

banco.o: banco.cpp banco.h
	g++ -c banco.cpp 

clean:
	rm *.o prog