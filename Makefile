attributes: main.o attributes.o
	$(CC) -o attributes main.o attributes.o
main: main.o attributes.o
	$(CC) -o main main.o attributes.o
	
.PHONY: clean
clean:
	-rm *.o attributes
