#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define MOD 1000
using namespace std;
int poww(long  a, long b) {
    int ans = 1;
    int k = (a*a) % MOD;
    if (b == 0)
        return 1;
    if (b % 2 == 1) { 
        b--;
        ans = (ans*a) % MOD;
        }
    for (int i = 0; i < b / 2; i++) {
        ans = (ans*k) % MOD;
    }
    return ans%MOD ;
}
int main() {
    long long a, b,c;
    while (1) {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << "" << poww(a, b) << endl;
    }
        return 0;
}