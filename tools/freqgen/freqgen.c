/* A Clarkinou Sound System frequency generation program.
 * Copyright (C) 2003 by Mathieu Brethes.
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

/* It returns a table of unsigned
 * short integers that represent the scale used in the program.
 * Standard european 12-tone scale is generated here.
 *
 * Idea coming from www.wikipedia.org/wiki/Mathematics_of_the_Western_music_scale
 *
 * The given note will have a relative pitch of 1 ; the lowest of 0.125 ;
 * the highest of 16.
 *
 * those are fixed-point numbers, usable by the Clarkinou Sound System.
 */

#include <stdio.h>
#include <math.h>

short int fptofix(double d) {
	double tmp;
	double i;
	short int mask=1;
	short int result=0;

	for (i = 15.0 ; i >= 0 && d >= 0 ; i--) {
		if ((d = (d - pow(2.0, i - 8.0))) >= 0) result |= (mask << (int)i);
		else d = d + pow(2.0, i - 8.0);
	}
	return result;
}	

int main(int argc, char **argv) {
	double curRatio;
	FILE *f;
	double i;
	char baseletter='A';
	char extletter=' ';
	int basenumber=0;

	if (argc != 2) {
		printf("Usage : %s file.h \n", argv[0]);
		return -1;
	}

	f = fopen(argv[1], "w");
	if (f == NULL) {
		fprintf(stderr, "IO error !\n");
		return -2;
	}

	fprintf(f, "/* generated with freqgen */\n\n");

	for (i = -36.0 ; i <= 72.0 ; i++) {
		curRatio = pow(2.0, i / 12.0);
		if (baseletter == 'A' || baseletter == 'C' || baseletter == 'D' || baseletter == 'F' || baseletter == 'G')
		{
			if (extletter != 'n') {
				fprintf(f, "#define %c%d 0x%0.4X\n", baseletter, basenumber, fptofix(curRatio));
				extletter = 'n';
			} else {
				fprintf(f, "#define %cp%d 0x%0.4X\n", baseletter, basenumber, fptofix(curRatio));
				extletter = ' ';
				baseletter ++;
			}
		} else {
			fprintf(f, "#define %c%d 0x%0.4X\n", baseletter, basenumber, fptofix(curRatio));
			baseletter++;
		}
		if (baseletter > 'G') {
			basenumber++;
			baseletter = 'A';
		}
	}

	fprintf(f, "};\n");
	fclose(f);
	return 0;
}
