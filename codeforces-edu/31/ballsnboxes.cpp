#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<ull> vi;
typedef priority_queue<ull, vi,greater<ull> > qq;

const int INF = 1e7;
qq q;
int n;


int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i< n;i++) {
        int a;
        cin >> a;
        q.push(a);
    }

    if(n == 1) {
        cout << 0;
        return 0;
    }


    ull a;
    ull s = 0;
    if (n % 2 == 0) {
        a = q.top();
        q.pop();
        a += q.top();
        q.pop();
        q.push(a);
    } else  {
        a = q.top();
        q.pop();
        a += q.top();
        q.pop();
        a += q.top();
        q.pop();
        q.push(a);
    }

    s += a;


    while(q.size()!=1) {
        a = q.top();
        q.pop();
        a += q.top();
        q.pop();
        a += q.top();
        q.pop();
        q.push(a);
        s += a;
    }

    cout << s;

    return 0;
}

