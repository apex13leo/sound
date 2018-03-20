#include "sound.h"
#include <stdio.h>
#include <math.h>

//function definition of displayBar()
//this function opens "test.wav" file and read the second part (data) of the file
//The samples should be in S16_LE format, and there are 16000 of them
//The function process every 200 samples and calculate their RMS value
//and render this value as a vertical bar on therminal screen

void displayBar(char filename[]){

	FILE *fp;
	short int samples[SAMPLERATE];
	double sum_200, rms_80[80], dB;
	int i, j;
	WAVheader myhdr;		//dummy header to skip over the reading from the file
	fp = fopen(filename, "r");
	if(fp == NULL){
		printf("ERROR opening the file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVheader), 1, fp);
	fread(&samples, sizeof(short), SAMPLERATE, fp);
	fclose(fp);

//all the samples of 1sec are read to the array samples[], we need to run a loop 80 times for 80
//bars on the screen, and each iteration of this loop will calculate a RMS valuer of  200 samples
	clearScreen();
	for(i=0; i<80; i++){
		for(j=0,sum_200=0.0; j<200; j++){
			sum_200 += samples[j+i*200]*samples[j+i*200];
		}
		rms_80[i] =sqrt(sum_200/200);
		dB = 20*log10(rms_80[i]);
//conditional compiling
#ifdef DEBUG
		printf("RMS[%d] = %10.4f = %10.4fdB\n", i, rms_80[i], dB);
		//in order to display sound value in a screen, we need to use decible
#else
		bar(i, dB);
#endif
	}	//end of for loop
}	//end of function

//function definition of displayWAVEheader()
void displayWAVheader(char filename[]){
	WAVheader myhdr;		//an instace of defined struct
	FILE *fp;
	fp = fopen(filename, "r");	//open the file for reading
	if(fp == NULL){		//if fopen is failed
		printf("ERROR of opening file!\n");
		return;
	}
	fread(&myhdr, sizeof(WAVheader), 1, fp);
	fclose(fp);
	printID(myhdr.chunkID);
	printf("Chunk size: %d\n", myhdr.chunkSize);
	printID(myhdr.format);
	printID(myhdr.subchunk1ID);
	printf("Subchunk 1 size: %d\n", myhdr.subchunk1Size);
	printf("Audio format: %d\n", myhdr.audioFormat);
	printf("Number of channels: %d\n", myhdr.numChannels);
	printf("Sample rate: %d\n", myhdr.sampleRate);
	printf("Byte rate: %d\n", myhdr.byteRate);
	printf("Block align: %d\n", myhdr.blockAlign);
	printf("Bits per sample: %d\n", myhdr.bitsPerSample);
	printID(myhdr.subchunk2ID);
	printf("Subchunk 2 size: %d\n", myhdr.subchunk2Size);
	//there are more fields to be displayed
}

void printID(char id[]){
	int i;
	for(i=0; i<4; i++)
		printf("%c", id[i]);

	printf("\n");
}
