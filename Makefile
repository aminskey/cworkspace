encrypt:
	gcc -o ../bin/encrypt encrypt.c

dog:
	gcc -o ../bin/dog dog.c -lncurses

typeWriter:
	gcc -o ../bin/typeWriter typeWriter.c -lncurses

bookrep:
	gcc -o ../bin/bookrep bookrep.c -lncurses


clean:
	rm -rf ../bin/encrypt
	rm -rf ../bin/dog
	rm -rf ../bin/bookrep
	rm -rf ../bin/typeWriter

all: clean encrypt bookrep dog typeWriter