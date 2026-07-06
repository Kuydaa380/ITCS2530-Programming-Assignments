// Andrew Kuyda
// ITCS 2530
// Prof. Koss
// 7/5/2026

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

const string REPORTFILE = "report.txt";

//Menu options values
const int MENU_VIEW = 1;
const int MENU_SAVE = 2;
const int MENU_COLLECTION = 3;

const int MENU_YES = 1;
const int MENU_NO = 2;

//Number of current states
const int numStates = 50;
const int MAX_COLLECTION = 50;

//Collector experience level
enum CollectorLevel {BEGINNER, INTERMEDIATE, EXPERT};

//NEW - Struct that combines and stores snow globe collection variables
struct SnowGlobe
{
	string state;
	string city;
	int yearCollected;
	CollectorLevel level;
};

//Function to change colors in functions that call it
void setColor(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}


//Function to display and set color of the welcome banner
void displayBanner()
{
	setColor(11); // Cyan
	cout << "'~.,.~'~.,.~'~.,.~'~.,.~'~.,.~'" << endl;
	cout << "'Welcome to Snowglobe Tracker '" << endl;
	cout << ".~.,.~.,.~.,.~.,.~.,.~.,.~.,.~." << endl << endl;
	setColor(7); // Reset to White
}


//Function to input users favorite snow globe (collected)
string getFavGlobe()
{
	string favGlobe;

	setColor(10); // Green
	cout << "What State is your favorite snow globe from?" << endl << endl;
	setColor(7); // Reset to White

	getline(cin, favGlobe);
	cout << endl << "Of course! " << favGlobe << " is a great State!" << endl;

	return favGlobe;
}


//Function to get destination user would most likely visit next
string getBestDest()
{
	string bestDest;

	setColor(10); // Green
	cout << "What state would you most like to visit next?" << endl << endl;
	setColor(7); // Reset to White

	getline(cin, bestDest);
	cout << endl << "Ahhh, " << bestDest << " is a fantastic place to visit!" << endl << endl;

	return bestDest;
}


//Function to track number of states visited so far
int getVisitedStates()
{
	int visitedState = 0;

	setColor(10); // Green
	cout << "How many states do you already have snow globes from?" << endl << "Enter a number: ";
	setColor(7); // Reset to White

	//Function for while loop for number of states visited
	cin >> visitedState;

	while (visitedState <= 0 || visitedState > numStates)
	{
		cout << "Please enter the number of states you have visited: " << endl;
		cin >> visitedState;
	}
	return visitedState;
}


//Function to determine collector level based on enum skill rating
CollectorLevel getCollectorLevel(int visitedState)
{
	if (visitedState <= 15)
		return BEGINNER;
	else if (visitedState <= 35)
		return INTERMEDIATE;
	else
		return EXPERT;
}


//NEW - Function that uses an array to store user input about which states they got each of their snowglobes from
void fillCollection(SnowGlobe collection[], int size)
{
	cin.ignore();

	for (int i = 0; i < size; i++)
	{
		setColor(10); // Green

		cout << "\nSnow Globe #" << i + 1 << endl;

		cout << "State: ";

		setColor(7); // Reser to White

		getline(cin, collection[i].state);

		while (collection[i].state.empty())
		{
			cout << "State cannot be blank: ";
			getline(cin, collection[i].state);
		}

		setColor(10); // Green

		cout << "City Purchased: ";

		setColor(7); // Reset to White

		getline(cin, collection[i].city);

		while (collection[i].city.empty())
		{
			cout << "City cannot be blank: ";
			getline(cin, collection[i].city);
		}

		setColor(10); // Green

		cout << "Year Collected: ";

		setColor(7); // Reset to White

		cin >> collection[i].yearCollected;
		cin.ignore();

		collection[i].level = getCollectorLevel(size);
	}
}


