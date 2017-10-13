//https://open.kattis.com/problems/wordladder2
#include "bits/stdc++.h"
using namespace std;

const int MAX = 1000;

int n;
int cnt = 0;
vector< vector<int> > adj;
vector< vector<int> > special_adj;
map<string,int> dict;
vector<string> words;

int check(string a, string b) {
    if (a.length() != b.length())
        return 0;

    int counter = 0;
    counter++;
    for(int i = 0; i < a.length(); i++) {
            if(a[i] != b[i])
                counter++;
    }
    return counter;
}

void get_edges() {

    for(int i = 0; i < words.size(); i++) {
        for(int j = i+1; j < words.size(); j++) {
            string a = words[i];
            string b = words[j];

            int diff = check(a,b);

        }
    }

}

int main() {

    cin >> n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        words.push_back(s);
        dict[s] = i;
    }

    // construct graph from words
    get_edges();

    // breadth first search until target is found


}
