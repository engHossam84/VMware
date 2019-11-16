
#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
	if (num > 1)
	{
		for (size_t i = 2; i * i <= (num); ++i)
		{
			if (num % i == 0)
				return false;
		}
		return true;
	}
	

}

void print(bool prime)
{
	if (prime)
		cout << "PRIME " << endl;
	else 
		cout << "NOT PRIME " << endl;
}

int main()
{
	vector<int> input{ 9, 1,3,4,6,11,12,13 };
	for (auto elem : input)
	{
		cout << elem << " is ";
		print(isPrime(elem));
	}
	return 0;
}
