Translate:
	gcc -o ../bin/Translate translate.c

Time:
	gcc -o ../bin/Date-Time time.c
MyGameTheme:
	gcc -o ../bin/MG intro.c -lncurses

testSh:
	gcc -o ../bin/Testsh myShell.c

MySh:
	gcc -o ../bin/WinSh test.c -lncurses
ncll:
	gcc -o ../bin/N-ll sp.c -lncurses

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
	rm -rf ../bin/WinSh
	rm -rf ../bin/MG
	rm -rf ../bin/Testsh
	rm -rf ../bin/N-ll

all: clean MySh ncll Translate bookrep dog typeWriter deTranslate MoveProj StoreCal MySh MyGameTheme testSh
