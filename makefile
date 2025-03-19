link: main.o vector.o rect.o button.o
	gcc main.o vector.o rect.o button.o -o algo.out -lraylib -lm -lGL -lpthread -ldl -lrt -lX11

main.o:
	gcc -c src/main.c -Iinclude  

rect.o:
	gcc -c include/rect.c -Iinclude

vector.o:
	gcc -c include/vector.c -Iinclude  

button.o:
	gcc -c include/button.c -Iinclude

clean: 
	rm -f *.o *.out 
