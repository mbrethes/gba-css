/* wave2c, a WAV file to GBA C source converter.
 * Copyright (c) 2003 by Mathieu Brethes.
 *
 * Contact : thieumsweb@free.fr
 * Website : http://thieumsweb.free.fr/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "wavdata.h"

int main(int argc, char **argv) {
	wavSound*s;
	FILE *fin;
	FILE *fout;

	if (argc != 4) {
		printf("Usage : %s <file.wav> <output.c> <soundname>\n", argv[0]);
		exit(0);
	}

	fin = fopen(argv[1], "r");

	s = loadWaveHeader(fin);

	if (s == NULL) {
		printf("Invalid wave !\n");
		exit(0);
	}

	fout = fopen(argv[2], "w");

	saveWave(fin, s, fout, argv[3]);

	return 0;	
}
