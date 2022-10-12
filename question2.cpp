#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

int expressionSum(int code){
    int value = 0, number = 0, power = 1;
    for(int k = 9; k >= 1; k--){
        number = power*k + number;
        switch( code % 3 ) {
            case 0:
                // Add
                value += number;
                break;
            case 1:
                // Subtract
                value -= number;
                break;
            case 2:
                // Join
                power = power * 10;
                break;
        }
        if (code % 3 != 2){
            number = 0;
            power = 1;
        }
        code /= 3;
    }
    return value;
}

void print(int code, int requiredSum){
    string result;
    
    for(int k = 9; k >= 1; k--){
        char c = '0' + k;
        result += c;
        switch( code % 3 ) {
            case 0:
                // Add
                // If k is the first number, it's already positive
                if (k > 1) result += "+";
                break;
            case 1: 
                // Subtract
                result += "-"; break;
            case 2: 
            // For joining the numbers we can just append the number to the string
            break;
        }
        code /= 3;
        
    }
    reverse(result.begin(), result.end());
    cout<< result << " = " << requiredSum << endl;
}

void solve() {
    // Number of expressions possible = 2 * (3**8) = 13122
    // Other than the first digit all other digits have a possibility of 3 choices
    // First digit only have two choices
    const int nExpr = 13122;
    cout<< "Expression from digits 123456789 evaluating to 100" << endl;

    fori(nExpr){
        if (expressionSum(i) == 100){
            print(i, 100);
        }
    }
}

int main(void){
    cout<< "Program to print all possible expressions from digits 123456789 evaluating to 100" << endl;
    solve();
    return true;
}
