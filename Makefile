main: main.c attributes.c input.c wordArray.c
	cc -o main main.c attributes.c input.c wordArray.c
	
clean:
	rm -f *.o
	


