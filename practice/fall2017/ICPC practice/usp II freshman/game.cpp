#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int a, b;
int aa, bb;

double d(int i, int j) {

    return sqrt(pow(i,2) + pow(j,2));
}

int main() {
    ios::sync_with_stdio(0);
    cin >> a >> b;
    cin >> aa >> bb;

    double q = d(a,b);
    double qq = d(aa, bb);
    if(q > qq){
        cout <<"Wil";
    } else if ( q < qq) {
        cout <<"Russo";
    } else
        cout <<"Empate";

    return 0;
}
