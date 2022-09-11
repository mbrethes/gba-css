# The Clarkinou Sound System

A general purpose sound-playing library for the Game Boy Advance, written in C back in 2003.

## License

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.


The files in the [tools](tools) directory have a separate license, the GNU GPL V2.

## Introduction

Every Game Boy Advance homebrew programmer has a single dream in his/her life :
adding some nice tunes to his/her program. However, information on the internet
about sound programming is quite sparse. And information about Game Boy Advance
sound programming is even sparser.

This library is my attempt at trying to get some sound out of the gaming
console. It is written entierly in C, as I am not really an ASM freak, uses the
"direct sound" output of the Game Boy Advance to provide stereo sound.

It is able to mix mono WAV samples, 8-bit signed, with a given panning,
volume, and pitch, and looping. The number of samples mixable at the same
time is fixed, by default, to 4.

A [tool](tools/wave2c) is provided to convert WAV files to a sample format usable in your
programs.

I added some kind of "modplaying" functionnality to that sound library, but
it is still beta - no tools are available to convert mod files to the internal
format of the modplayer, thus you have to code your module yourself... Not yet
really usable. The modplayer can use up to N channels (N <= 4 by default...) of
signed samples, with panning, volume, pitch, and loop.

In both cases (library/modplayer) it is also possible to change the volume,
pitch, or panning of a currently playing sample, which can prove very handy
at times.

## Project history

It all started at the end of july. I was stuck with a game project which
required sound, for the GBA 2003 Compo, and I had no damn idea of how to
produce sound out of the speaker. I started by browsing the internet and
implementing an example found on a website (see "resource" section, folks).

It was very basic : taking a sample adress from memory, feeding it to DMA,
and playing it to left and right speaker using DSound registers.

I added stereo support by doing that thing twice.

Then came, a few days later, a "double-buffering" technique. Small buffers in
the GBA inner (and fastest memory) were feeded with chunks of data from the
sound samples at a constant time interval. After a few hours of tweaking
around, it started to work well.

As I already had stereo working, I decided to add some volume management and
panning functionnality. Each mono sample had, then, two "volume" values, one
for left speaker, one for right speaker, thatwere computed from the initial
volume and the panning given.

Then I moved to Sweden, and the project was interrupted for two months. The
compo passed over, and I made no entry. But it motivated me to start working
again.

Noticing many sound players are able to loop samples, I added a "loop"
functionnality - basically checking whether the sample pointer passed over
the end of the loop and jumping back to the beginning of the loop.

The big improvement came at the start of october. I added a basic mixing
function, that added samples together. And, oddly enough, it worked ! I started
to tune up the whole thing so it coped with speed - it went down from 50% CPU
usage to 25% mixing 4 mono samples into stereo output. I know it's still much,
but it's better not optimizing before the very end of a project.

Pitch control was easy to add, after understanding how fixed-point calculation
worked.

And finally, I implemented, but without really great success, two sucessive
"modplayers". The first one never worked, the second is quite lousy, and I
guess this is where most of the work should be done now.


## Using the library

### What are those files, actually ?

In the main directory, reside several files :
- clarkmix.h and clarkmix.c are the main mixer source files,
- clarkmod.h and clarkmod.c are the module player source files,
- dma.h, dsound.h, oam.h, timer.h and gba.h are include files used by the
  library.

There is also a "tools" subdirectory, described later on. The tools have a separate license, the GPL.

Another directory, "demo", contains a demo program of the sound engine with
mod player usage.

### Building/linking

This library is shipped "source-code only", that means you will have to build
it yourself in order to use it in your program.

A sample Makefile is given, that you will very probably have to change in
order to make it work. I used a custom GCC 3.2 (see "resources") for ARM
devices to build it myself.

Type "make standard" to build the sound system. If you also want to use the
lousy modplayer in your code, type "make mod_player" instead.

The functions contained in clarkmix.c and clarkmod.c are going to be put in
IWRAM, so they need to be compiled in ARM assembly (and NOT thumb).

When linking, be sure to have defined the  u32 IntrTable[14] somewhere into
your program, as well as enabling "multiple interrputs" from the crt0.s file.

To call the library functions from your program, simply add a
\#include "clarkmix.h" and #include "clarkmod.h" if you want to play mods.


### what functions to call and when to call them

Before calling any function, the sound system needs to be initialized. At, say,
the very beginning of your code, you will have to call :

`InitSystem();`

And that is *all* ! No need to synchronize with V-blank or stuff like that, the
player manages everything itself.

To play a given sample, call :

```
playSample(sample_start, sample_end, loop_start, loop_end, volume, panning,
           bank, pitch).
```

sample_start, sample_end, loop_start, loop_end are pointers to where the sample
you want to play resides in memory. If you do NOT want a sample to loop, use
DONT_LOOP (or 0xFFFFFFFF) as loop_end.

