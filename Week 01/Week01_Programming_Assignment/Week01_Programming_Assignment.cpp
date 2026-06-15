// Andrew Kuyda
// ITCS 2530
// Prof. Koss
// 6/13/2026

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const string REPORTFILE = "report.txt";

const int MENU_VIEW = 1;
const int MENU_SAVE = 2;

const int MENU_YES = 1;
const int MENU_NO = 2;

int main() {

	//Intro banner
	cout << "'~.,.~'~.,.~'~.,.~'~.,.~'~.,.~'" << endl;
	cout << "'Welcome to Snowglobe Tracker '" << endl;
	cout << ".~.,.~.,.~.,.~.,.~.,.~.,.~.,.~." << endl << endl;

	cout << "Let's create a list to track which States you've collected snow globes from." << endl;
	cout << "There are 49 continental States, and Hawaii." << endl;

	//Users favorite snow globe (collected)
	string favGlobe;

	cout << "What State is your favorite snow globe from?" << endl << endl;
	
	getline(cin, favGlobe);
	
	cout << endl << "Of course! " << favGlobe << " is a great State!" << endl;

	//Get destination user would most likely visit next
	string bestDest;

	cout << "What state would you most like to visit next?" << endl;
	cout << endl;

	getline(cin, bestDest); 
	cout << endl;
	cout << "Ahhh, " << bestDest << " is a fantastic place to visit!" << endl << endl;
	
	//Number of current states
	int const numStates = 50;
	
	cout << "So in order to track which snow globes you still need, let's figure out what globes you already have." << endl << endl;

	//Tracking number of states visited so far
	int visitedState = 0;

	cout << "How many states do you already have snow globes from?" << endl;
	cout << "Enter a number: ";
	
	//Invalid input check
	//if (!(cin >> visitedState))
	//{
	//	cout << "Please enter a valid number" << endl << endl;
	//	return 1;
	//}

	//***WEEK 04 - while loop***
	cin >> visitedState;

	while (visitedState <= 0 || visitedState > numStates)
	{
		cout << "Please enter the number of states you have visited: " << endl;
		cin >> visitedState;
	}

	//Output statement based on previous user inputs
	cout << endl << "So far we've ascertained that your favorite snow globe is from " << favGlobe << ", and that you're most likely to travel to " << bestDest << " next." << endl;

	cout << "That means that out of " << numStates << " States you've visited " << visitedState << ", which leaves " << numStates - visitedState << " States to visit, or " << numStates - visitedState + 1 << " after you visit " << bestDest << "." << endl << endl;

	//If\Else statements resulting in string

	if (visitedState >= 1 && visitedState <= 15)
		cout << "You've barely travelled at all! Better make some travel plans!" << endl << endl;
	else
		cout << "You've visited a lot of places... that's a good start!" << endl << endl;

	if (favGlobe == "Michigan" || favGlobe == "michigan")
		cout << "Great choice! Michigan has the best snow globe" << endl << endl;
	else
		cout << "Your favorite globe isn't from Michigan?! You have poor taste in snow globes!" << endl << endl;

	//***WEEK 04 for loop***
	cout << "This is your current progress towards your collections completion!" << endl << endl;

	cout << "Progress: [";
	for (int colProg = 0; colProg < numStates; colProg++)
	{
		if (colProg < visitedState)
			cout << "#";
		else
			cout << "_";
	}
	cout << "] " << visitedState << "/" << numStates << endl << endl;

	//***WEEK 04 - do while loop***
	int menuNum;
	int menuOption = 0;

	do
	{
		cout << "Please choose from the following menu options by entering the corresponding number: " << endl;
		cout << MENU_VIEW << ": View your summary table." << endl;
		cout << MENU_SAVE << ": Save your summary table." << endl << endl;
		cin >> menuNum;
	
		cout << endl;

		switch (menuNum)
		{
		case MENU_VIEW:
			//Summary Table with left align and set width
			cout << "#######################################" << endl;
			cout << "#     Snow Globe Tracking Summary     #" << endl;
			cout << "#######################################" << endl;
			cout << left;
			cout << setw(25) << "Favorite Globe:" << setw(15) << favGlobe << endl;
			cout << setw(25) << "Next Destination:" << setw(15) << bestDest << endl;
			cout << setw(25) << "States Collected:" << setw(15) << visitedState << endl;
			cout << setw(25) << "States Remaining:" << setw(15) << numStates - visitedState << endl;
			cout << "#######################################";
			break;
	
		case MENU_SAVE:
			//Output Summary to report file with file check
		{
			ofstream fReport;

			fReport.open(REPORTFILE);
			if (!fReport)
			{
				cout << "Error opening Report File:" << endl;
				return 1;
			}

			fReport << "#######################################" << endl;
			fReport << "#     Snow Globe Tracking Summary     #" << endl;
			fReport << "#######################################" << endl;
			fReport << left;
			fReport << setw(25) << "Favorite Globe:" << setw(15) << favGlobe << endl;
			fReport << setw(25) << "Next Destination:" << setw(15) << bestDest << endl;
			fReport << setw(25) << "States Collected:" << setw(15) << visitedState << endl;
			fReport << setw(25) << "States Remaining:" << setw(15) << (numStates - visitedState) << endl;
			fReport << "#######################################" << endl;

			fReport.close();

			cout << "Summary saved!" << endl;
			break;
		}

		default:
			cout << "Invalid menu option chosen." << endl;

		}

		cout << endl;
		cout << "Would you like to return to the menu?" << endl;
		cout << MENU_YES << ": Type '1' for Yes" << endl;
		cout << MENU_NO << ": Type '2' for No" << endl;
		cin >> menuOption;
		cout << endl;


	} while (menuOption == MENU_YES);

	cout << endl << endl << "Exiting menu" << endl;
	
	return 0;
	}


// State Tracker: Michigan, Ohio, Indiana, Pennsylvania, 
// Florida, Alabama, Georgia, North Carolina, Minnesota, 
// Colorado, New Mexico, Utah, and Mississippi. (13)