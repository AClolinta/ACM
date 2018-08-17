#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

#define MAX 22 ;
#define ture true;
#define mian main;

using namespace std;

struct node {
    int row, col;
};

int go[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//定义用于移动的数组，丢人玩意用move报错ORz
bool vis [22] [22];//辣鸡玩意用MAX报错
node start;

int bfs(int len,int wid) {
    int count = 1;
    memset(vis, false, sizeof(vis));//初始化访问标记
    vector<vector<char>>maze(len, vector<char>(wid, 0));//创建二维数组及其初始化
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < wid; ++j) {
            cin >> maze[i][j];
            if ( maze[i][j] == '@') {
                start.row = i, start.col = j;//获取起始坐标
            }
        }
    }//容器创建并读入地图完成
    queue <node>q;
    node now, next;
    now = start;
    q.push(now);//起始节点入列
    vis[now.row][now.col] = true;//起始节点标记
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            next.row = now.row + go[i][0];
            next.col = now.col + go[i][1];
            if (next.row<0 || next.col<0 || next.row>len-1 || next.col>wid-1 || vis[next.row][next.col] || maze[next.row][next.col] == '#') {
                continue;
            }
            vis[next.row][next.col] = true;//标记该地块已被访问
            q.push(next);//入列
            count++;
        }
    }
    vector<vector<char>>(maze).swap(maze);//清空容器
    return count;
}

int main() {
    int len, wid;
    while (cin >> len >> wid && len && wid) {
        cout << bfs(wid, len) << endl;
    }
    return 0;
}