//NEW - Function to display the array of the snow globe collection
void displayCollection(SnowGlobe collection[], int size)
{
	setColor(11); // Cyan

	cout << endl;
	cout << "Collected Snow Globes" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". "
			<< collection[i].state
			<< " | City: " << collection[i].city
			<< " | Year: " << collection[i].yearCollected
			<< endl;
	}

	cout << endl;

	setColor(7); // Reset to White
}


//NEW - Array calculation that finds the longest and shortest state names
void findLongestAndShortest(SnowGlobe collection[], int size)
{
	if (size <= 0)
		return;

	string longest = collection[0].state;
	string shortest = collection[0].state;

	for (int i = 1; i < size; i++)
	{
		if (collection[i].state.length() > longest.length())
			longest = collection[i].state;

		if (collection[i].state.length() < shortest.length())
			shortest = collection[i].state;
	}

	setColor(14); // Yellow

	cout << endl;

	cout << left;

	cout << "          Array Calculation Results          " << endl;
	cout << "---------------------------------------------" << endl;
	cout << setw(25) << "Longest State Name:" << setw(15) << longest << endl;
	cout << setw(25) << "Shortest State Name:" << setw(15) << shortest << endl;
	cout << endl;

	setColor(7); // Reset to White
}

//Function to output statement based on previous user inputs
void displayStatesBreakdown(string favGlobe, string bestDest, int visitedState)
{
	cout << endl << "So far we've ascertained that your favorite snow globe is from " << favGlobe << ", and that you're most likely to travel to " << bestDest << " next." << endl;

	cout << "That means that out of " << numStates << " States you've visited " << visitedState << ", which leaves " << numStates - visitedState << " States to visit, or " << numStates - (visitedState + 1) << " after you visit " << bestDest << "." << endl << endl;
}


//Function for If\Else statements resulting in string
void displayStatesFeedback(int visitedState, string favGlobe)
{
	if (visitedState >= 1 && visitedState <= 15)
		cout << "You've barely travelled at all! Better make some travel plans!" << endl << endl;
	else
		cout << "You've visited a lot of places... that's a good start!" << endl << endl;

	if (favGlobe == "Michigan" || favGlobe == "michigan")
		cout << "Great choice! Michigan has the best snow globe" << endl << endl;
	else
		cout << "Your favorite globe isn't from Michigan?! You have poor taste in snow globes!" << endl << endl;
}


//Function with for loop to display collection progress
void progressBar(int visitedState)
{
	cout << "This is your current progress towards your collections completion!" << endl << endl;

	setColor(11); // Cyan

	cout << "Progress: [";

	for (int colProg = 0; colProg < numStates; colProg++)
	{
		if (colProg < visitedState)
			cout << "#";
		else
			cout << "_";
	}
	cout << "] " << visitedState << "/" << numStates << endl << endl;

	setColor(7); // Reset to White
}


//Function for Summary Table with left align and set width
void displaySummary(string favGlobe, string bestDest, int visitedState)
{
	setColor(12); // Red

	cout << "#######################################" << endl;
	cout << "#     Snow Globe Tracking Summary     #" << endl;
	cout << "#######################################" << endl;
	
	cout << left;

	cout << setw(25) << "Favorite Globe:" << setw(15) << favGlobe << endl;
	cout << setw(25) << "Next Destination:" << setw(15) << bestDest << endl;
	cout << setw(25) << "States Collected:" << setw(15) << visitedState << endl;
	cout << setw(25) << "States Remaining:" << setw(15) << numStates - visitedState << endl;

	//Enum collector level being used in a switch structure
	cout << setw(25) << "Collector Level:";

	CollectorLevel level = getCollectorLevel(visitedState);

	switch (level)
	{
	case BEGINNER:
		cout << "Beginner";
		break;

	case INTERMEDIATE:
		cout << "Intermediate";
		break;

	case EXPERT:
		cout << "Expert";
		break;
	}

	cout << endl;
	cout << "#######################################";
	
	setColor(7); // Reset to White
}


