CC=arm-thumb-elf-gcc

CAFLAGS=-marm -mthumb-interwork -O3
CMODFLAGS=$(CAFLAGS) -D__MOD_PLAYER__

standard: clarkmixstd.o

mod_player: clarkmix.o clarkmod.o

clarkmixstd.o: clarkmix.c clarkmix.h clarkfreqs.h
	$(CC) $(CAFLAGS) -c clarkmix.c

clarkmix.o: clarkmix.c clarkmix.h clarkfreqs.h clarkmod.h
	$(CC) $(CMODFLAGS) -c clarkmix.c

clarkmod.o: clarkmod.c clarkmod.h clarkmix.h
	$(CC) $(CMODFLAGS) -c clarkmod.c

clean:
	rm -f clarkmix.o clarkmod.o
