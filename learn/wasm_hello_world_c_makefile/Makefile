
IDIR =./include
CC=emcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =./lib


singlehello.js: hellomake.o hellofunc.o
	$(CC) $^ -o $@

hellomake.o: src/hellomake.c
	$(CC) -c $^ -o $@ $(CFLAGS)

hellofunc.o: src/hellofunc.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
