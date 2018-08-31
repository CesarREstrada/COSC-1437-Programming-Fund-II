/************************************************************************
   Cesar Estrada
   August 29, 2018
   DonationSorter.cpp
   Program Adapted from prof 9-3 on page 539 of text book
   Program asks user for number of donations, get the donations,
   and then sorts in acsending order.

   You could just create array and create a second array to keep the
   orginal order of first array. This program is used for better
   understanding of pointers
*************************************************************************/

// Headers
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// Function declarations
void arrSelectionSort(int** ptrToElems, int size);
void displayDonations(int* donations, int size);   //pointer to an array of integers
void displaySortedDonations(int** ptrToElems, int size); //double pointer that points to an pointer that point to integers
int** createPtrArray(int* donations, int size); // creats the link between sorted and donations
int* getDonations(int size); // adds values to the pointers of sorted and Donations


int main()
{
	//	Your code goes here
    
    
	//	Make sure we place the end message on a new line
    cout << endl;

	//	The following is system dependent.  It will only work on Windows
    // system("PAUSE");

	/* 
	// A non-system dependent method is below
	cout << "Press any key to continue";
	cin.get();
	*/
    return 0;
}

// sort the pointer values in pttToElems
void arrSelectionSort(int ** ptrToElems, int size)
{
	int startScan,			// where we start searching from
		minIndex;			// which index contain the smallest
	int* ptrMinElem;		// point to the Element with the smallest values

	for (startScan = 0; startScan < size - 1; startScan++)
	{
		minIndex = startScan;
		ptrMinElem = *(ptrToElems + startScan);		// contains the address of the smallest element
		for (int index = startScan + 1; index < size; index++)
		{
			if (*(*(ptrToElems + index)) < *ptrMinElem)
			{
				ptrMinElem = *(ptrToElems + index);
				minIndex = index;
			}
		}
		*(ptrToElems + minIndex) = *(ptrToElems + startScan); // this does some swapping to put in ascending order
		*(ptrToElems + startScan) = ptrMinElem;				  // swapping as well
	}
}

// displays the donations
void displayDonations(int * donations, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(donations + i) << endl;
	}
}

// display the donation in sorted ordered
void displaySortedDonations(int ** ptrToElems, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(*(ptrToElems)) << endl;
	}
}

// Create an array of pointers to ints
// Each element in array will point to an element in donations
int ** createPtrArray(int * donations, int size)
{
	int** ptrDonations = new int*[size];

	for (int i = 0; i < size; i++)
	{
		*(ptrDonations + 1) = (donations + 1);
	}
	return ptrDonations;
}

// gets the donation from the user, saves them to a dynamic array
// returns the address of the dynamic arrat
int * getDonations(int size)
{
	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Enter amount for donation " << i + 1 << ": ";
		cin >> *(arr + i); // arr[i]
	}
	return arr;
}
