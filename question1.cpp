#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

// Check if strings are anagrams
// Complexity: O(n)
// Operations on map takes O(1) time and operations are done n times where n = length of string 1
// Other solutions:
// 1. Sort both strings and compare them (Complexity: O(nlogn))
// 2. Using a hash table to store the count of each character in string 1 and then decrementing the count for each character in string 2 (Complexity: O(n))
bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int frequency1[26] = {0}, frequency2[26] = {0};
    for (int i=0; i < s1.length(); i++) {
        frequency1[s1[i] - 'a']++;
        frequency2[s2[i] - 'a']++;
    }

    for (int i=0; i < s1.length(); i++) {
        if (frequency1[s1[i] - 'a'] != frequency2[s1[i] - 'a']) {
            return false;
        }
    }

    return true;
}

void solve(string s1, string s2) {
    if (isAnagram(s1, s2)) {
        cout << "Anagrams" << endl;
    } else {
        cout << "Not Anagrams" << endl;
    }
}
    
int main () {
    cout<< "Program to check if two strings are anagrams" << endl;
    
    cout<< "Run test cases? (y/n): ";
    char c;
    cin >> c;

    if (c == 'y' || c == 'Y') {
        vector<string> s1 = {"anagram", "anagramm", "anagramm", "cat", "mathematics", "mathematics"};
        vector<string> s2 = {"margana", "marganaa", "marganaa", "act", "mathematics", "mathematic"};
        vector<bool> ans = {true, false, false, true, true, false};

        fori(s1.size()) {
            assert(isAnagram(s1[i], s2[i]) == ans[i]);
        }
        cout<< "All test cases passed" << endl;
    }

    cout<< "Run program using custom input? (y/n): ";
    cin >> c;

    if (c == 'y' || c == 'Y') {
        string s1, s2;
        cout << "Enter string 1: ";
        cin >> s1;
        cout << "Enter string 2: ";
        cin >> s2;
        solve(s1, s2);
    }
}