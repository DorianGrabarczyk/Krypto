#include <iostream>
#include <cstdio>
using namespace std;

int odwrotnoscModularna(int liczba, int modulo) // n * coœ = 1 (mod m)
{
	int leftA = 1, leftB = 0, righA = 0, rightB = 1;
	int i = 0;
	int temp, mod = modulo;
	while (liczba % modulo)
	{
		if (!i) {
			leftA -= liczba / modulo * righA;
			leftB -= liczba / modulo * rightB;
		}
		else {
			righA -= liczba / modulo * leftA;
			rightB -= liczba / modulo * leftA;
		}
		i = !i;
		temp = liczba, liczba = modulo, modulo = temp % modulo;
	}
	if (i)
		return (leftA%mod + mod) % mod;
	return(righA%mod + mod) % mod;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int cases = 0, p, e, i,d;
	while (scanf("%d %d %d %d", &p, &e, &i, &d) == 4)
	{
		if (p < 0) break;
		int days;
		days = p * odwrotnoscModularna(28 * 33, 23) * 28 * 33 + e * odwrotnoscModularna(23 * 33, 28) * 23 * 33 + i * odwrotnoscModularna(23 * 28, 33) * 23 * 28 - d;
		days += 21251;
		days %= 21252;

		printf("Case %d: the next triple peak aoccurs in %d days.\n", ++cases, days+1);
	}
	return 0;

}