Volume goes from 0 to 255. Volume=0 means you won't hear the sample very much.

Panning goes from -128 to 127. -128 is full-left, 127 is fullright.

Bank is the playing channel where the sample should be put. A given bank can
play one and only one sample - if you use a bank already playing to play a new
sample, the old one will be replaced. This value goes from 0 to 3 by default.

Pitch is a 8.8 fixed-point number, which is an incremental counter for sample
playing. 0x100 will play the sample at 1:1 rate, while 0x200 will play it at
2:1 rate, and 0x80 will play it at 1:2 rate.

You can modify volume, panning, or pitch of a sample currently playing, by
using :

```
setVolume(volume, bank);
setPanning(panning, bank);
setPitch(pitch, bank);
```

If you want to stop a sample from looping, you can call :
`stopSample(bank);`

If you included the lousy modplayer in the project, you can also call the
following functions :

```
playMod(module);
stopMod();
```

playMod will start playing a module, as defined later on, and stopMod will
stop it. Please not a module is always played in the first banks - for example
a 3-voice module will use banks 0-2.

All those functions return (almost) immediately.

### Advice for sound freaks

You will notice that samples are played at a very good sound level. That is,
in fact, because a sample is not reduced before being added to the others.

For example, if you play 1 sample that reaches 127 or -128, the output will be
127 and -128, given the volume is 100% of course.

But if you play 4 samples at the same time that reach 127 or -128, you will
hear some funny noises - samples added overflow and the wave is totally
screwed up.

I chose not to implement clipping for that. If you are going to play two very
loud samples at the same time, consider lowering the volume of the currently
playing ones using the setVolume() function.

If you want to change the mixing rate of the mixer, you will have to modify
some stuff in clarkmix.c file (see later). Do not forget that the modplaying
function, if you use it, uses a "speed ratio" based on the mixing rate, so if
a given mod starts to sound strange, you will have to lower its tempo or
something like that.

Changing the maximal number of mixing channels is also a matter of modifying
a #define in the clarkmix file.


### Useful tools

Two tools are provided with this library. The tools are under GPL, but their
output is not - even if they actually create source code.

In the [tools/](tools) subdirectory, you have two programs : wave2c and freqgen.

Freqgen is a frequency generator program that creates notes usable in mod
files. It permitted to create the clarkfreqs.h file, and has no other purpose.

Call it this way :
`./freqgen my_output.h`

Wav2c is a more interesting tool : it transforms legacy .WAV files into C
source. It can take as input either 8-bit mono WAV, 16-bit mono WAV,
8-bit stereo WAV or 16-bit stereo WAV. As an output it creates a C file with
the following data structure :

```
(u32) <soundname>_sampleRate=X; // the default sample rate
(32) <soundname>_length=Y;      // the length of the sound
(s8) <soundname>_data[]=...     // data of a monaural sound
```
or
```
(s8) <soundname>_dataL[]=...
(s8) <soundname>_dataR[]=...    // data of a stereo sound
```

Please notice this tool doesn't resample sound to the mixer frequency. It
doesn't also work with "sndrec" wav files, that have a weird header.

And it depends on the endianness of the machine... It will generate correctly
the sound on little-endian systems (like IBM-PCs), but is not likely to work
on big-endian systems (like MACs).

Call the program this way :

`./wav2c file.wav <sourcename.c> <soundname>`

