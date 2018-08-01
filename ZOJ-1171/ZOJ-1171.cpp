#include  <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        int sum = 0;
        cin >> n;
        char *card = new char[n];
        for (int i = 0; i < n; ++i) {
            cin >> card[i];
        }
        for (int i = 0; i <n-1;++ i ) {
            if (card[i] != card[i + 1]) {
                sum++;
            }
        }
        cout << sum << endl;
        if (t) {
            cout << endl;
        }
    }
    return 0;
}