//NEW - Function to save summary to report file with file check
void saveReport(string favGlobe, string bestDest, int visitedState, SnowGlobe collection[])
{
	ofstream fReport;

	fReport.open(REPORTFILE);

	if (!fReport)
	{
		cout << "Error opening Report File:" << endl;
		return;
	}

	fReport << "#######################################" << endl;
	fReport << "#     Snow Globe Tracking Summary     #" << endl;
	fReport << "#######################################" << endl;

	fReport << left;

	fReport << setw(25) << "Favorite Globe:" << setw(15) << favGlobe << endl;
	fReport << setw(25) << "Next Destination:" << setw(15) << bestDest << endl;
	fReport << setw(25) << "States Collected:" << setw(15) << visitedState << endl;
	fReport << setw(25) << "States Remaining:" << setw(15) << numStates - visitedState << endl;
	
	//Enum collector level is included along with array contents of collected snow globes
	CollectorLevel level = getCollectorLevel(visitedState);

	fReport << setw(25) << "Collector Level:";

	switch (level)
	{
	case BEGINNER:
		fReport << "Beginner";
		break;

	case INTERMEDIATE:
		fReport << "Intermediate";
		break;

	case EXPERT:
		fReport << "Expert";
		break;
	}

	fReport << endl << endl;

	fReport << "Collected Snow Globes" << endl;
	fReport << "---------------------" << endl;

	for (int i = 0; i < visitedState; i++)
	{
		fReport << i + 1 << ". "
			<< collection[i].state
			<< " | "
			<< collection[i].city
			<< " | "
			<< collection[i].yearCollected
			<< endl;
	}

	fReport.close();

	setColor(10); // Green

	cout << "Summary saved!" << endl;

	setColor(7); // Reset to White
}

//NEW - Function for a do while loop to display menu options
void displayMenu(string favGlobe, string bestDest, int visitedState, SnowGlobe collection[])
{
	int menuNum;
	int menuOption = 0;

	do
	{
		cout << "Please choose from the following menu options by entering the corresponding number:" << endl;

		cout << MENU_VIEW << ": View your summary table." << endl;
		cout << MENU_SAVE << ": Save your summary table." << endl;
		cout << MENU_COLLECTION << ": View collected snow globes." << endl << endl;

		cin >> menuNum;

		cout << endl;

		switch (menuNum)
		{
		case MENU_VIEW:
			displaySummary(favGlobe, bestDest, visitedState);
			break;

		case MENU_SAVE:
			saveReport(favGlobe, bestDest, visitedState, collection);
			break;

		case MENU_COLLECTION:
			displayCollection(collection, visitedState);
			break;

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

	cout << endl << endl;
	cout << "Exiting menu." << endl;
}


int main()
{
	displayBanner();

	cout << "Let's create a list to track which States you've collected snow globes from." << endl;
	cout << "There are 49 continental States, and Hawaii." << endl;

	string favGlobe = getFavGlobe();

	string bestDest = getBestDest();

	cout << "So in order to track which snow globes you still need, let's figure out what globes you already have." << endl << endl;

	int visitedState = getVisitedStates();

	//NEW - Array to store collected states
	SnowGlobe collection[MAX_COLLECTION];

	fillCollection(collection, visitedState);

	findLongestAndShortest(collection, visitedState);

	displayStatesBreakdown(favGlobe, bestDest, visitedState);

	displayStatesFeedback(visitedState, favGlobe);

	progressBar(visitedState);

	displayMenu(favGlobe, bestDest, visitedState, collection);

	return 0;
}

// State Tracker: Michigan, Ohio, Indiana, Pennsylvania, 
// Florida, Alabama, Georgia, North Carolina, Minnesota, 
// Colorado, New Mexico, Utah, and Mississippi. (13)

// 7 = White (default color)
// 8 = Gray
// 9 = Bright Blue
// 10 = Bright Green
// 11 = Bright Cyan
// 12 = Bright Red
// 13 = Bright Magenta
// 14 = Bright Yellow
// 15 = Bright White