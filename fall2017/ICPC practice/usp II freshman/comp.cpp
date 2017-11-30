#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;
vi a(4);

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        int aa;

        cin >> aa;

        a[i%4] += aa;

    }
    int m = 0;
    for(int i = 1; i < 4; i++) {
        if(a[m] < a[i])
            m = i;
    }

    switch(m) {
    case 0 : cout << 'A'; // prints "1"
             break;       // and exits the switch
    case 1 : cout << 'B';
             break;
     case 2 : cout << 'C'; // prints "1"
             break;       // and exits the switch
    case 3 : cout << 'D';
             break;
}
    return 0;
}
