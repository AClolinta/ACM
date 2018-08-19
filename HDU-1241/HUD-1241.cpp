#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

#define ture true
#define mian main
#define MAX 102

using namespace std;

int go[8][2] = { { 0,1 },{ 0,-1 },{ 1,0 },{ -1,0 },{ 1,1 },{ 1,-1 },{ -1,-1 },{ -1,1 } };
int m, n;
char of[MAX][MAX];

void dfs(int x, int y) {
    of[x][y] = '*';
    for (int i = 0; i < 8; ++i) {
        int nx = x + go[i][0];//八个方向都访问
        int ny = y + go[i][1];
        if (nx < m && ny < n && nx>=0 && ny>=0 && of[nx][ny] == '@') {
            dfs(nx, ny);
        } 
    }
    
}

void outdfs(int m, int  n) {
    int count = 0;
    memset(of, 0, sizeof(of));//油田的二维数组初始化
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> of[i][j];
        }
    }//读入油田
    
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (of[i][j] == '@') {
                dfs(i, j);
                count++;
            }
        }
    }
    cout << count << endl;
}

int main() {
    while ( cin >> m >> n && m && n ) {
        outdfs(m, n);
    }
    return 0;
}