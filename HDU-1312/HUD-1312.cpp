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

int go[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };//���������ƶ������飬����������move����ORz
bool vis [22] [22];//����������MAX����
node start;

int bfs(int len,int wid) {
    int count = 1;
    memset(vis, false, sizeof(vis));//��ʼ�����ʱ��
    vector<vector<char>>maze(len, vector<char>(wid, 0));//������ά���鼰���ʼ��
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < wid; ++j) {
            cin >> maze[i][j];
            if ( maze[i][j] == '@') {
                start.row = i, start.col = j;//��ȡ��ʼ����
            }
        }
    }//���������������ͼ���
    queue <node>q;
    node now, next;
    now = start;
    q.push(now);//��ʼ�ڵ�����
    vis[now.row][now.col] = true;//��ʼ�ڵ���
    while (!q.empty()) {
        now = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            next.row = now.row + go[i][0];
            next.col = now.col + go[i][1];
            if (next.row<0 || next.col<0 || next.row>len-1 || next.col>wid-1 || vis[next.row][next.col] || maze[next.row][next.col] == '#') {
                continue;
            }
            vis[next.row][next.col] = true;//��Ǹõؿ��ѱ�����
            q.push(next);//����
            count++;
        }
    }
    vector<vector<char>>(maze).swap(maze);//�������
    return count;
}

int main() {
    int len, wid;
    while (cin >> len >> wid && len && wid) {
        cout << bfs(wid, len) << endl;
    }
    return 0;
}