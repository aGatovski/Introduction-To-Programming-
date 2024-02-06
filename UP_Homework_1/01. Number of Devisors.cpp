#include <iostream>
using namespace std;

int specialPair = 0;

int numberOfDevisors(int n) {
	int countDevisors = 0;
	for (int i = 1; i <= n/2; i++)
	{
		if (n % i == 0) countDevisors++;
	}
	return countDevisors+1;
}

bool isSpecialPair(int k, int divisorsX, int divisorsY, int x, int y) {
	if (k * divisorsX * divisorsY == x * y) return true;
	return false;
}

int main()
{
	//cout << "Insert n and k";
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int numDevI = numberOfDevisors(i);
			int numDecJ = numberOfDevisors(j);
			if (isSpecialPair(k, numDevI, numDecJ, i, j)) specialPair++;
		}
	}
	cout << specialPair;
}
