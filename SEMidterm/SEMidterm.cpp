

#include <iostream>
#include <string>

int Menu(const char* prompt, int min, int max, const char* options);
int ReadInterger(const char* prompt, int min, int max);
std::string ReadChoice(std::string cAnswer, std::string wAnswer1, std::string wAnswer2, std::string wAnswer3, std::string question);


int main()
{
	bool select = true;
	while (select)
	{
		system("CLS");
		std::cout << "Welcome to my test! \nOnce you start, you will be getting a random question.\n(4 questions total available)\n";
		int sMenu = Menu("Choose numbers 1 or 2. \nGood luck.", 1, 2, "1.) Start \n2.) End\n");
		switch (sMenu)
		{
		case 1: //Start
			//Random number chosen 1-4
			srand((unsigned)time(0));
			int randomNumber;
			randomNumber = (rand() % 4) + 1;
			system("CLS");
			std::cout << "Please choose a, b, c or d.\n";
			if (randomNumber == 1) //Question 1
			{
				std::string quest1 = ReadChoice( "d", "a", "b", "c", "Which Metal Gear Solid game is my favorite?\na.) Metal Gear Solid \nb.) Metal Gear Solid 2: Sons of Liberty \nc.) Metal Gear Solid 3: Snake Eater \nd.) Metal Gear Solid 4: Guns of the Patriots");
				system("pause");
			}
			else if (randomNumber == 2) //Question 2
			{
				std::string quest2 = ReadChoice("a", "b", "c", "d", "Which is my favorite Cyberpunk or Cyberpunk-like entry?\na.) Ghost in the Shell \nb.) Akira \nc.) Battle Angel Alita \nd.) Neon Genesis Evangelion");
				system("pause");
			}
			else if (randomNumber == 3) //Question 3
			{
				std::string quest3 = ReadChoice("b", "a", "c", "d", "Which is my preferred console for gaming?\na.) Xbox\nb.) Playstation\nc.) Nintendo\nd.) PC\n");
				system("pause");
			}
			else if (randomNumber == 4) //Question 4
			{
				std::string quest4 = ReadChoice("d", "a", "b", "c", "Which is the best social media platform?\na.) Facebook\nb.) Twitter\nc.) Snapchat\nd.) None, social media is a plague\n");
				system("pause");
			}
			break;
			//Planned to do something with each particular answer but it's not a requirement, wish I had more time

		case 2: //End
			select = false;
			break;
		}
	}
}
std::string ReadChoice(std::string cAnswer, std::string wAnswer1, std::string wAnswer2, std::string wAnswer3, std::string question)
{
	std::cout << question << '\n';
	std::string input;
	do
	{
		std::cin >> input;
		if (input == cAnswer)
		{
			std::cout << "\nYou got it! \nYou sir or ma'am, have great taste!\n";
			return input;
			break;
		}
		else if (input == wAnswer1 || input == wAnswer2 || input == wAnswer3)
		{
			std::cout << "\nWrong... Well this is awkward.\n";
			return input;
			break;
		}
		else if (input != cAnswer || input != wAnswer1 || input != wAnswer2 || input != wAnswer3)
			std::cin.clear();
			std::cout << "Please try again. \n(HINT: TRY a, b, c, or d.\n";

	} while (true);
}
int Menu(const char* prompt, int min, int max, const char* options)
{
	std::cout << options;
	int selection = ReadInterger(prompt, min, max);
	return selection;
}
int ReadInterger(const char* prompt, int min, int max)
{
	std::cout << prompt << '\n';
	int input = 0;
	do
	{
		std::cin >> input;
		if (input >= min && input <= max)
		{
			return input;
		}
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Please try again. \n(HINT: ANY NUMBER BETWEEN " << min << " AND " << max << ".\n";
	} while (true);
}

