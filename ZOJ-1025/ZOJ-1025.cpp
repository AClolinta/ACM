#include <iostream>
#include <algorithm>
#include<memory.h>
using namespace std;
#define MAX 5004
struct wood {
    int l, w;
};
wood sticks[MAX];
bool b[MAX];
bool cmp( wood a,  wood b) {
    return (a.l < b.l || (a.l == b.l && a.w < b.w)); //定义cmp函数双重排序
}
int  main() {
    int cas;
    cin >> cas;
    while (cas--) {
        memset(b, false, sizeof(b));
        int n, count = 0;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> sticks[i].l >> sticks[i].w;
            b[i] = true;
        }
        sort(sticks, sticks + n, cmp );
        int flag = 1;
        while (flag) {
            int tmin;
            flag = 0,tmin = 1; //初始化为最小值!
            count++;
            for (int i = 0; i < n; ++i) {
                if (b[i] && tmin <= sticks[i].w) {
                    b[i] = false;
                    tmin = sticks[i].w;
                    flag = 1;
                }
            }
        }
            cout << count-1 << endl;
     }
        return 0;
}
