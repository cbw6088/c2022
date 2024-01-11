test.out : main.o delete.o insert.o print.o find_by_birth.o RegFromFile_read.o RegFromFile_write.o
	gcc -o test.out main.o delete.o insert.o print.o find_by_birth.o RegFromFile_read.o RegFromFile_write.o

main.o :
	gcc -c main.c
	
delete.o :
	gcc -c delete.c

insert.o :
	gcc -c insert.c

find_by_birth.o :
	gcc -c find_by_birth.c

RegFromFile_read.o :
	gcc -c RegFromFile_read.c

RegFromFile_write.o :
	gcc -c RegFromFile_write.c

print.o :
	gcc -c print.c

clean : 
	rm *.o test.o