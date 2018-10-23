#include <iostream>
#include <map>

using namespace std;
int main()
{
    long long liczba, i;
	while (true)
	{
		cin >> liczba;
		if(liczba == 0)
            break;
        map <long long, int> _map;
        map <long long, int>::iterator _iterator;
		for (i = 2; i*i <= liczba; i++)
		{
			while (liczba%i == 0)
			{
				_map[i]++;
				liczba /= i;
			}
		}
		if (liczba != 1) _map[liczba]++;
		for(_iterator = _map.begin();_iterator!= _map.end();_iterator++)
            cout << _iterator->first << "^" << _iterator->second << " ";
		cout << "\n";
	}
	return 0;
}
