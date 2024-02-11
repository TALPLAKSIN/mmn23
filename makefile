index: index.o linked_list.o
	gcc -Wall -ansi -pedantic index.o linked_list.o -o index

index.o: index.c linked_list.h
	gcc -g -c -Wall -ansi -pedantic index.c -o index.o

linked_list.o: linked_list.c linked_list.h
	gcc -g -c -ansi -Wall -pedantic linked_list.c -o linked_list.o

clean:
	rm -f index.o linked_list.o index