// Codeforces 100812 D
// Dream of Sum

#include "bits/stdc++.h"
using namespace std;

// 8
// 1 3 -2 -1 -5 2 2 1

const int MAX = 200005;

int n;
int arr[MAX];
long long prefix_sums[MAX]; // Need long longs here.
map < long long, int > pos; // Store the position of each prefix sum.

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) { // O(n)
        scanf("%d", &arr[i]);
        prefix_sums[i] = prefix_sums[i - 1] + arr[i];
    }
    int sol_l = -1, sol_r = -1, sol_len = n + 2;
    pos[0] = 0; // The empty list by definition has sum zero.
    for (int i = 1; i <= n; i++) { // All of this is O(n log n)
        // The log(n) is because we update the map each time, each update takes O(log n)
        // If this current prefix sum exists in the map,
        // Basically, we have found an index (j) where j < i
        // which has the same value as prefix_sums[i].
        if (pos.find(prefix_sums[i]) != pos.end()) {
            int l = pos[prefix_sums[i]];
            if (i - l < sol_len) { // To find minimum length answer
                sol_len = i - l;
                sol_l = l + 1;
                sol_r = i;
            }
        }
        // Update the map to store the largest index which has the sum
        pos[prefix_sums[i]] = i;
    }
    if (sol_l == -1) {
        printf("-1\n");
    } else {
        printf("%d %d\n", sol_l, sol_len);
    }
}
