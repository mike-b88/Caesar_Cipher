// Caesar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Creat a C++ program that implements the Caesar Cipher on all
// ASCII values

#include <iostream>
#include <string>
/*
Problem: User needs to encipher plaintext messages into
Caeser Cipher encrypted messages

**Analyze the problem


**Design the steps, or algorithm to complete this program:

User inputs characters, for now just alphabit, after this gets
working implement use of all ASCII characters.

Develop a way to wrap around for the letters X,Y,Z and x,y,z

Allow use of spaces, do not shift spaces for now

Varibles:
May need some loops to go through the input string:

size of string for loop increment control variable

string variable to store the input string

char variable to output the cipher character




*/


//Code here after algorithm and problem analysis is worked out

using namespace std;

int sizeOfStrg;
char ctUpper, ctLower;        //ciphered character
string input;   //User input string
int cipherUpperVal, cipherLowerVal; //ASCII Value of cipher
int ptVal;      //Plain text ASCII value, UpperCase
int ptValLow;   //Plain text ASCII value, LowerCase
int ptInt;      //Plain text ASCII value for subtraction of upper and lower case ASCII values to determine position 
int modVal;
int j, g;			// control for print out of wrapped around characters


int main()
{
	cout << "Greetings please input your plain text message, use either upper"
		<< " or lower case alphabetic characters:" << endl;

	//Loop to go start process on enciphering
	int k = 0;
	int s = 0;
	while (s <= 0)
	{
		getline(cin, input);
		cin.sync();               //Look up the meaning of this, as I have forgot, and the getline function
		sizeOfStrg = input.size(); // Look up how the period works, what is it called


								   // Create loop to cycle through input to look for invalid characters until code is extended

		for (int p = 0; input[p] != '\0'; p++ || k <= 0)
		{
			ptInt = int(input[p]);                  //stores current value of string 
			ptVal = ptInt - static_cast<int>('A');  //stores the postion of the current value, use to determine if in allowable range
			ptValLow = ptInt - static_cast<int>('a');

			//cout << "The ASCII VALUE IS: " << ptInt << endl;
			//cout << "THE position in the alhpabit is: " << ptVal << endl;

			if ((ptInt < 65 || (ptInt > 90 && ptInt < 96)
				|| ptInt > 122) && ptInt != 32 && k <= 0)
			{
				cout << "You can only input Letters" << endl;
				k++;
			}

			// End of checker, past this point the program begins shifted values three spaces to the right

			if (0 <= ptVal && ptVal < 26)
			{
				j = 0;
				if (((ptVal + 3) % 25) > 0 && ptVal >= 22)
				{
					modVal = ((ptVal + 3) % 25);
					switch (modVal)
					{
					case 1: ctUpper = 'A';
						cout << " " << ctUpper;
					//	cout << " IS X WORKING " << endl;
						break;
					case 2: ctUpper = 'B';
						cout << " " << ctUpper;
				//		cout << " is Y working";				//Outputs an error character of '\'
						break;
					case 3: ctUpper = 'C';
						cout << " " << ctUpper;
				//		cout << " IS Z WORKING " << endl;
						break;
					default: break;

					}
					j++;
				}
				
				if (j <= 0) {
					cipherUpperVal = ptVal + 3;
					//	cout << " " << cipherUpperVal;
					cipherUpperVal = cipherUpperVal + 65;

					cout << " " << static_cast<char>(cipherUpperVal);
				}
			//	cout << endl;
			//	cout << "The modulis is: " << modVal << endl;
			}

			else if (0 <= ptValLow && ptValLow < 26)
			{
				g = 0;
				if (((ptValLow + 3) % 25) > 0 && ptValLow >= 22)
				{
					modVal = ((ptValLow + 3) % 25);
					switch (modVal)
					{
					case 1: ctLower = 'a';
						cout << " " << ctLower;
					//	cout << " IS x WORKING " << endl;
						break;
					case 2: ctLower = 'b';
						cout << " " << ctLower;							//outputs an error character of '|'
					//	cout << " is y working";
						break;
					case 3: ctLower = 'c';
						cout << " " << ctLower;
					//	cout << " IS z WORKING " << endl;
						break;
					default: break;

					}
					g++;
				}
				if (g <= 0) {
					cipherLowerVal = ptValLow + 3;
					//	cout << " " << cipherLowerVal;
					cipherLowerVal = cipherLowerVal + 97;
					cout << " " << static_cast<char>(cipherLowerVal);

					//	cout << endl;
					//	cout << "The modulus is: " << modVal << endl;
				}
			}
		
		
		}
		s++;
	}
	cout << endl;
	cout << "Code works so far" << endl;
	s++;
	k++;

	return 0;
}
