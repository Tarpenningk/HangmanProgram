/*
	
	File Name:	
	Author:		Kalynn Tarpenning
	Major:		Computer Science
	Date:		
	Purpose:	

*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include"hangman.h"
using namespace std;

int main ()
{
	//Array Variables
	char word[21]; // Holds word from Word Bank
	char underScores[21];
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool userGuesses[26];
	
	//Other Variables
	int count; 
	int stage;
	int wordLength;
	
	char letter;
	char response;
	char enter;
	
	bool again;
	bool alreadyGuessed;
	bool wordGuessed;
	bool correct = false;
	
	ifstream wordBank;
	
	//Opening File Outside of do-while loop
	wordBank.open("wordBank.txt");
	
	if(!wordBank)
	{
		cout << "ERROR: File not found." << endl;
	}
	
	do
	{
		//Sets all of userGuesses to false
		for(count = 0; count < 26; count++)
		{
			userGuesses[count] = false; 
		}
		
		
		//Changes all of underScores elements to _
		for(count = 0; count < 21; count++)
		{
			underScores[count] = '_'; 
		}
		
		
		//Setting stage to zero
		stage = 0;
		
		
		//Pulls a word from the .txt file
		wordBank >> word;
		
		
		while(stage!=6)
		{
			//Calls function to show how many letters are in the word
			printWord(word, underScores);
			
			//Shows how close to dead you are
			printStage(stage);	
			
			//Replaces _ with correctly guessed letters
			printLettersGuessed(userGuesses, alphabet);

			cout << "\n\nWHAT LETTER DO YOU GUESS? ";
			cin >> letter;
			
			//Presses enter to continue
			cin.ignore();
			cin.get();
			
			letter = toupper(letter); //the toupper function will make letter uppercase.
			
			
			//Checks if letter is in the word
			correct = false;
			for(count=0; count<21; count++)
			{
				if(letter == word[count])
				{
					underScores[count] = word[count];
					correct = true;
					
				}
			
			}
		
			
			// Checking if letter has been guessed
			do 
			{
				for(count=0; count<26; count++) 
				{ 
					if(letter == alphabet[count]) 
					{ 
						if(userGuesses[count] == true) 
						{ 
							alreadyGuessed = true; 
							cout << "OOPS! YOU HAVE ALREADY GUESSED THAT LETTER!\n"; 
							
							cout << "\n\nWHAT LETTER DO YOU GUESS? ";
							cin >> letter; 
							letter = toupper(letter);
						}
						else
						{
							alreadyGuessed = false;
						}
							
					} 
				}
				
			}while(alreadyGuessed == true);
			
			// Changes letter to true so it can't be guessed again
			for(count=0; count<26; count++)
			{
				if(letter == alphabet[count])
				{
					userGuesses[count] = true;
				}
				
			}
			

			// Prints either Correct or Wrong to screen 
			if(correct == true)
			{
				cout << "CORRECT!" << endl;
				
				cout << "Press Enter to Continue." << endl;
				
				while(cin.get() != '\n')
				{
					cout << "Press Enter to Continue." << endl;
				}

				
			}

			else 
			{
				stage++;
				cout << "WRONG!" << endl;
				
				cout << "Press Enter to Continue." << endl;
				
				while(cin.get() != '\n')
				{
					cout << "Press Enter to Continue." << endl;
				}

			}
			
			
			//Dead!
			if (stage == 6)
			{
				printStage(stage);
			}
			
			//Checks if word is complete
			wordLength = strlen(word);
			if(strncmp(word, underScores, wordLength) == 0) 
			{ 
				wordGuessed = true; 
				cout << "YES! THE WORD WAS: " << word << endl;
				cout << setfill('>') << setw(35) << ">" << " YOU WIN! " << setw(35)<< ">" << "\n\n"; 

				break;
			}
			
			

		}
		

		
		//Asks User if they want to go again.
		cout << "\nWould you like to go again? Press y or n" << endl;
		cin >> response;
		response = toupper(response);
		if(response == 'N')
		{
			again = false;		
		}
		else if(response == 'Y')
		{
			again = true;
		}		

	}while(again == true);
	
	wordBank.close();
	
	return 0;
}

/*void printWord(char word[], char underScores[])
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
}*/