#include <iostream>
#include <cstdlib>
#include <cstdio>

#define rozmiar 1000001

using namespace std;

bool result[rozmiar];
int potegi[1001];

int main() {
	result[0] = false;
	fill(result, result + rozmiar, false);

	for (int i = 1; i < 1001; i++)
		potegi[i] = i * i;
	for (int i = 1; i < rozmiar; i++) {
		for (int j = 1; potegi[j] <= i; j++) {
			result[i] = result[i] |  (!result[i - potegi[j]]);
			if (result[i])
				break;
		}
	}
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;		
		if(result[n] == true)
            cout<<"Win \n";
        else
            cout<<"Lose \n";		
	}
	return 0;
}
