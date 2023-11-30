#include <iostream>

#include "utility.h"

using namespace std;

int getOption(string txt) {

	cout << txt;
	int sel;
	cin >> sel;
	return sel;

}