#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

string createRomanNumeral(int num, int numerals[], string letters[]);

int main() {

	int num; //this is the number we input

	cout << "Enter in your number: ";
	cin >> num;
	cout << endl << "Your number is: " << num; //this line is here for testing rn
	

	int numerals[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
	string letters[13] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
	//putting both of these into arrays so that the create roman numeral function will work


	auto start = high_resolution_clock::now();
	string romanNumeral = createRomanNumeral(num, numerals, letters);

	cout << endl << romanNumeral << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(stop - start);

	cout << "Time duration: " << duration.count() << " nanoseconds" << endl;
}


string createRomanNumeral(int num, int numerals[], string letters[]) {
	string romanNumeral;

	//using a for loop and using i to go through each array at the same time. 
	for (int i = 12; i >= 0; i--) {
		//while the num is greater than the numeral we are currently on it'll go through this loop
		while (num >= numerals[i]) {
			//adds the specific letters using i.
			romanNumeral += letters[i];
			num -= numerals[i];
			//subtracting the numeral from the number, for example:
			//if num was 2004 it would subtract 1000 and then it would be 1004 -> 4 -> 0
		}
	}
	return romanNumeral;
}