#include <bits/stdc++.h>
#define ull unsigned long long
#define f(i, n) for(int (i) = 0; (i) < (n); i++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
typedef map<int, int> mi;

const int INF = 1e6+50;

int q[10][INF];
int dp[INF];
int n;




void precompute() {
    for(int i = 1; i < 10; i++) {
        for(int j = i; j < 10; j++)
            q[i][j] = 1;
        dp[i] = i;
    }
    for(int i = 10; i <= 1e6; i++) {
        int num = i;
        int x = 1;
        while (num != 0) {
            if (num%10 != 0)
                x *= (num % 10);
            num = num / 10;
        }
        dp[i] = dp[x];

        for(int j = 1; j < 10; j++) {
            q[j][i] = q[j][i-1];
            if(dp[i] == j)
                q[j][i]++;
        }
    }


}


int main() {

    ios::sync_with_stdio(0);

    precompute();

    cin >> n;
    f(i, n) {
        int l, r, k;
        cin >> l >> r >> k;

        cout << q[k][r]-q[k][l-1]<< endl;

    }




    return 0;
}
