TextGen: main.c attributes.c input.c wordArray.c ./ngramTree/tree.c
	cc -o TextGen main.c attributes.c input.c wordArray.c ./ngramTree/tree.c
	
clean:
	rm -f *.o
	


