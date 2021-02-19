#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	string name;
	int votes;
} candidate;

string candidateName;
string voteName;
string voteCompare;
vector<candidate> candidates;

int candidateCount;
int voteCount;

bool vote(string name); 
void print_winner(); 

int main() {

	cout << "How many candidates are there? >" << flush;
	cin >> candidateCount;

	while (candidateCount < 2) {
		cout << "Need more than one candidate." << endl;
		cout << "How many candidates are there? >" << flush;
		cin >> candidateCount;
	}

	for (int i = 0; i < candidateCount; i++) {
		cout << "Enter name for candidate " << i + 1 << ": " << flush;
		cin >> candidateName;
		//https://stackoverflow.com/questions/8067338/vector-of-structs-initialization
		// Push back new candidate with default constructor
		candidates.push_back(candidate());
		candidates[i].name = candidateName;
		cout << candidates[i].name << endl;
	}

	cout << "All candidates entered." << endl;
	cout << "Number of voters:" << flush;
	cin >> voteCount;

	for (int i = 0; i < voteCount; i++) {
		cout << "Enter Vote #" << i + 1 << ": " << flush;
		cin >> voteName;
		
		while (!vote(voteName)) {
			cout << "Name not found." << endl;
			cout << "Enter Vot #" << i + 1 << ": " << flush;
			cin >> voteName;
		}
	}

	cout << "All votes entered." << endl;

	print_winner();

	candidates.clear();

	return 0;
}

bool vote(string name) {
	for (int i = 0; i < candidateCount; i++) {
		if (candidates[i].name == name) {
			candidates[i].votes++;
			return true;
		}	
	}

	return false;
}

void print_winner() {
	int max = 0;

	for (int i = 0; i < candidateCount; i++) {
		if (candidates[i].votes > max) {
			max = candidates[i].votes;
		}
	}

	int ties = 0;

	for (int i = 0; i < candidateCount; i++) {
		if (candidates[i].votes == max) {
			cout << candidates[i].name << " wins with " << max << " votes." << endl;
			ties++;
		}
	}

	if (ties > 1) {
		cout << "We have a tie." << endl;
 	}
}