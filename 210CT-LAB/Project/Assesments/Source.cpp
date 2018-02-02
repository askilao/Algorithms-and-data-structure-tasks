#include<iostream>
#include<string>
using namespace std;

/*
Week 2 Coursework
Given the following pseudocode, first understand how it works, then implement the code for multiplying
the two polynomials in the programming language of your choice.
• Create a result array Res[], of size m + n + 1, where m is the degree of the first polynomial and n is
  the degree of the second polynomial
• Initialise all the array elements as 0
• For each element of P1 (corresponding to index i) and each element of P2 (corresponding to index
  j), perform the following operation
  res[i+j] = res[i+j] + P1[i]*P2[j], where i is the index for P1 and j is the index for P2.
  Hint: Use a nester FOR loop to traverse both arrays.
• Return res
*/

int int_get(string s);
void get_poly_numbers(int arr[], int n);
void calculate_poly(int arr[], int arr1[], int n, int min, int max);

int main() {
	int poly_min, poly_max; // To determine what degree is the highest and lowest
	int degree1 = int_get("Enter degree of first polynomial");
	int degree2 = int_get("Enter degree of second polynomial");
	int len = degree1 + degree2; //length for use in array later
	int* poly1 = new int[degree1 + 1]; //Create two int arrays with the polynomials
	int* poly2 = new int[degree2 + 1];

	//Determines what is the highest and lowest degree, if they are equal the else is executed
	if (degree1 < degree2) {
		poly_max = degree2;
		poly_min = degree1;
	}
	else {
		poly_max = degree2;
		poly_min = degree1;
	}
	// Asks user for the numbers in each polynomial, using a function
	cout << "\nPoly 1: " << endl;
	get_poly_numbers(poly1, degree1);
	cout << "\nPoly 2: " << endl;
	get_poly_numbers(poly2, degree2);

	//Calculates and prints the result of the multiplication of the polynomials
	//Takes the two poly arrays, the length of the result array and the two min and max previously determined as paramteres
	calculate_poly(poly1, poly2, len, poly_min, poly_max);


	//"Press any button to continue..."
	system("PAUSE");
	return 0;



}
//Fills the polynomial arrays from the keyboard
void get_poly_numbers(int arr[], int n) {
	for (int i = 0; i <= n; i++) {
		arr[i] = int_get("Enter nr ");

	}
}
//Calculates and prints result
void calculate_poly(int arr[], int arr1[], int n, int min, int max) {
	//Result array with the size og degree1+degree2+1 
	int* res = new int[n + 1];

	//Initializes every slot to 0
	for (int i = 0; i <= n; i++) {
		res[i] = 0;
	}
	//Multiplies the arrays, each for loop goes upto the highest degree of the polynomials
	for (int i = 0; i <= min; i++) {
		for (int j = 0; j <= max; j++) {
			res[i + j] = res[i + j] + arr[i] * arr1[j];
		}
	}
	cout << "Result: ";
	cout << "\nDegree: " << n << endl;
	for (int i = 0; i <= n; i++) {
		//Prints the result and adds the coefficients
		if (i < n )
		cout << res[i] << "x^(" << n - i << ") + ";
		else
			cout << res[i] << endl;
	}
	cout << endl;
}
//Input function previously created
int int_get(string s) {
	int temp;
	cout << s << " > ";
	cin >> temp;
	cin.ignore();
	return temp;
}
