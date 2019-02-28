#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX(100000);
int main() {
    int n;
    cin >> n;
    while (  n-- ) {
        int m,s,t;
        cin >> m>>s;
        vector <int> a(m,0);
        for (int i = 0; i < m; ++i) {
            cin >> t;
            a[i] = t;
        }
        int l = 0, r = 0, sum = 0,  ans = m;
        while (1) {
            if (r == m) {
                break;
            }//�߽�����
            sum += a[r++];
            while (sum >= s) {
                ans = min(ans, r - l);//����߽�
                sum -= a[l++];
            }
        }
        if (ans == m) {
            cout << "0" << endl;
            continue;
        }
        cout << ans << endl;
        a.clear();
    }
    return  0;
}