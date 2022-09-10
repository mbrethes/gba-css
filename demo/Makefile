BASEDIR=~mathieu/Projets/GBA/tools/bin
WAV2C=$(BASEDIR)/wav2c
PNM2GBA=$(BASEDIR)/pnm2pix8
PNM2TMAP=$(BASEDIR)/pnm2tmap
PAL2GBA=$(BASEDIR)/pal2gba
CC=arm-thumb-elf-gcc
AS=arm-thumb-elf-as
OCPY=arm-thumb-elf-objcopy
LD=arm-thumb-elf-ld

CAFLAGS=-marm -mthumb-interwork -O3 -I../
CFLAGS=-mthumb -mthumb-interwork -O3 -I../
MFLAGS=-mthumb -mthumb-interwork -O0 -I../
LDFLAGS=-Tlnkscript
OCPYFLAGS=-O binary

main.bin: main.elf
	$(OCPY) $(OCPYFLAGS) main.elf main.bin

main.elf: crt0.o main.o	clarkmix.o clarkmod.o clarkpic.o clarkpal.o clarkdemo.o trump.o music.o ascii.o asciipal.o shake.o hatclose.o kicker.o snr.o
	$(LD) $(LDFLAGS) crt0.o main.o clarkmix.o clarkmod.o clarkpic.o clarkpal.o clarkdemo.o trump.o music.o ascii.o asciipal.o hatclose.o shake.o kicker.o snr.o -o main.elf 

crt0.o: crt0.s
	$(AS) -mthumb-interwork crt0.s -o crt0.o

main.o: main.c ../gba.h ../clarkmix.h ../gfx.h ../clarkmod.h ../clarkfreqs.h clarkpic.h clarkpal.h clarkdemo.h ascii.h asciipal.h
	$(CC) $(CFLAGS) -c main.c

clarkdemo.o: clarkdemo.c clarkdemo.h ../gfx.h clarkpic.h
	$(CC) $(CAFLAGS) -c clarkdemo.c

clarkmix.o: ../clarkmix.c ../clarkmix.h ../clarkfreqs.h ../clarkmod.h
	$(CC) $(CAFLAGS) -c ../clarkmix.c -o clarkmix.o

clarkmod.o: ../clarkmod.c ../clarkmod.h ../clarkmix.h
	$(CC) $(CAFLAGS) -c ../clarkmod.c -o clarkmod.o

# media files

clarkpic.o: clarkpic.c clarkpic.h
	$(CC) $(MFLAGS) -c clarkpic.c

clarkpal.o: clarkpal.c clarkpal.h
	$(CC) $(MFLAGS) -c clarkpal.c

ascii.o: ascii.c ascii.h
	$(CC) $(MFLAGS) -c ascii.c

asciipal.o: asciipal.c asciipal.h
	$(CC) $(MFLAGS) -c asciipal.c

trump.o: trump.c
	$(CC) $(MFLAGS) -c trump.c

shake.o: shake.c
	$(CC) $(MFLAGS) -c shake.c

snr.o: snr.c
	$(CC) $(MFLAGS) -c snr.c

kicker.o: kicker.c
	$(CC) $(MFLAGS) -c kicker.c

hatclose.o: hatclose.c
	$(CC) $(MFLAGS) -c hatclose.c

music.o: music.c ../clarkfreqs.h
	$(CC) $(MFLAGS) -c music.c -o music.o
	
clean:
	rm -f *.o *.bin *.elf
