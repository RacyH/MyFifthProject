/*Racy Halterman
C++ Fall 2020
Due: November 2nd
Lab 5: Number Guessing Game
: Write a number-guessing game in which the computer selects a random number in the range of 0 to 100,
and users get a maximum of 20 attempts to guess it.
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h> //Including the necessary libraries, and a couple of extras, just in case

using namespace std;
using std::cout; // I used cout too many times, and they all started popping up as errors. I looked it up, and this was the solution for that.

void welcome();
void game(int& w, int& l);
void success();
void failure();
void again();
void score(int& w, int& l);

int main() /* A random note. I could have put every single part of this into a function, and called it something else, but this allowed for me to 
		   see more easily what was happening in my code, and edit it if need be.*/
{
	welcome(); //Welcome statement

	int c = 1, s = 0, f = 0; /*Set the value of c to 1 so that the while statement would allow them to choose whether they wanted to play again or not. s and f are 0
	so that the scores start, at the beginning of the game, as 0.*/

	while (c == 1)
	{
		game(s, f); //Used s and f here so that the scores would change throughout the game
		again(); //The statement that asks if the player wants to play again.
		cin >> c; //The input to change c to a number, which if it is not 1, will kick them from the game.
	}
	score(s, f); //Outputs the number of wins and the number of losses, based on their in-game performance.
	
return 0;
}

void welcome()
{ //Simple welcome to the game statements.
	cout << "Welcome to a number guessing game!\n" << "You have 20 guesses. The range of the number you are guessing is between 1 and 100.\n";
	cout << "You will be able to restart the game once you have finished the 20 guesses, or you have guessed the correct number.\n";
	cout << "Warning! Only input numbers.Incorrect inputs will count as a guess.\n";
	cout << "Every game has a different number, so don't try counting up from 1, you only have 20 guesses per number.\n";
}

void game(int& w, int& l) //The w and l are there to keep score. I used the reference paramater so the score would keep as long as the code was open.
{
	srand(time(NULL)); //Random seed generator
	int x = rand() % 100 + 1, i = 0, ran; //Random number generator, range 1 to 100. The i keeps the number of guesses.
	//cout << x; //For debugging purposes only. Will not show up in final output
	do
	{
		cout << "Your guess: ";
		cin >> ran; //Input the number
		cout << '\n';
		if (cin.fail()) //This checks to see if the input failed or not. If it did, then it will make this if statement operate.
		{
			cin.clear(); /*This clears the cin so that you can continue the program without it failing. It also makes the first if statement not true, but technically
it makes the second one true, so each wrong-input guess counts as a wrong answer.*/
			cin.ignore(100, '\n'); // it will ignore 100 characters or get to the end of the line.
		}
			 if (ran == x) //Whenever you guess correctly, this if statement becomes true, and the following are done.
			{
				success();
				w++; //Keeps score of the times you won.
			}
			 else if (!(ran == x)) //Incorrect guesses.
			{
				failure();
				i++; //Counts up for the number of guesses.
				cout << "You have " << 20 - i << " guesses left.\n"; //Outputs guesses left
			}
		if (i == 20)
		{
			l++; //Whenever you guess too many times, you get a loss tallied on to your score.
		}
	} while (ran != x && i < 20); //Makes it so that it quits running through if you guess correctly, or if your number of guesses has reached 20.
}

void success()
{
	srand(time(NULL));
	int s = rand() % 10 + 1; //Another random number generator that makes it choose a number at random
	switch (s) //With the help fo the random number generator, this switch statement allows for a random statement to be chosen.
	{
	case 1: //Whenever s == 1, this statement comes out.
		cout << "You did it! Congratulations!\n\n";
		break;
	case 2:
		cout << "Wow! Way to go!\n\n";
		break;
	case 3:
		cout << "You win!\n\n";
		break;
	case 4:
		cout << "I would give you a gold star if I had hands. You win!\n\n";
		break;
	case 5:
		cout << "You're amazing!\n\n";
		break;
	case 6:
		cout << "That was fantastic!\n\n";
		break;
	case 7:
		cout << "Incredible!\n\n";
		break;
	case 8:
		cout << "That's the way to be!\n\n";
		break;
	case 9:
		cout << "I wish I was you. 'Cause then I would be a winner!\n\n";
		break;
	case 10:
		cout << "How did you do that so well?\n\n";
		break;
	default: cout << "Error";
	}
}

void failure()
{ //Practically the same reasoning and logic for this code, but allows for failure statements to be chosen at random.
	srand(time(NULL));
	int f = rand() % 10 + 1;

	switch (f)
	{
	case 1:
		cout << "How did you do that? Suck so bad, I mean.\n\n";
		break;
	case 2:
		cout << "There is no way that someone can have such a lack of skill.\n\n";
		break;
	case 3:
		cout << "If there were two things left on earth, you and a coconut, you would be the dumbest thing on earth.\n\n";
		break;
	case 4:
		cout << "Wow.. Can you even tie your own shoes?\n\n";
		break;
	case 5:
		cout << "That was quite a fail.\n\n";
		break;
	case 6:
		cout << "Nope.\n\n";
		break;
	case 7:
		cout << "That was not the correct number.\n\n";
		break;
	case 8:
		cout << "You gotta try again.\n\n";
		break;
	case 9:
		cout << "Please, try again.\n\n";
		break;
	case 10:
		cout << "Well, that didn't work.\n\n";
		break;
	default: cout << "Error";
	}
}

void again()
{ //Again, same logic, just different purpose. This one asks in a random way if the user would like to play again.
	srand(time(NULL));
	int a = rand() % 10 + 1;

	switch (a)
	{
	case 1:
		cout << "That's right, run away. Or are you gonna play again?\n\n";
		break;
	case 2:
		cout << "Do you want to keep playing?\n\n";
		break;
	case 3:
	cout << "There is still lots of time, if you want to play again.\n\n";
	break;
	case 4:
	cout << "There is no such things as too many games. Play again?\n\n";
	break;
	case 5:
	cout << "I would play again, if I were you. Keep playing?\n\n";
	break;
	case 6:
	cout << "No, no, no. Don't walk away. Play again?\n\n";
	break;
	case 7:
	cout << "You can't just quit on me. Let's play again?\n\n";
	break;
	case 8:
	cout << "I wouldn't quit on you, so why do you want to quit on me? Play some more?\n\n";
	break;
	case 9:
	cout << "Let's go. Just one more time?\n\n";
	break;
	case 10:
	cout << "Never quit. Never give up. Play again.\n\n";
	break;
	default: cout << "Error";
	}
	cout << "Press 1 to keep playing, 2 to quit.\n\n"; //This allows the user to choose whether they wanted to quit or continue playing
}

void score(int& w, int&l)
{ /*This is the code block that allows the score to be printed on the screen. I used the reference parameter so that the value of the integer would stay the same
	throughout the code*/
	cout << "You won " << w << " times.\n" << "You lost " << l << " times." << endl;
}
