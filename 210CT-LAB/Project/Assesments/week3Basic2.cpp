#include<iostream>
#include<string>
using namespace std;


bool linear_search(int arr[],int m, int n);
int int_get(string s);
int main() {
	int n,m;
	while (true) {
		m = int_get("Enter length of array");
		int* array = new int[m + 1];

		for (int i = 0; i < m; i++) {
			cout << "Enter number: " << i + 1 << " "; cin >> array[i];
		}
		cout << "Search for ?: "; cin >> n;
		if (linear_search(array, m, n))
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
}

bool linear_search(int arr[], int m ,int n) {
	if (m == 0)
		return false;
	if (arr[m] == n)
		return true;
	else
		return linear_search(arr, m - 1, n);

	
}
int int_get(string s) {
	string temp;
	cout << s << " > ";
	cin >> temp;
	cin.ignore();
	while (!isdigit(stoi(temp))) {
		cout << "sorry " << temp << "Is not a number" << endl;
		cin >> temp;
		cin.ignore();
	}

	return stoi(temp);
}