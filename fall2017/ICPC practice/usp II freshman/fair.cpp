#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++) {

        int a,b;
        cin >> a >> b;

        if(abs(a-b) <= 1)
            cout << "Ok" << endl;
        else
            cout << (a+b)/2 << " " << (a+b)/2 + (a+b) %2 << endl;

    }

    return 0;
}
