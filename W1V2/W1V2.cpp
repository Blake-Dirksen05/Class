//Gerishom Muholeza Code
#include <iostream>
#include <vector>
using namespace std;


string Roman(int num) {

	// Table of integer values and their corresponding Roman numeral symbols
	const vector<pair<int, string>> table = {
		{1000,"M"}, {900,"CM"}, {500,"D"},  {400,"CD"}, 
		{100,"C"},  {90,"XC"},  {50,"L"},   {40,"XL"}, 
		{10,"X"},   {9,"IX"},   {5,"V"},    {4,"IV"}, 
		{1,"I"}
	};

	// Resultant Roman numeral string
	string res;

	// Iterate through the table
	for (const auto& p : table) { 
		int val = p.first; // Get the integer value
		const string& symbol = p.second;

		// Append as many times as possible
		while (num >= val) {
			num -= val; // Reduce num
			res += symbol; // Append the symbol
		}
		if (num == 0) break; // Early exit if num is reduced to 0
	}
	return res;
}

int main() {

	int example1 = 3749;
	int example2 = 58;
	int example3 = 1994;

	cout << "Here is the Roman Numerals into Integers - Example 1: " <<
		Roman(example1) << endl;

	cout << "Here is the Roman Numerals into Integers - Example 2: " <<
		Roman(example2) << endl;

	cout << "Here is the Roman Numerals into Integers - Example 3: " <<
		Roman(example3) << endl;

	return 0;

}
