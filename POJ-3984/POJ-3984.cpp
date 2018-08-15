#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <queue>

using namespace std;

struct node {
    int row, col;
};
int go[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };//�����ƶ�
int maze[5][5];//�Թ�
bool vis[5][5];//�Թ����
node path[5][5];//��¼·��
queue <node> q;
void outputbfs(node a) {
    if (a.col == 4 && a.row == 4) {
        cout << "(4, 4)\n" << endl;
        return;
    }
    printf("(%d, %d)\n", a.row, a.col);
    outputbfs(path[a.row][a.col]);

}
void bfs() {
    vis[4][4] = 1;
    node now,pre;
    now.row = 4, now.col = 4;
    q.push(now); //Ԥ����
    while ( !q.empty() ) {
        now = q.front();
        q.pop();
        if (now.row == 0 && now.col == 0) {
            outputbfs(now);
        }
        for (int i = 0; i < 4; ++i ) {
            pre.row = now.row + go[i][0];
            pre.col = now.col + go[i][1];//Խ�磬�ظ���ǽ�ڵ��ж�
            if (pre.row < 0 || pre.col < 0 || pre.row>4 || pre.col>4 || vis[pre.row][pre.col]  || maze[pre.row][pre.col]) {
                continue;
            }
            vis[pre.row][pre.col] = true;//��Ǹ�����
            path[pre.row][pre.col] = now;//����·��
            q.push(pre);//����
        }
    }
}

int main() {
    memset(maze, 0, sizeof(maze));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j< 5; ++j) {
            cin >> maze[i][j];
        }
    }
    bfs();
    return 0;
}