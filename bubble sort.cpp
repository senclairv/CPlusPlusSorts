// C++ program for implementation of Bubble sort
#include <iostream>
#include <vector>

using namespace std;

static int bubbleInversions = 0;
 
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
    
    bubbleInversions++;
}
 
// A function to implement bubble sort
void bubbleSort(vector<int> arr)
{
   int i, j;
   for (i = 0; i < arr.size() - 1; i++)
       for (j = 0; j < arr.size() - i - 1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}
 
/* Function to print an array */
void printArray(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
}
 
// Driver program to test above functions
int main()
{
    vector<int> arr;
    arr.push_back(64);
    arr.push_back(34);
    arr.push_back(25);
    arr.push_back(12);
    arr.push_back(22);
    arr.push_back(11);
    arr.push_back(90);
    arr.push_back(1);
    bubbleSort(arr);
    cout << "Sorted array: " << endl;
    printArray(arr);
	cout << endl << "Inversions: " << bubbleInversions;
    return 0;
}
