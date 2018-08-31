/******************************
   Douglas Atkinson
   August 27, 2018
   main.cpp
   Display the sizes and addresses of various data types
********************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Function declarations
template<class T> void displayLine(string title, T & data);
void displayLineForPtrChar(string title, char * & data);

int main()
{
	// A bunch of meaningless variables
	// Primitives
	char aChar = 'A';
	short aShort = 2;
	int aInt = 4;
	long aLong = 6;
	long long aReallyLong = 8;
	float aCokeFloat = 10.25f;
	double trouble = 20.50;

	// Now for some pointer action
	char* pChar = &aChar;
	short* pShort = &aShort;
	int* pInt = &aInt;
	long* pLong = &aLong;
	long long* pReallyLong = &aReallyLong;
	float* pCokeFloat = &aCokeFloat;
	double *pTrouble = &trouble;
	int** ppInt = &pInt;

	// Display a pretty table (for the girls)
	cout << "Data type sizes and addresses\n\n";
	cout << setw(24) << "Data type\n";
	cout << setw(24) << "& variable name"
		<< setw(6) << "Size"
		<< setw(18) << "Address"
		<< setw(18) << "Value\n";

	// Display the primitives
	displayLine("char aChar", aChar);
	displayLine("short aShort", aShort);
	displayLine("int aInt", aInt);
	displayLine("long aLong", aLong);
	displayLine("long long aReallyLong", aReallyLong);
	displayLine("float aCokeFloat", aCokeFloat);
	displayLine("double trouble", trouble);

	// Display the pointers
    
	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}

template<class T>
void displayLine(string title, T & data)
{
	cout << setw(24) << title
		<< setw(6) << sizeof(data)
		<< setw(18) << static_cast<void*>(&data)
		<< setw(18) << data << endl;
}

void displayLineForPtrChar(string title, char *& data)
{
	cout << setw(24) << title
		<< setw(6) << sizeof(data)
		<< setw(18) << static_cast<void*>(&data)
		<< setw(18) << static_cast<void*>(data) << endl;
}
