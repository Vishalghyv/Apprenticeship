#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

string multiply(string num1, string num2) {
    string result(num1.size() + num2.size(), '0');
    
    for (int i = num1.size() - 1; 0 <= i; --i) {
        int carry = 0;
        for (int j = num2.size() - 1; 0 <= j; --j) {
            int tmp = (result[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
            result[i + j + 1] = tmp % 10 + '0';
            carry = tmp / 10;
        }
        result[i] += carry;
    }
    
    size_t startpos = result.find_first_not_of("0");
    if (string::npos != startpos) {
        return result.substr(startpos);
    }
    return "0";
}

int main() {
    string s1, s2;

    cin>> s1>> s2;
    // s1 = "-91341696911863743156";
    // s2 = "-16674061847985637946";

    int sign = 1;
    // Check if either of s1 or s2 contain - or .
    if (s1[0] == '-' || s2[0] == '-') {
        sign = -1;
        if (s1[0] == '-' && s2[0] == '-') {
            sign = 1;
            s1 = s1.substr(1);
            s2 = s2.substr(1);
        } else {
            if (s1[0] == '-') {
                s1 = s1.substr(1);
            } else {
                s2 = s2.substr(1);
            }
        }
    }
    if (sign == -1) {
        cout<< "-";
    }

    cout<< multiply(s1, s2)<< endl;
}