2022 note: this tool has been improved by other contributors. I couldn't track
all of the versions but there is at least another one [on GitHub here](https://github.com/olleolleolle/wav2c).

### The demo

A demo is provided to show how the modplayer works. It is a small, multiboot
demo, which runs very well on the Game Boy Advance - seems to go fine on an
emulator, too.

To build the demo, go into the "demo" subdirectory and type "make". You
might have to modify the makefile a bit to get it to compile - locations of
tools and so on, you know...

You will end up with a main.bin file. This is the demo file. Load it using
a MBV2 cable, and enjoy (well, I know, it's a pretty lame demo).


## Reference manual


### Resource usage

Well, as it is for now, the Clarkinou Sound System alone takes around 5 KB of
IWRAM, including sound buffers. Adding the modplayer will increase the memory
usage by around 1 KB.

It uses two timers, timer 0 and timer 1. Timer 0 is used for the data
transfers from the buffers to the FIFOs A and B, and timer 1 is hooked to the
buffer-switching and filling procedure.

It also uses DSound output A and B (but leaves alone the 4 GBC sound channels),
as well as DMA1 and 2. DMA3 is NOT used in the mixer, so you can use it safely
outside - but don't mess with DMA1 and 2.

My CPU usage measure is not really accurate, but when playing 4 samples at a
time the modplayer can use up to 25% of CPU time. When not playing it is
around 1/2% usage I guess. Yep, it is not optimized.


### Functions inner workings

clarkmix.c contains the following :

```
void switchBuffers(void); // a basic buffer-switching function, called by the
                          // timer1 interrupt function.

void mixBuffers(void); // the mixer function. Clears the buffer, then adds up
                       // samples values inside. If the library was compiled
                       // with module support, it also calls the mixMod()
                       // function. It is called by the timer1 interrupt
                       // function.

void InterruptProcess(void); // timer 1 interrupt function. Resets DMA,
                             // switches samples, mixes buffers, and returns.

void playSample(u32 data_begin, u32 data_end,   // plays a new sample.
                u32 loop_begin, u32 loop_end,   // updates the corresponding
                u8 volume, s8 panning, u8 bank, // sample bank and performs
                u16 pitch);                     // basic computations to
                                                // compute the stereo volumes.

void stopSample(u8 bank); // cancels loop

void setVolume(u8 volume, u8 bank); // sets volume, performs basic calculation

void setPanning(s8 panning, u8 bank); // sets panning, same remark

void setPitch(u16 pitch, u8 bank); // sets pitch.

void InitSystem(void); // initilizes the buffers, turns on the sound chip and
                       // off the 4 GBC channels, then initializes DMA and
                       // dsound_output register. Sets up the timers and
                       // interrupts, too.
```

Interesting things to remark :

* the code uses intensively right shifts (for example "/ 256" is ">>8") to replace slow-like-hell divisions.
* volume computation algorithm :

    A given sample bank has 2 "volumes" attached to it, one for left speaker, and
    one for right speaker. Those volumes are computed whence a new sample is played
    or when setVolume or setPanning are called. Volume is a 8-bit value from 0
    to 255, panning is a 6-bit value from -128 to 127. 

    ```
        volume_left  = ((128 - panning) * volume) / 256;
        volume_right = ((128 + panning) * volume) / 256;
    ```

Well, this is a method I found after playing around, and it seems to work...

* buffer mixing algorithm :

    The algorithm itself is really straightforward : for each sample currently
    played, the sample values are to be copied into the buffer. First the integer
    part of the fixed point sample offset is added to the pinter to the beginning
    of sample, then the value pointed by the result is added to the buffer (with
    respect to its volume), and finally the offset is updated using the sample
    pitch.

    Simple, simple, simple.

    ```
        for each sample in bank do
           for i = 0 to buffer_size do
              currentpointer = sample.databegin + sample.offset / 256;
              buffer_left[i] += *currentpointer * sample.volume_left / 256;
              buffer_right[i] += *currentpointer * sample.volume_right / 256;
              sample.offset += sample.pitch;
           done
        done
    ```

clarkmod.c contains the following functions :

```
void mixMod(); // is the main mod mixing function, called by mixBuffers() if
               // you included module support.
               // uses a 0.32 floating-point "tempo" which is a fraction of
               // the buffer-switching rate.

void playMod(modData *d); // starts playing a new mod structure.

void stopMod(); // stops playing the mod.
```

### Data structures

The mixer uses internal data structures, that the user shouldn't need to use
himself. However the programmer will be glad knowing about them.

In clarkmix.c, the structure sample is defined :

```
struct sample {
    u32 data_begin;
    u32 data_end;
    u32 loop_begin;
    u32 loop_end;
    u8 volume_a;     // internal use
    u8 volume_b;     // internal use
    u8 volume;
    s8 panning;
    u8 in_loop;      // >0 if in loop
    u16 pitch;       // used for FP 8.8 calculations. 0x100 is 1.
    u32 data_offset; // used for fixed-point 24.8 calculations.
};
```

On the other hand, the modplayer uses data structures that the user should
know about (as he, or she, has to code music). Those are defined in the
clarkmod.h file :

```
// this is the basic "sample" structure used by the mixer, used to define
// an array of samples used by the current module.
typedef struct {
        u32 data_begin, data_length, loop_begin, loop_length;
} samplElem;

// this is a given element of a pattern. For a 4-channel module, 4 elements of
// those will be used for a single "tempo tick".
typedef struct {
        u8 FX;     // the effect to perform.
        u8 index;  // the sample index in the array described below
        u8 volume; s8 panning;
        u16 pitch;
} patElem;

// This last structure is the module itself. It contains pointers to arrays
// of samples and pattern elements.
typedef struct {
        u32 tempo;    // tempo --> FFFFFFFF=1/1 speed, 1 = 1/FFFFFFFF speed.
        u8 repeat;      // repeat after end ?
        u8 chanNum;     // number of channels (4 max)
        u8 sampNum;     // number of samples in sample array (255max).
        u32 patNum;     // number of pattern elements (counts ALL).
        const samplElem *sAr; // array with references to modules.
        const patElem *pAr;       // array with what to actually play.
} modData;
```

### \#define stuff


For compilation purposes or just to facilitate the life of the programmer, the
files contains also quite a lot of constants encoded by #define.

clarkmix.h contains #define DONT_LOOP 0xFFFFFFFF , which should
be used as loop values if a given sample should not loop.

clarkmix.c contains the following :

```
#define BUFFER_SIZE 640    // 1/25 sec buffer.
#define PLAYER_FREQ 0xFBFF // 16khz play back freq
#define SAMPLES_MIX  4     // the number of samples mixed at the same time.
```

You can modify those to suit your needs.

The value for PLAYER_FREQ is computed like this :

`PLAYER_FREQ= 0xFFFF - 16777216/frequency ;`

where 16777216 is the GBA CPU's frequency. The buffer size should be also
computed the same way with this formula :

`BUFFER_SIZE = frequency * 1 / 25;`

Where 1/25 is the fraction of second stored in the buffer. Note the lower this
fraction, the smaller the buffer, but under certain values sound artifacts
can occur (I don't really know why).


clarkmod.h contains the following :

```
#define REPEAT_TRUE 0xFF
#define REPEAT_FALSE 0x0
```

Those are used for defining whether a "mod" data should be repeated when the
end is reached, or not.

The modplayer "effects" are defined as a bitfield like this :

```
#define FX_NOP      0
#define FX_CHVOL    1
#define FX_CHPAN    2
#define FX_CHPITCH  4
#define FX_CHSAMPLE 8
```

Thus it is possible to do several effects at the same time, for example
changing pan and pitch.


clarkmod.c contains the following :

```
#define PLAY_SAMPLE(sa,pat,ba) playSample(sa.data_begin,sa.data_begin+\
                                          sa.data_length,sa.loop_begin,\
                                          sa.loop_begin+sa.loop_length,\
                                          pat.volume,pat.panning,ba,\
                                          pat.pitch)
```

which is a helper function to play a sample.


### Global variables

The modplayer contains some global variables.

clarkmix.c defines several of them :

```
// the 4 buffers, for DSound A and DSound B
s8 fifoAbuf0[BUFFER_SIZE];
s8 fifoAbuf1[BUFFER_SIZE];
s8 fifoBbuf0[BUFFER_SIZE];
s8 fifoBbuf1[BUFFER_SIZE];

// pointers to those buffers
// the ones used by the DMA
s8* curBufA;
s8* curBufB;
// the ones in which we mix sound
s8* mixBufA;
s8* mixBufB;

// the sample banks
struct sample toMix[SAMPLES_MIX];

// if 0, use buffers1 as DMA buffers, else use buffers0.
u16 bufferSwitch;
```

clarkmod.c defines also some internal, global values.

```
// the pattern counter, points to the current pattern to play
u32 patCounter;
// the tempo counter, new note is played on overflow.
u32 tempoCounter;

// pointer to the currently playing mod - if NULL nothing is played.
modData* curMod;
```

## Acknowledgements and greetings

This project wouldn't have been possible without help, and I got help from
several sources. First I'd like to thank Chris Strickland, as it is with his
article that all started. Thanks to Tom Happ too, as I used the Cowbite
specification very often ; thanks to the guys of BeLogic too - very useful
doc, one more time.

Special greetings to Clarkinou, the person which is unknowingly at the origin of
the project. This sound system is kind of his birthday present - or more likely
an apology for having forgotten his birthday ;).


## Resources

I used information and resources from several websites to build up this project.

If those links do not work anymore (well it's been 19 years after all), you may get some luck trying to find
them in Archive.org.

Game Boy Advance Sound programming info :
[http://www.gamedev.net/reference/articles/article1823.asp](http://www.gamedev.net/reference/articles/article1823.asp)
   (good intro on sound programming)
[http://www.belogic.com/gba/](http://www.belogic.com/gba/)
   (everything you ever wanted to know about sound registers)

General Game Boy Advance programming info and tools :
[http://www.cs.rit.edu/~tjh8300/CowBite/CowBiteSpec.htm](http://www.cs.rit.edu/~tjh8300/CowBite/CowBiteSpec.htm)
   (GBA unofficial specification sheet, very complete)
[http://didaho1.free.fr/cross/](http://www.cs.rit.edu/~tjh8300/CowBite/CowBiteSpec.htm)
   (80x86 -> ARM7TDMI GCC 3.2 cross-compiler working on debian linux)

Other resources of interest :
[http://ccrma-www.stanford.edu/CCRMA/Courses/422/projects/WaveFormat/](http://ccrma-www.stanford.edu/CCRMA/Courses/422/projects/WaveFormat/)
   (a good explanation of MS-WAV legacy file format)
[http://oxygen.it.net.au/mixing/](http://oxygen.it.net.au/mixing/)
   (digital mixing techniques, a very good tutorial)

