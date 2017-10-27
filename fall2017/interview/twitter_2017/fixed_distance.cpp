#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int INF = 1e7;

int n;
/*
 * Complete the function below.
 */
int fixedDistance(vector <int> a, int d) {

    set<int> s = set(1e5);

    for(int i = 0; i < a.size(); i++) {
        s.insert(a[i]);
    }

    int count = 0;
    for(int i = 0; i < a.size(); i++) {
        if(s.find(i+d) != s.end())
            count++;
    }

    return count;

}



int main() {

  return 0;
}

