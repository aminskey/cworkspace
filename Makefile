Translate:
	gcc -o ../bin/Translate translate.c

Time:
	gcc -o ../bin/Date-Time time.c
MySh:
	gcc -o ../bin/Myshell test.c

StoreCal:
	gcc -o ../bin/StoreCal storeCalculator.c -lncurses
MoveProj:
	gcc move.c -lncurses -o ../bin/MoveProj

deTranslate:
	gcc -o ../bin/deTranslate detranslate.c
dog:
	gcc -o ../bin/dog dog.c -lncurses

typeWriter:
	gcc -o ../bin/typeWriter typeWriter.c -lncurses

bookrep:
	gcc -o ../bin/bookrep bookrep.c -lncurses
time:
	gcc -o ../bin/Date-Time time.c 

clean:
	rm -rf ../bin/Translate
	rm -rf ../bin/deTranslate
	rm -rf ../bin/dog
	rm -rf ../bin/bookrep
	rm -rf ../bin/typeWriter
	rm -rf ../bin/Time
	rm -rf ../bin/StoreCal
	rm -rf ../bin/Myshell

all: clean Translate bookrep dog typeWriter time deTranslate MoveProj StoreCal MySh
