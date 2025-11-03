// COMSC-210 | Lab 28 | Dainiz Almazan
// IDE used: CLion

#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <numeric>
#include <random>

#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25;

int select_goat(list<Goat> trip);

void delete_goat(list<Goat> &trip);

void add_goat(list<Goat> &trip, string [], string []);

void display_trip(list<Goat> trip);

// Uses std::find to find a goat by name and display its info
// arguments: an array of Goat objects
// returns: nothing
void find_goat_by_name(list<Goat> &trip);

// Uses std::replace to replace a Goat object with another Goat object
// arguments: an array of Goat objects
// returns: nothing
void replace_goat(list<Goat> &trip);

// Uses std::shuffle to shuffle the list of Goat objects
// arguments: an array of Goat objects
// returns: nothing
void shuffle_goats(list<Goat> &trip);

// Uses std::reverse to reverse the list of Goat objects
// arguments: an array of Goat objects
// returns: nothing
void reverse_goats(list<Goat> &trip);

// Uses std::for_each to increase the age of all the goats by 1
// arguments: an array of Goat objects
// returns: nothing
void age_goats(list<Goat> &trip);

// Uses std::accumulate to get the sum of all Goat objects in the array and display it
// arguments: an array of Goat objects
// returns: nothing
void get_num_goats(list<Goat> &trip);

// Uses std::any_of to check if a Goat object with the provided color exists and displays the result
// arguments: an array of Goat objects
// returns: nothing
void check_for_goat_color(list<Goat> &trip);

// Uses std::clear to delete all the Goat objects in the array
// arguments: an array of Goat objects
// returns: nothing
void delete_goats(list<Goat> &trip);

int main_menu();

int main() {
	srand(time(0));

	// read & populate arrays for names and colors
	ifstream fin("names.txt");
	string names[SZ_NAMES];
	int i = 0;
	while (fin >> names[i++]);
	fin.close();
	ifstream fin1("colors.txt");
	string colors[SZ_COLORS];
	i = 0;
	while (fin1 >> colors[i++]);
	fin1.close();

	// create & populate a trip of Goats using std::list of random size 8-15
	int tripSize = rand() % 8 + 8;
	list<Goat> trip;
	int age;
	string name, color;
	for (int i = 0; i < tripSize; i++) {
		age = rand() % MAX_AGE; // defined in Goat.h
		name = names[rand() % SZ_NAMES];
		color = colors[rand() % SZ_COLORS];
		Goat tmp(name, age, color);
		trip.push_back(tmp);
	}

	// Goat Manager 3001 Engine
	int sel = main_menu();
	while (sel != 12) {
		switch (sel) {
			case 1:
				cout << "Adding a goat.\n";
				add_goat(trip, names, colors);
				break;
			case 2:
				cout << "Removing a goat.\n";
				delete_goat(trip);
				break;
			case 3:
				cout << "Displaying goat data.\n";
				display_trip(trip);
				break;
			case 4:
				find_goat_by_name(trip);
				break;
			case 5:
				replace_goat(trip);
				break;
			case 6:
				shuffle_goats(trip);
				break;
			case 7:
				reverse_goats(trip);
				break;
			case 8:
				age_goats(trip);
				break;
			case 9:
				get_num_goats(trip);
				break;
			case 10:
				check_for_goat_color(trip);
				break;
			case 11:
				delete_goats(trip);
				break;
			default:
				cout << "Invalid selection.\n";
				break;
		}
		sel = main_menu();
	}

	return 0;
}

int main_menu() {
	cout << "*** GOAT MANAGER 3001 ***\n";
	cout << "[1] Add a goat\n";
	cout << "[2] Delete a goat\n";
	cout << "[3] List goats\n";
	cout << "[4] Find a goat by name\n"; // find
	cout << "[5] Replace goat\n"; //replace
	cout << "[6] Shuffle goats\n"; //shuffle
	cout << "[7] Reverse goats\n"; //reverse
	cout << "[8] Age all goats\n"; //for_each
	cout << "[9] Get number of goats\n"; //accumulate
	cout << "[10] Find out if color of goat exists\n"; //any_of
	cout << "[11] Delete all goats\n"; //clear
	cout << "[12] Quit\n";
	cout << "Choice --> ";
	int choice;
	cin >> choice;
	while (choice < 1 || choice > 12) {
		cout << "Invalid, again --> ";
		cin >> choice;
	}
	return choice;
}

void delete_goat(list<Goat> &trip) {
	cout << "DELETE A GOAT\n";
	int index = select_goat(trip);
	auto it = trip.begin();
	advance(it, index - 1);
	trip.erase(it);
	cout << "Goat deleted. New trip size: " << trip.size() << endl;
}

void add_goat(list<Goat> &trip, string nms[], string cls[]) {
	cout << "ADD A GOAT\n";
	int age = rand() % MAX_AGE;
	string nm = nms[rand() % SZ_NAMES];
	string cl = cls[rand() % SZ_COLORS];
	Goat tmp(nm, age, cl);
	trip.push_back(tmp);
	cout << "Goat added. New trip size: " << trip.size() << endl;
}

void display_trip(list<Goat> trp) {
	int i = 1;
	for (auto gt: trp)
		cout << "\t"
				<< "[" << i++ << "] "
				<< gt.get_name()
				<< " (" << gt.get_age()
				<< ", " << gt.get_color() << ")\n";
}

int select_goat(list<Goat> trp) {
	int input;
	cout << "Make a selection:\n";
	display_trip(trp);
	cout << "Choice --> ";
	cin >> input;
	while (input < 1 or input > trp.size()) {
		cout << "Invalid choice, again --> ";
		cin >> input;
	}
	return input;
}

void find_goat_by_name(list<Goat> &trip) {
	// TODO: fix
	// string name;
	// cout << "Enter the name of the goat you're searching for: ";
	// cin >> name;
	// auto it = find(trip.begin(), trip.end(), [](const Goat& goat) {
	// 	return goat.get_name() == name;
	// });
	// if (it != trip.end()) {
	// 	//
	// }
}

void replace_goat(list<Goat> &trip) {
}

void shuffle_goats(list<Goat> &trip) {
	// TODO: fix
	//shuffle(trip.begin(), trip.end(), default_random_engine());
}

void reverse_goats(list<Goat> &trip) {
	reverse(trip.begin(), trip.end());
}

void age_goats(list<Goat> &trip) {
	for_each(trip.begin(), trip.end(), [](Goat& goat) {
		goat.set_age(goat.get_age() + 1);
	});
}

void get_num_goats(list<Goat> &trip) {
	int numGoats = accumulate(trip.begin(), trip.end(), 0, [](int sum, const Goat& goat) {
		return sum + 1;
	});
	cout << "Total number of goats: " << numGoats << endl;
}

void check_for_goat_color(list<Goat> &trip) {
	string color;
	cout << "Enter the goat color to search for: ";
	cin >> color;
	bool found = any_of(trip.begin(), trip.end(),[color](Goat goat) {
		return goat.get_color() == color;
	});

	if (found)
		cout << "Goat color " << color << " found!\n";
	else
		cout << "Goat color " << color << " found!\n";
}

void delete_goats(list<Goat> &trip) {
	trip.clear();
}
