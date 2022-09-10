/* A module (yes) */

#include <clarkmod.h>
#include <clarkfreqs.h>

extern const s8 trump_data[];
extern const s8 shake_data[];
extern const s8 hatclose_data[];
extern const s8 snr_data[];
extern const s8 kicker_data[];
#define trump_length 18008
#define shake_length 2224
#define hatclose_length 752
#define snr_length 7128
#define kicker_length 2768

// don't loop samples
const samplElem sAr[] = {
	{(u32)trump_data, trump_length, 0,0xFFFFFFFF},
	{(u32)shake_data, shake_length, 0,0xFFFFFFFF},
	{(u32)hatclose_data, hatclose_length, 0,0xFFFFFFFF},
	{(u32)snr_data, snr_length, 0, 0xFFFFFFFF},
	{(u32)kicker_data, kicker_length, 0, 0xFFFFFFFF}
};

/* our mod is ... */
const patElem pAr[] = {
	{FX_CHSAMPLE, 0, 5, -64, C2},
	{FX_CHSAMPLE, 0, 5, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 10, -64, C3},
	{FX_CHSAMPLE, 0, 10, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 15, -64, C3},
	{FX_CHSAMPLE, 0, 15, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 20, -64, C3},
	{FX_CHSAMPLE, 0, 20, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 25, -64, B3},
	{FX_CHSAMPLE, 0, 25, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 30, -64, B3},
	{FX_CHSAMPLE, 0, 30, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 35, -64, C3},
	{FX_CHSAMPLE, 0, 35, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 40, -64, C3},
	{FX_CHSAMPLE, 0, 40, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 45, -64, C3},
	{FX_CHSAMPLE, 0, 45, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 50, -64, C3},
	{FX_CHSAMPLE, 0, 50, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 55, -64, B3},
	{FX_CHSAMPLE, 0, 55, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 60, -64, B3},
	{FX_CHSAMPLE, 0, 60, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 65, -64, C3},
	{FX_CHSAMPLE, 0, 65, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 70, -64, C3},
	{FX_CHSAMPLE, 0, 70, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 75, -64, C3},
	{FX_CHSAMPLE, 0, 75, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 80, -64, C3},
	{FX_CHSAMPLE, 0, 80, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 85, -64, B3},
	{FX_CHSAMPLE, 0, 85, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 90, -64, B3},
	{FX_CHSAMPLE, 0, 90, 63, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 95, -64, C3},
	{FX_CHSAMPLE, 0, 95, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 100, -64, C3},
	{FX_CHSAMPLE, 0, 100, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 105, -64, C3},
	{FX_CHSAMPLE, 0, 105, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 110, -64, C3},
	{FX_CHSAMPLE, 0, 110, 63, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, 0, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 115, -64, B3},
	{FX_CHSAMPLE, 0, 115, 63, D3},
	{FX_CHSAMPLE, 2, 255, 0, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, 0, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 120, -64, B3},
	{FX_CHSAMPLE, 0, 120, 63, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* part 2 */

	{FX_CHSAMPLE, 0, 127, -58, C3},
	{FX_CHSAMPLE, 0, 127, 57, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -52, C3},
	{FX_CHSAMPLE, 0, 127, 51, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -46, C3},
	{FX_CHSAMPLE, 0, 127, 45, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -40, C3},
	{FX_CHSAMPLE, 0, 127, 39, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -34, B3},
	{FX_CHSAMPLE, 0, 127, 33, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -28, B3},
	{FX_CHSAMPLE, 0, 127, 27, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, -22, C3},
	{FX_CHSAMPLE, 0, 127, 21, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -16, C3},
	{FX_CHSAMPLE, 0, 127, 15, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -10, C3},
	{FX_CHSAMPLE, 0, 127, 9, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -4, C3},
	{FX_CHSAMPLE, 0, 127, 3, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 2, B3},
	{FX_CHSAMPLE, 0, 127, -3, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, -8, B3},
	{FX_CHSAMPLE, 0, 127, -9, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, -14, C3},
	{FX_CHSAMPLE, 0, 127, -15, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 20, C3},
	{FX_CHSAMPLE, 0, 127, -21, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 26, C3},
	{FX_CHSAMPLE, 0, 127, -27, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 32, C3},
	{FX_CHSAMPLE, 0, 127, -33, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 38, B3},
	{FX_CHSAMPLE, 0, 127, -39, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 44, B3},
	{FX_CHSAMPLE, 0, 127, -45, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 50, C3},
	{FX_CHSAMPLE, 0, 127, -51, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 56, C3},
	{FX_CHSAMPLE, 0, 127, -57, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 62, C3},
	{FX_CHSAMPLE, 0, 127, -63, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* part 3 */

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* part 3 bis */

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 100, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},	

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

/* part 4 */

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},



	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},



	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},



	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, C3},
	{FX_CHSAMPLE, 0, 127, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 127, 63, B3},
	{FX_CHSAMPLE, 0, 127, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* last part (outro !) */

	{FX_CHSAMPLE, 0, 120, 63, C3},
	{FX_CHSAMPLE, 0, 120, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 110, 63, C3},
	{FX_CHSAMPLE, 0, 110, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 100, 63, C3},
	{FX_CHSAMPLE, 0, 100, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 90, 63, C3},
	{FX_CHSAMPLE, 0, 90, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_CHSAMPLE, 0, 80, 63, B3},
	{FX_CHSAMPLE, 0, 80, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 70, 63, B3},
	{FX_CHSAMPLE, 0, 70, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_CHSAMPLE, 0, 60, 63, C3},
	{FX_CHSAMPLE, 0, 60, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 50, 63, C3},
	{FX_CHSAMPLE, 0, 50, -64, E3},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 40, 63, C3},
	{FX_CHSAMPLE, 0, 40, -64, E3},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 30, 63, C3},
	{FX_CHSAMPLE, 0, 30, -64, E3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_CHSAMPLE, 0, 20, 63, B3},
	{FX_CHSAMPLE, 0, 20, -64, D3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_CHSAMPLE, 0, 10, 63, B3},
	{FX_CHSAMPLE, 0, 10, -64, D3},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* outro 2 */

	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* outro 2 */

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_NOP, 0, 0, 0, 0},

/* outro 2 */

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 2, 255, -5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 4, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 1, 200, 5, A3},


	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, -20, A3},
	{FX_NOP, 0, 0, 0, 0},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 3, 255, 20, A3},
	{FX_CHSAMPLE, 1, 200, 5, A2},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 1, 200, 5, A3},

	{FX_NOP, 0, 0, 0, 0},
	{FX_NOP, 0, 0, 0, 0},
	{FX_CHSAMPLE, 2, 255, -5, A3},
	{FX_CHSAMPLE, 3, 255, -20, A3}

};



const modData theMod = {
	0x40000000, REPEAT_FALSE, 4, 5, 1024, sAr, pAr };
