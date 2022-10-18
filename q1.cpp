#include<bits/stdc++.h>

using namespace std;
#define ll double
#define fori(n) for(int i=0; i<n; i++)

int main() {
    ll N, r, S, BT;
  
    cin>> N>> r>> S>> BT;

    ll x; // G
  
    // T = (G - S)*r/100 + BT
    // T = x * r/100 - S*r/100 + BT
    // T = (x * c1) - c2
  
    ll c2 = (S*(r/100)) - BT;
    ll c1 = r/100;
    // N = G - F
    // N = G - T + (T*T)/G
    // N * x = x * x - (x * x* c1) + x*c2 + (((x * c1) - c2) * ((x * c1) - c2))
    // 0 = x * x (1 - c1) + x * (c2 - N) + x * x * (c1 * c1) - 2 * c1 * c2 * x + c2 * c2
    // 0 = x * x * ((c1 * c1) + 1 - c1) + x * (c2 - N - 2 * c1 * c2) + c2 * c2
    // 0 = x * x * c3 + x * c4 + c5
  
    ll c3 = (c1 * c1) + 1 - c1;
    ll c4 = c2 - N - (2 * c1 * c2);
    ll c5 = c2 * c2;

    // Polynomial solution
    // x = [-b ± √(b2 – 4ac)]/2a.

    // x = [-c4 ± √c6]/23

    ll c6 = (c4 * c4)  - 4 * c3 * c5;
  
    if (c6 < 0) {
        cout<< "No solution" << endl;
        return 0;
    }
  
    ll c7 = sqrt(c6);

    ll r1 = ((-1 * c4) + c7) / (2 * c3); 

    ll r2 = ((-1 * c4) - c7) / (2 * c3); 
    ll G;
    if (r1 >= N) {
        G = r1;
    } else {
        G = r1 > r2 ? r1 : r2;
    }

    ll T = (G * c1) - c2;

    ll value = ceil(T * 100) / 100;
    // Set precision to 2 decimal places
    cout<< fixed<< setprecision(2);
    cout<< value<< endl;
    return 1;
}