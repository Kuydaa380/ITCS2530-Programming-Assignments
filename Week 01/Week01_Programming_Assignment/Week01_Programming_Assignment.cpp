// Andrew Kuyda
// ITCS 2530
// Prof. Koss
// 5/30/2026

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
//***WEEK 02 - Included <iomanip> for input\output formatting***
//***WEEK 02 - Included <string> for manipulating strings***
//***WEEK 02 - Included <fstream> for file input and output***

using namespace std;

//***WEEK 02 - Made a string var like the video ex. to safeguard file name
const string REPORTFILE = "report.txt";

int main() {

	//***WEEK 02 - Add Intro Banner***

	cout << "'~.,.~'~.,.~'~.,.~'~.,.~'~.,.~'" << endl;
	cout << "'Welcome to Snowglobe Tracker '" << endl;
	cout << ".~.,.~.,.~.,.~.,.~.,.~.,.~.,.~." << endl << endl;

	cout << "Let's create a list to track which States you've collected snow globes from." << endl;
	cout << "There are 49 continental States, and Hawaii." << endl;

	//Users favorite snow globe (collected)
	string favGlobe;

	//***WEEK 02 - replaced \n with << endl for consistency***
	//***WEEK 02 - replaced "cout << endl;" with "<< endl << endl" for readability***

	cout << "What State is your favorite snow globe from?" << endl << endl;
	
	//***WEEK 02 - replaced cin >> favGlobe; with a getline to account for spaces in state names e.g. New Mexico
	getline(cin, favGlobe);
	
	cout << "Of course! " << favGlobe << " is a great State!" << endl;

	//State user would most like to visit next
	string bestDest;

	cout << "What state would you most like to visit next?" << endl;
	cout << endl;

	//***WEEK 02 - replaced cin with getline to account for spaces in state names e.g. New Mexico***
	getline(cin, bestDest); 
	cout << endl;
	cout << "Ahhh, " << bestDest << " is a fantastic place to visit!" << endl << endl;
	

	//Tracking number of states visited so far
	
	//***WEEK 02 - Made numStates const***
	int const numStates = 50;
	
	cout << "So in order to track which snow globes you still need, let's figure out what globes you already have." << endl << endl;

	int visitedState = 0;
	//***WEEK 02 - Initialized value with 0, moved above previous text (cout)***

	cout << "How many states do you already have snow globes from?" << endl;
	cout << "Enter a number:" << endl << endl;
	
	//***WEEK 02 - Added an invalid input check only using if***
	if (!(cin >> visitedState))
	{
		cout << "Please enter a valid number" << endl;
		return 1;
	}
		
	cout << endl;

	cout << "So far we've ascertained that your favorite snow globe is from " << favGlobe << ", and that you're most likely to travel to " << bestDest << " next." << endl << endl;
	cout << "That means that out of " << numStates << " States you've visited " << visitedState << ", which leaves " << numStates - visitedState << " States to visit, or " << numStates - ++visitedState << " after you visit " << bestDest << endl << endl;

	//***WEEK 02 - added Summary Table with left align and set width***
	cout << "#######################################" << endl;
	cout << "#     Snow Globe Tracking Summary     #" << endl;
	cout << "#######################################" << endl;
	cout << left;
	cout << setw(25) << "Favorite Globe:" << setw(15) << favGlobe << endl;
	cout << setw(25) << "Next Destination:" << setw(15) << bestDest << endl;
	cout << setw(25) << "States Collected:" << setw(15) << visitedState << endl;
	cout << setw(25) << "States Remaining:" << setw(15) << numStates - visitedState << endl;
	cout << "#######################################";

	//***WEEK 02 - Output Summary to report file with file check***

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

	return 0;
}


// State Tracker: Michigan, Ohio, Indiana, Pennsylvania, 
// Florida, Alabama, Georgia, North Carolina, Minnesota, 
// Colorado, New Mexico, Utah, and Mississippi. (13)