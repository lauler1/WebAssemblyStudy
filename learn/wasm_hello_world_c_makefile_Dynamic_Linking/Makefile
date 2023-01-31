
IDIR =./include
CC=emcc
CFLAGS=-I$(IDIR)
CFLAGS+= -g
CFLAGS+= -sLLD_REPORT_UNDEFINED #to get more information on undefined symbols
CFLAGS+= -sERROR_ON_UNDEFINED_SYMBOLS=0 #To disable errors for undefined symbols

#-sSIDE_MODULE=1/-sMAIN_MODULE=1 (Bigger file) All the code compiled remains in the output, including all system libraries linked in, and also all the JS library code
#-sSIDE_MODULE=2/-sMAIN_MODULE=2 (Less code in file) Normal dead code elimination. The main module is built normally, with no special behavior for keeping code alive.

ODIR=obj
LDIR =./lib

all: singlehello.js

singlehello.js: hellofunc.wasm src/hellomake.c
	$(CC) $^ -s MAIN_MODULE=2 -o $@ $(CFLAGS)

hellofunc.wasm: src/hellofunc.c
	$(CC) $< -s SIDE_MODULE=1 -o $@ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *.o *~ core $(INCDIR)/*~
	rm -f *.wasm *.js a.out*
