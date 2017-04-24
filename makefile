OBJ = main.o wave.o screen.o comm.o #(added later)
APPNAME = sound.a
ZIPNAME = sound.tar

$(APPNAME) : $(OBJ)
	gcc -o $(APPNAME) $(OBJ) -lm -lcurl
%.o : %.c
	gcc -c -o $@ $< -std=c99

clean:
	rm $(OBJ) $(APPNAME)
archive:
	tar cf $(ZIPNAME) *.c *.h makefile
