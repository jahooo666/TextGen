main: main.c attributes.c input.c wordArray.c ngramArray.c
	cc -o main main.c attributes.c input.c wordArray.c ngramArray.c
	
clean:
	rm -f *.o
	


