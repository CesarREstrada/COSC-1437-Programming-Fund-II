/*******************************************************
   Cesar Estrada
   August 27, 2018
   DataTypeSize.cpp
   Display the sizes and addresses of carious data types
********************************************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
using namespace std;

// Function declarations
template <class T> void displayLine(string title, T & data);   // makes it easier to display data. only have to write code once it does the work for you.
void displayLineForPtrChar(string title, char * data);

int main()
{
	// Declare a bunch of meaningless variable
	// Primitives
	char aChar = 'A';
	short aShort = 2;
	int aInt = 4;
	long aLong = 6;
	long long aReallyLong = 8;
	float aCokeFloat = 10.25F;
	double trouble = 20.50;

	// Now for some pointer action
	char * pchar = &aChar;
	short * pShort = &aShort;
	int * pInt = &aInt;
	long * pLong = &aLong;
	long long * pReallyLong = &aReallyLong;
	float * pCokeFloat = &aCokeFloat;
	double * pTrouble = &trouble;
	int ** ppInt = &pInt;

	// Display a pretty table (for the girls)
	cout << "Data type sizes and addresses\n\n";
	cout << setw(24) << "Data type\n";
		cout << setw(24) << "& variable name"
		<< setw(6) << "Size"
		<< setw(18) << "Address"
		<< setw(18) << "Value\n";

	// Display  the primitives
	displayLine("char aChar", aChar);
	displayLine("short aShort", aShort);
	displayLine("int aInt", aInt);
	displayLine("long aLong", aLong);
	displayLine("long long aReallylong", aReallyLong);
	displayLine("float aCokeFloat", aCokeFloat);
	displayLine("double trouble", trouble);
	cout << endl;

	// Display the pointers
	displayLineForPtrChar("char * pChar", pchar);
	displayLine("short * pShort", pShort);
	displayLine("int * pInt", pInt);
	displayLine("long * pLong", pLong);
	displayLine("long long * pReallylong", pReallyLong);
	displayLine("float * pCokeFloat", pCokeFloat);
	displayLine("double * ptrouble", pTrouble);
	displayLine("int ** ppInt", ppInt);
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

// 
template<class T>
void displayLine(string title, T & data) // data is a reference to T (any data type but char) "RAW address or Void addres"
{
	cout << setw(24) << title
		<< setw(6) << sizeof(data)
		<< setw(18) << static_cast<void*>(&data) // displays the address of data
		<< setw(18) << data << endl;			 // diplays the contents of data
}

//
void displayLineForPtrChar(string title, char * data) // taking a reference from a char
{
	cout << setw(24) << title
		<< setw(6) << sizeof(data)
		<< setw(18) << static_cast<void*>(&data) 
		<< setw(18) << static_cast<void*>(data) << endl;
}
