#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
using namespace std;



void printWord(char word[], char underScores[])
{
	int wordLength; 
	wordLength = strlen(word); // Problem with length?
	cout << "WORD: ";
	for(int count = 0; count < wordLength; count++)
	{
			cout << underScores[count] << " ";
	}		
}

void printStage(int stage)
{

	switch(stage)
	{
		case 0:
		{
			cout << "							\n";
			cout << "		+---------+ 		\n";
			cout << "	 	|	  |				\n";
			cout << "		|					\n";
			cout << "		|					\n";
			cout << "		|					\n";
			cout << "		|					\n";
			cout << "		|					\n";
			cout << "		|					\n";
			cout << "	---------------------	\n";
		}
		case 1:
		{
			if(stage == 1)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	 |				\n";
				cout << "		|	 |				\n";
				cout << "		|	 O				\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "	--------------------	\n";
			}
		}
		
		case 2:
		{
			if(stage == 2)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|	  O				\n";
				cout << "		|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "	--------------------	\n";
			}
		
		}
		
		case 3:
		{
			if(stage == 3)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|	  O				\n";
				cout << "		|	  |\\			\n";
				cout << "		|	  |				\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "	--------------------	\n";
			}

		}
		
		case 4:
		{
			if(stage == 4)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|	  O				\n";
				cout << "		|	 /|\\			\n";
				cout << "		|	  |				\n";
				cout << "		|					\n";
				cout << "		|					\n";
				cout << "	--------------------	\n";
			}

		}
		
		case 5:
		{
			if(stage == 5)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|	  O				\n";
				cout << "		|	 /|\\			\n";
				cout << "		|	  |				\n";
				cout << "		|	   \\			\n";
				cout << "		|					\n";
				cout << "	--------------------	\n";	
			}

		}
		
		case 6:
		{
			if(stage == 6)
			{
				cout << "							\n";
				cout << "		+---------+ 		\n";
				cout << "	 	|	  |				\n";
				cout << "		|	  |				\n";
				cout << "		|	  O				\n";
				cout << "		|	 /|\\			\n";
				cout << "		|	  |				\n";
				cout << "		|	 / \\			\n";
				cout << "		|  	DEAD!			\n";
				cout << "	--------------------	\n";
			}

		}
	}	
}

void printLettersGuessed(bool userGuesses[], char alphabet[])
{
	
	cout << "LETTERS YOU HAVE ALREADY GUESSED: "; 
		
	for(int x=0; x<= 25; x++)
	{
		if(userGuesses[x] == true)
		{
			cout << alphabet[x];
		}
	}
}