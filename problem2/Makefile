operation : statictest sharetest rdynamic

statictest : main.c
	gcc -I./lib -L./lib main.c -o statictest -lstest

sharetest : main.c
	gcc -I./lib -L./lib main.c -o sharetest -lstest

rdynamic : main.c
	gcc -rdynamic dltest.c -o rdynamictest -ldl

clean :
	rm -f *.o

