#include <bits/stdc++.h>
using namespace std;

int isPerfectSquare(long double x)
{
	int res = -1;
	bool checker = false;
	if (x >= 0)
	{
		long long sr = sqrt(x);
		if (sr * sr == x)
		{
			checker = true;
			res = sr - 1;
			return res;
		}
		else
		{
			while(checker == false){
				x--;
				long long sr = sqrt(x);
				if (sr * sr == x)
				{
					checker = true;
					res = sr;
					return res;
				}
			}
		}
	}
	return res;
}

int main()
{
	long long x = 2502;
	int squareRoot = isPerfectSquare(x);
	cout << "squaroot of x is " << squareRoot << endl;
	return 0;
}
