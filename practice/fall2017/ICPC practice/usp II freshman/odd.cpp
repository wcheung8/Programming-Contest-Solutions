#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    ull s = 0;
    long a = 0;
    long minodd = -1;
    for(int i = 0; i < n; i ++) {

        cin >> a;
        if(a & 1 == 1)
            if(minodd == -1 || minodd > a)
                minodd = a;
        s += a;

    }

    if(s & 1 == 1)
        s -= minodd;

    cout << s;


    return 0;
}
