show:
	gcc pass.c -lcurl -lncurses -o ../bin/webshow

talk:
	gcc termtalk.c -o ../bin/ttalk

Webose:
	gcc verbose.c -lcurl -o ../bin/webose

desk:
	gcc MzDesk/libfuncs/*.c MzDesk/*.c -IMzDesk/acornlibs -fdiagnostics-generate-patch -lncurses -o ~/bin/AcornDesk
game:
	gcc gameStation/libfuncs/*.c *.c -Ilibs -fdiagnostics-generate-patch -lncurses -o ~/bin/GameStation
enc:
	gcc enc.c -o ../bin/Encrypt
dnc:
	gcc dnc.c -o ../bin/Decrypt

OpsTable:
	gcc table2-1.c -lncurses -o ../bin/OpsTable

FourTerm:
	gcc thread.c -o ../bin/FourTerm
tty:
	gcc -o ../bin/TTYTALK TTTalk.c
graph:
	gcc graph.c -o ../bin/graphprog

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
BOXEmu:
	gcc -o ../bin/AcornDos drvConf.c Mybox.c -lncurses
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
createHello:
	gcc Hello.c -lncurses; ./a.out

typeWrite:
	gcc -o ../bin/typeWriter typeWriter.c -lncurses

showimg:
	cimg c.img
clean:
	rm -rf ../bin/webshow
	rm -rf ../bin/Translate
	rm -rf ../bin/deTranslate
	rm -rf ../bin/dog
	rm -rf ../bin/ttalk
	rm -rf ../bin/bookrep
	rm -rf ../bin/typeWriter
	rm -rf ../bin/Time
	rm -rf ../bin/StoreCal
	rm -rf ../bin/WinSh
	rm -rf ../bin/MG
	rm -rf ../bin/AcornDos
	rm -rf ../bin/Edit
	rm -rf ../bin/webose
	rm -rf ../bin/AsciiHex
	rm -rf ../bin/graphprog
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
	rm -rf ../bin/AcornDesk
	rm -rf ../bin/GameStation
	rm -rf ../bin

all: clean createBin show talk Webose desk game graph OpsTable tty FourTerm MySh dir Translate bookrep dog deTranslate MoveProj typeWrite  StoreCal AsciiTable testSh AsciiHex BOXEmu Edit Archive getMax hRead imgRead lost read storeCal dnc enc showimg createHello
