#include<iostream>
#include<string>
using namespace std;

/*
Write a program that reads n words from the standard input, separated by spaces and prints them
mirrored (the mirroring function should be implemented recursively). What is the time complexity of
the algorithm? Use the BigO notation to express it.
Example input: n = 4 day time you is
Example output: yad emit ouy si
*/

string reverse(string s);

int main() {
	string s;
	int n;
	
	//determine the the amount of words from user
	cout << "Enter n: "; cin >> n; cin.ignore();
	string* words = new string[n];
	//dynamic array with size = n

	for (int i = 0; i < n; i++) {
	//input strings into string array separated by ' ' 
	getline(cin, words[i], ' ');
	cout << reverse(words[i]) << " ";
	}
	cout << endl;
	system("PAUSE");

}
/*
BIG O:
the function has to run to the length of each word so if there is 5 words it would be o(5n)
so worst case is O(n)
*/
string reverse(string s) {
	//basecase, if it is the last substr left
	if (s.size() == 1)
		return s;
	else {
		//reverse a substr of the original string and add the first charather of the string
		return reverse(s.substr(1, s.size())) + s.at(0);
	}
}
