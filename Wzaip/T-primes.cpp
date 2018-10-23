#include <iostream>
#include <set>
#include <vector>

using namespace std; 

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long int ilosc,liczba,i,j,n=1000001;

	vector<bool> pierwsze(1000001, true);
	set<long long int> tprime;
	pierwsze[0] = pierwsze[1] = false;

	//Sito
	for (i = 2; i*i <= n; i++)
	{
		if (pierwsze[i])
		{
			for (j = i; i*j <= n; j++)
			{
				pierwsze[i*j] = false;
			}
		}

	}

	for (i = 2; i <= n; i++)
	{
		if (pierwsze[i])
		  tprime.insert(i*i);
	}
	cin >> ilosc;
	while (ilosc >0)
	{
		cin >> liczba;
		if (tprime.find(liczba) != tprime.end())
			cout << "YES\n";
		else
			cout << "NO\n";
		ilosc--;
	}
}

