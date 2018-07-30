#include <iostream>
using namespace std;
long long fact(int n) {         //阶乘
    long long ans=1;
    if (n == 1 || n==0 ) {
        return 1;
    }
    ans = n * fact(n - 1);
    return ans;
}
long long c(int n, int m) {
    long long ans_1;
    ans_1 = (fact(n)) / (fact(n - m) * fact(m));    //组合数（非模板，本题定制）
    return ans_1;
}

long long f[34];
int main() {
    int t;
    cin >> t ;
    f[0] = 1, f[1] = 0, f[2] = 1;
    for (int i = 3; i <= 30; ++i) {
        f[i] = (i - 1)*(f[i - 1] + f[i - 2]);   //错排打表
    }
    while (t--) {
        int n, m;
        cin >> n >> m;
        cout << "" << c(n, m)*f[m] << endl;
    }
    return 0;
}