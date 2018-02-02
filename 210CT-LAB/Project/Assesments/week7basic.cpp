#include<iostream>
#include<string>
using namespace std;

const int NODES = 5;

class Node {
public:
	int value;
	Node(int v) {
		value = v;
	}
	int getValue() {
		return value;
	}
	void setValue(int v) {
		value = v;
	}
};

int graph[NODES][NODES];
int main() {
	
	for (int i = 0; i < NODES; i++) {
		for (int j = 0; j < NODES; j++)
			graph[i][j] = connected(i,j);
	}

	
	for (int i = 0; i < NODES; i++) {
		for (int j = 0; j < NODES; j++)
			cout << graph[i][j] << endl;
	}



	return 0;
	

}

bool connected(int i, int j) {
	int n;
	cout << "\nIs node " << i << "connected to node " << j << " ? 0/1";
	cin >> n;
	cin.ignore();
	while (n != 1 || n != 0) {
		cout << "\nIncorrect input, must be either 1(true) or 0(false)";
		cout << "\nIs node " << i << "connected to node " << j << " ? 0/1";
		cin >> n;
		cin.ignore();
	}

	if (n)
		return true;
	else if (!n)
		return false;

}