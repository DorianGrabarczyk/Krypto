
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int liczbaDomkow,wysokosc,plakat=0;
	stack<int> stosik;
	cin >> liczbaDomkow >> wysokosc >> wysokosc;
	stosik.push(wysokosc);
	while (liczbaDomkow - 1)
	{
		cin >> wysokosc >> wysokosc;
		while (wysokosc < stosik.top())	
		{
			plakat++;
			stosik.pop();
			if (stosik.empty()) stosik.push(wysokosc);
		}
		if(wysokosc > stosik.top())
		{
			stosik.push(wysokosc);
		}
		liczbaDomkow--;
	}
	plakat += stosik.size();
	cout << plakat;
}