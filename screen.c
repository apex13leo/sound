//contains screen manipulation function, such as clearScreen(), gotoxy(), setColor(), etc
#include "screen.h"
#include <stdio.h>

/*
	Function definition of setColor()
	This function will use VT100 escape sequence "\ESC[1;m" to define colors of elements
	input argument: none
	return argument: none
*/

void setColor(int color){
	printf("%c[1;%dm",ESC, color);
	fflush(stdout);
}

/*
	Function definition of clearScreen()
	This function will use VT100 escape sequence "\ESC[2J" to erase the total terminal screen
	input argument: none
	return argument: none
*/

void clearScreen(void){
	printf("%c[2J", ESC);
	fflush(stdout);
}

/*
	Function definition of gotoxy()
	This function uses VT100 escape sequence "\ESC[row;coIH" to set the cyrsor to the
	specific location of the terminal screen
	input argument:
		int row: row number (1 is top)
		int col_ col number (1 is left)
	return argument: none
*/

void gotoxy(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
	fflush(stdout);

}

/*
	Function definition of bar()
	Displays 80 lines of sound data in dB.
	Sound level is defined by colors. From green (least noise) to red (most noise).
	Includes screen postioning.
*/

void bar(int col, double dB){
	int i;
	for(i=0; i<dB/RES; i++){
		gotoxy(35-i, col+1);	//the first bar start from col=1
#ifndef UNICODE		//if not defined
		printf("%c", '*');
#else
		if(i<30/RES)setColor(GREEN);
		else if(i<60/RES)setColor(YELLOW);
		else setColor(RED);
		printf("%s", BAR);
#endif
	}
	setColor(GREEN);
	gotoxy(37, 1);
}


