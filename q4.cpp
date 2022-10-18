#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define fori(n) for(int i=0; i<n; i++)

int main() {
    // V = pi * r * H**2 - pi/3 * H**3

    double r, V;
    // cin>> r>> V;
    // 9.4101888
    // 2526.5557948 
    r = 9.4101888;
    V = 2526.5557948;
    cout<< setprecision(10);

    double pi = 3.14159265358979323846;
    // Calculate H

    // Binary search for H
    double low = 0, high = r + r, mid, val;

    mid = (low + high) / 2;
    val = (pi * mid * mid) * ((r ) - (mid /3));

    double deviation = 1e-10;
    while (!(fabs(val - V) <= deviation)) {
        mid = (low + high) / 2;
        val = (pi * mid * mid) * ((r) - (mid /3));
        if (val > V) {
            high = mid;
        } else {
            low = mid;
        }
    }
    cout<< mid<< endl;
    cout<< val<< " " << V<< endl;
    double value = round(mid * 10000000) / 10000000;
    cout << value<<  endl;





}