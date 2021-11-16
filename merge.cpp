// basic file operations
//#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int MAX = 10000;




//-------------------------------------------------------------------------------------------------
//Merge-Sort Code

int mergeSort(vector<int> &left, vector<int> &right, vector<int> &unsorted)
{
	int lsize = left.size();
	int rsize = right.size();

	int i, j, k, count;
	i = 0;
	j = 0;
	k = 0;
	count = 0;

	while (j < lsize && k < rsize)
	{
		if (left[j] <= right[k])	// If the left vector's element is less than or equal to right, it is in the correct position and is simply moved over to new vector.
		{
			unsorted[i] = left[j];
			j++;
		}
		
		else						// Otherwise, the right must be greater than the current and an inversion takes place. Thus the inversion counter is increased by 1.
		{
			unsorted[i] = right[k];
			count+= left.size() - j;
			cout << endl << "Count: " << count << " ";
			k++;
		}
		i++;						// After an iteration, continue to next element in the unsorted vector.
	}

	while (j < lsize)				// After one of the two conditions earlier were met, add remaining members for left and right vectors to unsorted in natural order.
	{
		unsorted[i] = left[j];
		i++;
		j++;
	}

	while (k < rsize)
	{
		unsorted[i] = right[k];
		i++;
		k++;
	}
	return count;
}

// Recursively unsorted vector in 2 pieces until their size is <= 1. Then they return the number of inversions from each call of merge which are added up into inversions.
int merge(vector<int> &unsorted)
{
	// If the input vector is <= 1, the inversions are trivially 0 because the vector is already sorted.
	if (unsorted.size() <= 1)
		return 0;

	int inversions = 0;
	int mid = 0;
	mid = unsorted.size() / 2;

	vector<int> right;
	vector<int> left;

	// Making left vector from 0 to mid of unsorted.
	for (int i = 0; i < mid; i++)
	{
		left.push_back(unsorted[i]);
		cout << left[i] << " ";
	}
	
	cout << endl;
	
	// Making right vector from mid to unsorted.size() of unsorted.
	for (int i = 0; i < unsorted.size() - mid; i++)
	{
		right.push_back(unsorted[mid + i]);
		cout << right[i] << " ";
	}
	
	cout << endl;

	inversions = merge(left) + merge(right) + mergeSort(left,right,unsorted);
	
	cout << endl << "INV: " << inversions << endl;

	return inversions;
}

//---------------------------------------------------------------------------


int main()
{
	vector<int> go;
	go.push_back(23);
	go.push_back(4);
	go.push_back(5);
	go.push_back(1);
	go.push_back(7);
	go.push_back(19);
	go.push_back(13);
	go.push_back(1);
	
	for(int i = 0; i < go.size(); i++)
		cout << go[i] << " ";
		
	cout << endl;
	
	int inv = merge(go);
	cout << inv << endl;
	
	for(int i = 0; i < go.size(); i++)
		cout << go[i] << " ";
	
	return 0;
}
