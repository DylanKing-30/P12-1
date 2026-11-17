//	P12-1.cpp	-	Dylan King	-	November 15, 2026
//
//	Description:	The program displays the seat pattern as shown below left. The program then accepts seat requests,
//					with one seat being requested at a time. If a valid seat request is made, then the seat letter is
//					replaced with an 'X' to mark that the seat has now been reserved and an updated seating chart is
//					is displayed.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

const int ROWS = 13;
const int COLUMNS = 4;
const int ERROR = -1;

char seat_chart[COLUMNS][ROWS];

// findRowIndex: given user input, returns appropriate row index into arrays.
// @param thisRow - integer indicating row selected by the user
// @return appropriate index into 2-D array if the specified row is valid, ERROR otherwise
int findRowIndex(int thisRow);
// findSeatIndex: given user input, returns appropriate column index into seating chart array.
// @param thisSeat - character indicating selected seat within row
// @return appropriate index into 2-D array if the specified seat is valid, ERROR otherwise
int findSeatIndex(char thisSeat);
// displaySeatColumn: given a 2-D mapping of the seating chart in the form [columns][rows],
// will print out a "column" of seats on one row of output (i.e., seat 'A' for all rows in the plane)
// @param seats - reference to a 2-D character array
// @param column - reference to which column of seats to display
void displaySeatColumn(char seats[][ROWS], int column);

int main() {
	//	Assign the seating chart values
	for (int i = 1; i <= ROWS; i++) {
		seat_chart[0][i - 1] = 'A';
		seat_chart[1][i - 1] = 'B';
		seat_chart[2][i - 1] = 'C';
		seat_chart[3][i - 1] = 'D';
	}
	seat_chart[2][12] = '?';
	seat_chart[3][13] = '?';

	string str;
	while (true) {
		displaySeatColumn(seat_chart, 3);
		displaySeatColumn(seat_chart, 2);

		cout << "\n";
		for (int i = 1; i <= ROWS; i++) {
			if (i < 10) {
				cout << "  ";
			}
			else {
				cout << i / 10 << " ";
			}
		}
		cout << "\n";
		for (int i = 1; i <= ROWS; i++) {
			if (i < 10) {
				cout << i << " ";
			}
			else {
				cout << i % 10 << " ";
			}
		}
		cout << "\n\n";
		displaySeatColumn(seat_chart, 1);
		displaySeatColumn(seat_chart, 0);
		cout << "\nEnter a seat or Q to quit: ";
		int row_index = 5;
		int column_index = 5;
		if (getline(cin, str)) {
			//	Load the line into a stringstream
			stringstream ss(str);

			char seat;
			int row;

			ss >> row >> seat;

			if (ss.str() == "Q" || ss.str() == "q") {
				return 0;
			}
			
			if (findRowIndex(row) == -1) {
				cout << "Sorry, no such seat exists on the CRJ 200.";
			}
			else {
				row_index = findRowIndex(row);
			}

			if (findSeatIndex(seat) == -1 && findRowIndex(row) != -1) {
				cout << "Sorry, no such seat exists on the CRJ 200.";
			}
			else {
				column_index = findSeatIndex(seat);
			}
		}

;
	}
}

// findRowIndex: given user input, returns appropriate row index into arrays.
// @param thisRow - integer indicating row selected by the user
// @return appropriate index into 2-D array if the specified row is valid, ERROR otherwise
int findRowIndex(int thisRow) {
	if (thisRow == 1 || thisRow == 2 || thisRow == 3 || thisRow == 4 || thisRow == 5 || thisRow == 6 || thisRow == 7 || thisRow == 8 || thisRow == 9 || thisRow == 10 || thisRow == 11 || thisRow == 12 || thisRow == 13) {
		return thisRow - 1;
	}
	else {
		return ERROR;
	}
}
// findSeatIndex: given user input, returns appropriate column index into seating chart array.
// @param thisSeat - character indicating selected seat within row
// @return appropriate index into 2-D array if the specified seat is valid, ERROR otherwise
int findSeatIndex(char thisSeat) {
	if (thisSeat == 'A') {
		return 0;
	}
	else if (thisSeat == 'B') {
		return 1;
	}
	else if (thisSeat == 'C') {
		return 2;
	}
	else if (thisSeat == 'D') {
		return 3;
	}
	else {
		return ERROR;
	}
}
// displaySeatColumn: given a 2-D mapping of the seating chart in the form [columns][rows],
// will print out a "column" of seats on one row of output (i.e., seat 'A' for all rows in the plane)
// @param seats - reference to a 2-D character array
// @param column - reference to which column of seats to display
void displaySeatColumn(char seats[][ROWS], int column) {
	if (column == 0 || column == 1) {
		for (int row = 0; row < ROWS; row++) {
			cout << seats[column][row] << " ";
		}
	}
	else if (column == 2 || column == 3) {
		for (int row = 0; row < ROWS - 1; row++) {
			cout << seats[column][row] << " ";
		}
	}
	cout << "\n";
}