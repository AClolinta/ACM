#include <iostream>
using namespace std;
long long  table[1004];
#define  MOD 10000
int main() {
    table[0] = 0, table[1] = 0, table[2] = 2,table[3]=2;
    for (int i = 3; i <= 1000; ++i) {
        table[i] = (table[i - 1] + 2 * table[i - 2]) % MOD;//ͬ�ඨ����Ȼ�ᱬ���n��
    }
    int n;
    while (cin>>n && n) {
        cout << "" << table[n]  << endl;
    }
    return 0;
}