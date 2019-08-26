/*

	File Names:	hangman.h, hangman.cpp, functions.cpp & wordBank.txt
	Author:		Kalynn Tarpenning
	Major:		Computer Science
	Date:		October 20, 2015
	Purpose:	Header file to be used with the other files for a hangman game program. 
	
*/

#ifndef _HANGMAN_H
#define _HANGMAN_H


/*  Now we include the headers we need */
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;

 
/*  Now we include all the function prototypes */
void printWord(char[], char[]);
void printStage(int);
void printLettersGuessed(bool[], char[]);



#endif