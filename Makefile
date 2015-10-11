all:llist bst

llist:llist.o
	g++ -g main.cpp llist.o -o main_list

bst:bst.o llist.o
	g++ -g main.cpp llist.o -o main_list
	g++ -g main_bst.cpp bst.o llist.o -o main_bst
	g++ -g main_2.cpp llist.o -o main_ll_2
	
bst.o:bst.cpp
	g++ -g -c bst.cpp -o bst.o
llist.o:llist.cpp
	g++ -g -c llist.cpp -o llist.o

