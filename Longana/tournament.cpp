#include "tournament.h"



tournament::tournament()
{
	tournScore = 0;
}


tournament::~tournament()
{
}

void tournament::startTourn()
{
	
}

void tournament::setTournScore()
{
	while (tournScore == 0)
	{
		cout << "Please enter the tournament score: ";
		cin >> tournScore;
		//Check to make sure the user enters a number.
		if (cin.fail())
		{
			cout << "invalid input. input must be a number" << endl << endl;
			cin.clear();
			cin.ignore();
			tournScore = 0;
		}
	}
	
}