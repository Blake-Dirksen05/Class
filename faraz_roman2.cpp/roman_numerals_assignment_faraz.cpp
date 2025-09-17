#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <unordered_map>
#include <chrono>
using namespace std;
/*
  Integer - Roman 
  Time: O(1) because we loop a constant-sized list of 13 tokens.
  Space: O(1).
*/
string intToRoman(int num) {
    static const vector<pair<int,string>> tokens = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string res;
    for (const auto &t : tokens) {
        while (num >= t.first) {
            res += t.second;
            num -= t.first;
        }
    }
    return res;
}

/* Optional (bonus): Roman → Integer
   Validates  pairs (IV, IX, XL, XC, CD, CM). 
   Time: O(n) over length of string, Space: O(1).
*/
int romanToInt(const string &s) {
    unordered_map<char,int> val{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int n = (int)s.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int v = val[s[i]];
        if (i+1 < n && v < val[s[i+1]]) {
            // ensure valid subtractive pairs
            char a = s[i], b = s[i+1];
            bool ok = (a=='I' && (b=='V'||b=='X')) ||
                      (a=='X' && (b=='L'||b=='C')) ||
                      (a=='C' && (b=='D'||b=='M'));
            if (!ok) throw invalid_argument("Invalid subtractive pair");
            ans += val[b] - v;
            ++i; // skip next
        } else {
            ans += v;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Example 2 from the prompt
    int num = 58;
    string r = intToRoman(num);
    cout << num << " → " << r << "\n"; // Expected: LVIII

    // run the other two prompt examples
    vector<int> tests = {3749, 1994};
    for (int x : tests) {
        cout << x << " → " << intToRoman(x) << "\n";
    }

    // Optional: quick runtime check over many calls (prints milliseconds)
    const int REPS = 1'000'000; // 1e6 calls
    auto start = chrono::steady_clock::now();
    long long checksum = 0; // prevent optimizer from discarding
    for (int i = 1; i <= REPS; ++i) {
        checksum += intToRoman((i % 3999) + 1).size();
    }
    auto end = chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end - start).count();
    cerr << "Performed " << REPS << " conversions in " << ms << " ms (O(1) per call).\n";
    cerr << "checksum=" << checksum << "\n"; // side-effect to keep loop

    // Quick round-trip check for correctness (Roman → Int → Roman) 
    vector<string> sampleRomans = {"LVIII", "MMMDCCXLIX", "MCMXCIV"};
    for (const string &sr : sampleRomans) {
        int v = romanToInt(sr);
        cout << sr << " → " << v << " → " << intToRoman(v) << "\n";
    }

    return 0;
}

/*
WHY I THINK THIS IS MOST EFFICIENT
- We  consume the largest possible token from a fixed, sorted list of 13 Roman tokens.
- The loop visits at most 13 tokens and appends a bounded number of symbols (<= 15 for max 3999).
- Therefore the running time is O(1) per conversion and space is O(1).

*/
