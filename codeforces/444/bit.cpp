#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef priority_queue<pi, vector<pi>, greater<pi> > q;

const int INF = 1e7;

vi a;
string n;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    int c = 0;
    int flag = 0;
    for(unsigned int i = 0; i < n.size(); i++) {
        if (n[i] == '0' && flag)
            c++;
        if(n[i] != '0')
            flag = 1;
    }

    if(c >= 6)
        cout << "yes";
    else
        cout << "no";
    return 0;
}
