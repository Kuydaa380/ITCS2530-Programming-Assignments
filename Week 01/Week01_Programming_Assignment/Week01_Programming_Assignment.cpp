#include <iostream>

using namespace std;

int main() {

	cout << "Let's create a list to track which States you've collected snow globes from.\n";
	cout << "There are 49 continental States, and Hawaii.\n";

	//Users favorite snow globe (collected)
	string favGlobe;

	cout << "What state is your favorite snow globe from?\n";
	cout << endl;
	cin >> favGlobe;
	cout << endl;
	cout << "Of course! " << favGlobe << " is a great State!\n";

	//State user would most like to visit next
	string bestDest;

	cout << "What state would you most like to visit next?\n";
	cout << endl;
	cin >> bestDest;
	cout << endl;
	cout << "Ahhh, " << bestDest << " is a fantastic place to visit!\n";
	cout << endl;

	//Tracking number of states visited so far
	int numStates = 50;
	
	cout << "So in order to track which snow globes you still need, let's figure out what globes you already have.\n";
	cout << endl;
	
	cout << "How many states do you already have snow globes from?\n";
	cout << "Enter a number:\n";
	cout << endl;

	int visitedState;
	cin >> visitedState;
	cout << endl;

	cout << "So far we've ascertained that your favorite snow globe is from " << favGlobe << ", and that you're most likely to travel to " << bestDest << " next.\n";
	cout << endl;
	cout << "That means that out of " << numStates << " States you've visted " << visitedState << ", which leaves " << numStates - visitedState << " States to visit, or " << numStates - ++visitedState << " after you visit " << bestDest;
	cout << endl;

	return 0;
}

// State Tracker: Michigan, Ohio, Indiana, Pennsylvania, 
// Florida, Alabama, Georgia, North Carolina, Minnesota, 
// Colorado, New Mexico, Utah, and Mississippi. (13)