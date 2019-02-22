#include <iostream>
#include <algorithm>
using namespace std;
const int MAX(105);
int main() {
    int N,T[MAX][MAX];
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i < j) break;
            cin >> T[i][j];
        }
    }
    for (int i = N - 1; i > 0; --i) {
        for (int j = 0; j < N; ++j) {
            T[i - 1][j] += max(T[i][j], T[i][j + 1]);
        }
    }
    cout << T[0][0] << endl;
    return 0;
}