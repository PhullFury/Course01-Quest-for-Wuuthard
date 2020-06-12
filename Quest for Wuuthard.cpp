#include <iostream>
#include <ctime>

bool bGameState = true;

bool PlayGameAtDifficulty(int difficulty)
{
	//Code variables
	int CodeA = rand() % difficulty + difficulty;
	int CodeB = rand() % difficulty + difficulty ;
	int CodeC = rand() % difficulty + difficulty ;
	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	if (difficulty == 1)
	{
		std::cout << "\nYou walk down an empty coridor and find a strange door.\n";
		std::cout << "On the door there is a strange lock with three movable pieces.\n";
		std::cout << "Interestingly the pieces have numbers written on them.\n";
		std::cout << "Beneath the pieces something is written\n\n";
		std::cout << "* The code adds up to: " << CodeSum << "\n";
		std::cout << "* The code multiplys to give: " << CodeProduct << "\n\n";
	}
	else
	{
		std::cout << "\nYou move through the corridor and to get to the next door.\n";
		std::cout << "You look at the inscription\n\n";
		std::cout << "* The code adds up to: " << CodeSum << "\n";
		std::cout << "* The code multiplys to give: " << CodeProduct << "\n\n";

	}

	//Guess variables and user input
	int GuessA, GuessB, GuessC;
	std::cout << "What numbers do you want the pieces to display: ";
	std::cin >> GuessA >> GuessB >> GuessC;
	std::cout << "\n\n";
	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "You arrange the pieces and the door rumbles.\n";
		std::cout << "It drops into the ground giving you access to the next corridor.\n";
		bGameState = true;
		return true;
	}
	else
	{
		std::cout << "You arrange the pieces and the door rumbles but nothing happens.\n";
		std::cout << "You look around and see the Draugars coming out of their tombs.\n";
		std::cout << "They move toward you and despite your feeble attempt you are killed by the Draugars.\n";
		std::cout << "Your name is added in the giant list of Draugar victims.\n\n";
		std::cout << "You lost.\n";
		std::cout << "The answer was " << CodeA << " " << CodeB << " " << CodeC << ".\n";
		bGameState = false;
		return false;	
	}
}

int main()
{
	srand(time(NULL));
	//Intro
	std::cout << "================================================== Quest for Wuuthard =================================================\n\n\n";
	std::cout << "                                     You are an adventurer in the world of Skyrim.\n";
	std::cout << "                       You go out on an adventure to find an artifact which is worth a lot of septims.\n";
	std::cout << "                               But it is in a Draugar filled dungeon with strange locks.\n";
	std::cout << "                               Get the code on the locks wrong and the Draugar wake up.\n";
	std::cout << "                                                 Good luck adventurer.\n";
	std::cout << "                                                And may Talos gaurd you.\n\n";
	std::cout << "_______________________________________________________________________________________________________________________\n\n\n";
	std::cout << "You enter an old and wrecked Draugar Dungeon and look around.\n";
	std::cout << "On a wall some letters are etched.\n";
	std::cout << "It says \"Be vary traveller of this dungeon. As you go deeper and deeper it becomes harder.\"";

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	while (bGameState && LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGameAtDifficulty(LevelDifficulty);
		std::cin.clear();//clears any error
		std::cin.ignore();//discards the buffer

		if (bLevelComplete)
		{
			LevelDifficulty++;
		}
	}
	
	if (bGameState)
	{
		std::cout << "\nThe door opens and you walk into an open room\n";
		std::cout << "There is a giant statue of Ysgramor.\n";
		std::cout << "You marvel at it when you spot a giant battle axe the statue is holding\n";
		std::cout << "You touch it and voice booms in the room.\n";
		std::cout << "It says \"Congratulations adventurer, you have found my tomb. Many have tried to find it but died in vain.\"\n";
		std::cout << "\"You are the first one who found it.\"the voice continues,\"Go on take it Wuuthard is yours.\"\n";
		std::cout << "You retrive Wuuthard and the door to get out the dungeon opens.\n";
		std::cout << "You exit the dungeon and with Wuuthard and the blessings of Ysgramar himself you go on to become a great fighter and eventually the High King of Skyrim.\n";
		std::cout << "\nThanks for playing\n\n\n";
	}
	
	std::cout << "Press any key to continue.......\n";
	char Anything;
	std::cin >> Anything;

	return 0;
}