/*
Print all pairs in an array that sum up to a given value

*/

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void printPairs(vector<int> vec, int target)
{
	unordered_map<int, int> secondToIndexMap;
	for (size_t i = 0; i < vec.size(); ++i)
	{
		int second = target - vec[i];
		auto record = secondToIndexMap.find(vec[i]);
		if (record == secondToIndexMap.end())
		{
			secondToIndexMap[second] = i;
		}
		else
		{
			cout << "( " << vec[record->second] << " , " << vec[i] << " )" <<endl;
		}
	}

}

int main()
{
	vector<int> input{ 1,-5,5,8,9,3,6,0,2,-2,-4 , 3, -1};
	printPairs(input, 4);
	return 0;

}
