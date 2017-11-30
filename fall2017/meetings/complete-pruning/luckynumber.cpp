// https://open.kattis.com/problems/luckynumber
#include "bits/stdc++.h"
using namespace std;

const int MAX = 1000;

int n;
int cnt = 0;
vector< int > current ;


bool isValid(int sz) {

    long long ans = 0;
    for (int i = 0; i < sz; i++) {
        ans *= 10LL;
        ans += current[i];
        ans %= sz;
    }
    return (ans % sz) == 0;

}

void generate(int position) {
    if((position > 0) && (!isValid(position))){
        return;
    }
    if (position == n) {
        cnt++;
        return;
    }

    for(int i = 0; i <= 9; i++) {
        if(i == 0 && position == 0)
            continue;
        current.push_back(i);
        generate(position+1);
        current.pop_back();
    }
}


int main() {

    cin >> n;
    generate(0);
    cout << cnt << endl;
}
