OpsTable:
	gcc table2-1.c -lncurses -o ../bin/OpsTable

FourTerm:
	gcc thread.c -o ../bin/FourTerm
tty:
	gcc -o ../bin/TTYTALK TTTalk.c

createBin:
	mkdir ../bin

Translate:
	gcc -o ../bin/Translate translate.c

Time:
	gcc -o ../bin/Date-Time time.c

testSh:
	gcc -o ../bin/Testsh myShell.c

MySh:
	gcc -o ../bin/WinSh test.c -lncurses
dir:
	gcc -o ../bin/dir sp.c -lncurses

StoreCal:
	gcc -o ../bin/StoreCal storeCalculator.c -lncurses
MoveProj:
	gcc move.c -lncurses -o ../bin/MoveProj

deTranslate:
	gcc -o ../bin/deTranslate detranslate.c
dog:
	gcc -o ../bin/dog dog.c -lncurses

bookrep:
	gcc -o ../bin/bookrep bookrep.c -lncurses

AsciiTable:
	gcc -o ../bin/AsciiTable AsciiTable.c -lncurses
BoxEmu:
	gcc -o ../bin/BoxEmu Mybox.c -lncurses
Edit:
	gcc -o ../bin/Edit Edit.c -lncurses
AsciiHex:
	gcc -o ../bin/AsciiHex AsciiHex.c -lncurses
Archive:
	gcc -o ../bin/Archive arch.c -lncurses

getMax:
	gcc -o ../bin/GetScrMax getsMax.c -lncurses
hRead:
	gcc -o ../bin/HexRead hexRead.c -lncurses
imgRead:
	gcc -o ../bin/cimg imgRead.c -lncurses
lost:
	gcc -o ../bin/Lost lost.c -lncurses
read:
	gcc read.c -o ../bin/binaryFileTotext
storeCal:
	gcc -o ../bin/StoreCal storeCalculator.c -lncurses
typeWrite:
	gcc -o ../bin/typeWriter typeWriter.c -lncurses
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
	rm -rf ../bin/BoxEmu
	rm -rf ../bin/Edit
	rm -rf ../bin/AsciiHex
	rm -rf ../bin/Archive
	rm -rf ../bin/HexRead
	rm -rf ../bin/cimg
	rm -rf ../bin/Lost
	rm -rf ../bin/binaryFileTotext
	rm -rf ../bin/StoreCal
	rm -rf ../bin/typeWriter
	rm -rf ../bin/OpsTable
	rm -rf ../bin/Testsh
	rm -rf ../bin/FourTerm
	rm -rf ../bin/TTYTALK
	rm -rf ../bin/N-ll
	rm -rf ../bin/AsciiTable
	rm -rf ../bin

all: clean createBin OpsTable tty FourTerm MySh dir Translate bookrep dog deTranslate MoveProj typeWrite  StoreCal AsciiTable testSh AsciiHex BoxEmu Edit Archive getMax hRead imgRead lost read storeCal 
