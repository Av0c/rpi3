#include "wave.h" // "" are used for user defined header
#include <stdio.h>
#include <math.h>
#include <signal.h>
#include <sys/wait.h>
#include "screen.h"
#include <stdlib.h> //no warning when using c99 standard

#define PI acos(-1.0)

int main(int argc, char *argv[]) {
	FILE *fp;
	WAVHDR myhdr;
	int ans, ret;
	short int sa[SAMPLE_RATE];
	while (1) {
		ret=system("arecord -r16000 -c1 -d1 -f S16_LE -q data.wav");
		clearScreen();
		if (WIFSIGNALED(ret) && (WTERMSIG(ret)==SIGINT||WTERMSIG(ret)==SIGQUIT)) break;
		fp = fopen("data.wav", "r");
		fread(&myhdr, sizeof(myhdr), 1, fp);
		displayWAVHDR(myhdr);
		fread(&sa, sizeof(short int), SAMPLE_RATE, fp);
		displayWAVdata(sa);
		fclose(fp);
	}
}
