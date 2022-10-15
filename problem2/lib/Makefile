Operation : libstest.a libdtest.so.1.0.1

libstest.a : add.o div.o mult.o sub.o
	ar rcs libstest.a add.o div.o mult.o sub.o

libdtest.so.1.0.1 : add.o div.o mult.o sub.o
	gcc -shared -Wl,-soname,libdtest.so.1 -o libdtest.so.1.0.1 add.o div.o mult.o sub.o
	ln -s libdtest.so.1.0.1 libdtest.so.1
	ln -s libdtest.so.1.0.1 libdtest.so
add.o : add.c
	gcc -c add.c

div.o : div.c
	gcc -c div.c

mult.o : mult.c
	gcc -c mult.c

sub.o : sub.c
	gcc -c sub.c

clean :
	rm -f *.o
	rm -f *.so
