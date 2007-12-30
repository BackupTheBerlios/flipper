
diff: diff.c composed.c simple.c intset.c simple.h composed.h tables.h formula.h defines.h intset.h params.h formula.pl
	fo2c < formula.pl > formula.h
	gcc -Os -fomit-frame-pointer -o diff simple.c  composed.c intset.c diff.c
	#tcc -o diff *.c
	./diff
clean:
	rm -f *.o
	rm -f diff
