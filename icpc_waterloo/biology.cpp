#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int a,b;
int c,cc,d,dd;
int m;
vi asdf;
int choose (int n, int k)
{

if ( k < 0 || n < 0)
    return 0;

    if(k>n)
        return 0;

    int x = 1;
    for(int i = n; i > k ; i--)
    {
        x *= i;
    }

    for (int i = 2; i <= n-k; i++)
    {
        x /= i;
    }

    return x;

}

string s = "";

int main()
{
    for(int i = 0; i < a; i ++) {

    }

    return 0;
}
