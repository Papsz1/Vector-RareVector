#include <iostream>
#include "VVector.h"
#include "RareVVector.h"

using namespace std;

int main()
{	
	cout << "--------VVector--------" << endl;
	try {

		VVector<int> v1(10);
		int a[] = { 10, 35, 43, 1, 4 };
		VVector<int> v2(a, 5);
		VVector<int> v3(v2);
		VVector<int> v4(v2 + v3);
		VVector<int> v5(v2 - v3);

		cout << "Constructor with one parameter: " << endl;
		for (int i = 0; i < 10; i++)
		{
			cout << v1[i] << " ";
		}

		cout << endl << "Constructor with two parameters: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << v2[i] << " ";
		}

		cout << endl << "Copy constructor: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << v3[i] << " ";
		}

		cout << endl << "Addition: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << v4[i] << " ";
		}

		cout << endl << "Subtraction: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << v5[i] << " ";
		}

		cout << endl << "Scalar product: " << endl;
		double product = v2 * v3;
		cout << product;

		cout << endl << "Euclidean norm: " << endl;
		double eucl = ~v2;
		cout << eucl;

		cout << endl << "Euclidean distance: " << endl;
		double distance = v2 % v3;
		cout << distance;

	}

	catch (const char* s) {
		cout << endl << s << endl;
	}


	cout << endl << "--------RareVVector--------" << endl;
	
	try {
		int a[] = { 10, 35, 43, 1, 4 };

		RareVVector<int> r1(10);
		RareVVector<int> r2(a, 5);
		RareVVector<int> r3(r2);
		RareVVector<int> r4(r2 + r3);
		RareVVector<int> r5(r2 - r3);


		cout << "Constructor with one parameter: " << endl;
		for (int i = 0; i < 1; i++)
		{
			cout << r1[i] << " ";
		}

		cout << endl << "Constructor with two parameters: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << r2[i] << " ";
		}

		cout << endl << "Copy constructor: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << r3[i] << " ";
		}

		cout << endl << "Addition: " << endl;
		for (int i = 0; i < 5; i++)
		{
			cout << r4[i] << " ";
		}

		cout << endl << "Subtraction: " << endl;
		for (int i = 0; i < 0; i++)
		{
			cout << r5[i] << " ";
		}

		cout << endl << "Scalar product: " << endl;
		double product = r2 * r3;
		cout << product;

		cout << endl << "Euclidean norm: " << endl;
		double eucl = ~r2;
		cout << eucl;

		cout << endl << "Euclidean distance: " << endl;
		double distance = r2 % r3;
		cout << distance;
	}
	catch (const char* s) {
		cout << endl << s << endl;
	}

	try {
		int a[] = { 10, 35, 20, 1, 4 };
		VVector<int> v1(a, 5);
		RareVVector<int> r1(a, 5);

		VVector<int> v_conversion(r1);
		RareVVector<int> r_conversion(v1);

		cout << endl << "Creating a vector from a rare vector: " << endl;
		for (int i = 0; i < 5; i++)
			cout << v_conversion[i] << " ";

		cout << endl << "Creating a rare vector from a vector: " << endl;
		for (int i = 0; i < 5; i++)
			cout << r_conversion[i] << " ";
			

	}
	catch (const char* s) {
		cout << endl << s << endl;
	}

}

