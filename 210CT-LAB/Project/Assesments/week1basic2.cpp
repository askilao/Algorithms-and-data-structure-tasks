#include<iostream>
#include<string>
#include <cmath>
using namespace std;



int main() {

	string number = "";
	int n, armCheck;
	while (2 > 1) {
		cout << "enter number: "; getline(cin, number);

		armCheck = stoi(number);
		int armSum = 0;
		int listlen = number.size();
		for (int i = 0; i < listlen; i++) {
			if (isdigit(number.at(i))) {
				char temp = number.at(i);
				n = atoi(&temp);
				armSum += int(pow(n, listlen));
			}
		}
		if (armSum == armCheck) cout << "Yes\n";
		else cout << "No\n";
	}
}
