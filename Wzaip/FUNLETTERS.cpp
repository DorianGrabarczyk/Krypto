#include <iostream>
#include <vector>

using namespace std;

const unsigned long long int silinie[17] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000 };


int getIndex(char litera, vector<char> _vector)
{
	for (int i = 0; i < _vector.size(); i++)
		if (_vector[i] == litera)
			return i;
}
unsigned long long int numerPermutacji(string charRow)
{
	unsigned long long int result = 0;
	int dlugosc = charRow.length();
	int tmp;
	vector<char> chars = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o' };
	result += ((int)charRow[0] - 97)*silinie[dlugosc - 1];
	chars.erase(chars.begin() + getIndex(charRow[0], chars));
	for (int i = 1; i < dlugosc - 1; i++)
	{
		tmp = getIndex(charRow[i], chars);
		result += tmp * silinie[dlugosc - 1 - i];
		chars.erase(chars.begin() + tmp);
	}
	return result;
}

string getPermutationString(unsigned long long int number, int length)
{
	string result = "";
	vector<char> litery = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o' };
	int index;
	do
	{
		index = 0;
		while (index * silinie[length - 1 - result.length()] <= number)
			index++;
		number -= (index - 1) * silinie[length - 1 - result.length()];
		result += litery[index - 1];
		litery.erase(litery.begin() + index - 1);
	} while (result.length() < length);
	return result;
}


int main()
{
	std::ios::sync_with_stdio(false);

	int n;
	cin >> n;

	string charRow;
	unsigned long long int number, nextNumber;

	for (int i = 0; i < n; i++)
	{
		cin >> charRow;
		cin >> nextNumber;

		number = numerPermutacji(charRow) + nextNumber;

		cout << getPermutationString(number, charRow.length()) << "\n";
	}

	return 0;
}
