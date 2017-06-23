CC = gcc
CFLAGS = -g -Wall --std=c99
OBJECTS = main.o my_string.o my_vect.o unit_test.o test_def.o my_tree.o

string_driver: $(OBJECTS)
	$(CC) $(CFLAGS) -o string_driver main.o my_string.o my_vect.o my_tree.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

my_string.o: my_string.h my_string.c
	$(CC) $(CFLAGS) -c my_string.c -o my_string.o

my_vect.o: my_vect.h my_vect.c my_string.h my_string.c 
	$(CC) $(CFLAGS) -c my_vect.c -o my_vect.o

my_tree.o: my_tree.h my_tree.c my_vect.h my_vect.c my_string.h my_string.c 
	$(CC) $(CFLAGS) -c my_tree.c -o my_tree.o
unit_test: my_string.o unit_test.o test_def.o
	$(CC) $(CFLAGS) -o unit_test unit_test.o test_def.o my_string.o

clean:
	rm string_driver unit_test $(OBJECTS)
