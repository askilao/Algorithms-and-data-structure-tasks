#include<iostream>
#include<string>
using namespace std;
/*
Guessing game using binary search
Where the computer guess the number and user selects higher, lower or correct answer
*/
int main() {
	int first, last, answer, mid, counter = 0;
	first = 1;
	last = 20000;
	char c;
	do {
		cout << "Guessing game:\nNumbers are between " << first << " and " << last << endl;
		first = 1;
		last = 20000;
		do {
			mid = first + (last - first) / 2;
			cout << "Is the number " << mid << "\n0 if lower\n1 if higher\n2 if correct answer" << endl;
			cin >> answer;
			if (answer == 0) {
				last = mid - 1;
			}
			else if (answer == 1) {
				first = mid + 1;
			}
			counter++;
		} while (answer != 2);

		cout << "Yes! I guessed the right number and it only took me " << counter << " tries!" << endl;
		cout << "Play again? y/n: "; cin >> c;
	} while (c != 'n');
}