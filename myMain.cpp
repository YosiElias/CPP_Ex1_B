#include "mat.hpp"

#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
	int row, col;
	char a, b;
	cout<<"Enter number of rows:\n";
	cin>>row;
	cout<<"Enter number of colmns:\n";
	cin>>col;
	cout<<"Enter the first char:\n";
	cin>>a;
	cout<<"Enter the second char:\n";
	cin>>b;
	try {
		cout << ariel::mat(col, row, a, b) << endl;
	}
	catch (exception& ex) {
	 	cout << "---> caught exception: " << ex.what() << endl;  // should print the exception
	}
}