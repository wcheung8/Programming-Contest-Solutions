#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;
vi a(100000);
vi b(100000,-1);
priority_queue<int> cc;

int main() {
    ios::sync_with_stdio(0);
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    for(int i = 0; i < n; i++) {

        int x = a[i];
        int c = 1;
        if(b[i] == -1){
            b[i]=0;
            while(x != i){
                b[x]=0;
                x = a[x];
                c++;
            }
            cc.push(c);
        }

    }
    if(cc.size() == 1){
        cout << fixed<< (unsigned long long)(pow(cc.top(),2));
        return 0;
    }

    ull a = cc.top();
    cc.pop();
    a+=cc.top();
    cc.pop();

    a *=a;
    while(!cc.empty()) {
        a+= cc.top() * cc.top();
        cc.pop();
    }

    cout << fixed<< a;


    return 0;
}
