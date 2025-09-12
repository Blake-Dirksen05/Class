#include <iostream>
#include <chrono>
#include<vector>
#include<numeric>
using namespace std;
using namespace std::chrono;

string createRomanNumeral(int num, int numerals[], string letters[]);

int main() {
	int num; //this is the number we input

	cout << "Enter in your number: ";
	cin >> num;
	cout << endl << "Your number is: " << num << endl; //this line is here for testing rn
	
	int numerals[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	string letters[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	//putting both of these into arrays so that the create roman numeral function will work
	
	auto start = high_resolution_clock::now();
	string romanNumeral = createRomanNumeral(num, numerals, letters);
	auto stop = high_resolution_clock::now();
	
	auto duration = duration_cast<nanoseconds>(stop - start);
	
	cout << endl << romanNumeral << endl;
	cout << "Time duration: " << duration.count() << " nanoseconds" << endl;
}


string createRomanNumeral(int num, int numerals[], string letters[]) {
	string romanNumeral;

	//using a for loop and using i to go through each array at the same time. 
	for (int i = 12; i >= 0; i--) {
		int remainder = num / numerals[i];	//dividing by the numerals so that we can see how many numerals we need
		
		if (remainder > 0) { //if we have a remainder we go through this loop
			for (int j = 0; j < remainder; j++) { //however many remainder we have we go through this 2nd for loop
				romanNumeral += letters[i];
				//adding the string onto the string every loop
			}
		num %= numerals[i]; //reducing num so that we don't repeat ourselves
		}
	}

	return romanNumeral;
}