#include <vector>
#include <iostream>

using namespace std;

#define MAXN   8000001
int spf[MAXN];
void sito()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
vector<int> faktoryzacja(int x)
{
    vector<int> v;
    if(x == 1)
        v.push_back(x);
    while (x != 1)
    {
        v.push_back(spf[x]);
        x = x / spf[x];
    }
    return v;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int ilosc,x;
    sito();
    cin>> ilosc;
    while(ilosc--)
    {
    cin >> x;
    vector <int> p = faktoryzacja(x);
    cout<<p[0];
    for (int i=1; i<p.size(); i++)
        cout << "*"<<p[i];
    cout << "\n";
    }
    return 0;
}
