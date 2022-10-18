#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

// Print vector of strings
void printVector(vector<string> v) {
    fori(v.size()) {
        cout<< v[i];
        if (i != v.size() - 1) {
            cout<< "-";
        }
    }
    cout<< endl;
}

// Get string numberical value
// a = 1, b = 2, c = 3, ...
int getNum(string s) {
    int sum = 0;
    for(int i=0; i<s.size(); i++) {
        sum += (s[i] - 'a' + 1);
    }
    return sum;
}


int main() {

    string s;
    cin>> s;

    // Convert string to lowercase
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    // Split string as per delimiter '-'
    stringstream ss(s);
    string token;
    vector<string> tokens;
    while(getline(ss, token, '-')) {
        tokens.push_back(token);
    }

    // Sort tokens in alphabetical order
    sort(tokens.begin(), tokens.end(), [](string a, string b) {
        return a < b;
    });

    for(int i=0; i<tokens.size(); i++) {
        int val = getNum(tokens[i]);
        if (val % 2 == 0) {
            sort(tokens[i].begin(), tokens[i].end());
        } else {
            sort(tokens[i].begin(), tokens[i].end(), greater<char>());
        }
    }

    printVector(tokens);
}