#include <iostream>
#include <vector>

using namespace std;

static int quickInversions = 0;

vector<int> quickmerge(vector<int> less, vector<int> equal, vector<int> more)
{
	vector<int> sorted;
	
	for(int i = 0; i < (int)less.size(); i++)
	{
		sorted.push_back((int)less[i]);
	}
	
	for(int i = 0; i < (int)equal.size(); i++)
	{
		sorted.push_back((int)equal[i]);
	}
	
	for(int i = 0; i < (int)more.size(); i++)
	{
		sorted.push_back((int)more[i]);
	}
	
	return sorted;
}

vector<int> quicksort(vector<int> vec)
{
	vector<int> smaller;
	vector<int> equal;
	vector<int> larger;
	
	if(vec.size() <= 1)
		return vec;
	
	for(int i = 0; i < (int)vec.size(); i++)
	{
		if((int)vec[i] < (int)vec[0])
		{
			smaller.push_back(vec[i]);
			quickInversions += (int)equal.size() + (int)larger.size();
		}
			
		else if((int)vec[i] > (int)vec[0])
			larger.push_back(vec[i]);
			
		else if((int)vec[i] == (int)vec[0])
			equal.push_back(vec[i]);
	}
	
	return quickmerge(quicksort(smaller), equal, quicksort(larger));
}

int main()
{
	vector<int> myvec;
	
	myvec.push_back(6);
	myvec.push_back(4);
	myvec.push_back(7);
	myvec.push_back(3);
	myvec.push_back(9);
	myvec.push_back(1);
	myvec.push_back(23);
	myvec.push_back(67);
	myvec.push_back(1);
	
	cout << "myvec: ";
	
	for(int i = 0; i < int(myvec.size()); i++)
	{
  		cout << myvec[i] << " ";
	}
	
	cout << endl;
	
	vector<int> mysorted = quicksort(myvec);
	
	for(int i = 0; i < int(mysorted.size()); i++)
	{
  		cout << mysorted[i] << " ";
	}
	
	cout << endl << "Inv: " << quickInversions;
	
	return 0;
}
