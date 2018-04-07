//
//  main.cpp
//  Breadth-First_Search
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//宽度优先搜索，利用队列，将初始状态拿出来存进队列的头部，随后不断从非空的队列里面取出状态，并且将未访问的状态放进去，直到队列取空或者问题得到解决
//迷宫的最短路径
//input:
//#S######.#
//......#..#
//.#.##.##.#
//.#........
//##.##.####
//....#....#
//.#######.#
//....#.....
//.####.###.
//....#...G#
//output:22(shortest path)
//limit:n, m <= 100

#include <iostream>
#include <queue>
using namespace std;
#define MAX 100

//使用一个比较大的数指代不能到达的地方的距离
const int INF = 100000000;
//使用pair表示状态，状态就是现在的坐标，使用typedef更加方便
typedef pair<int, int> P;
//存储地图的数组
char path[MAX][MAX];
//起点的坐标
int sx, sy;
//终点的坐标
int gx, gy;
//到各个位置的最短距离的数组
int d[MAX][MAX];
//四个方向的移动量
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};


int n = 0;
int m = 0;

//求从（sx， sy）到（gx， gy）的最短距离，如果不能到达就是INF
int bfs(){
	//一个用于存储状态的队列
	queue<P> que;
	//先将从起点到各点的距离设置为不可达INF
	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < m; j++)
			d[i][j] = INF;

	//将初始状态加入队列，并且距离为0
	que.push(P(sx, sy));
	d[sx][sy] = 0;

	//当队列不为空的时候进行计算
	while(que.size()){
		//拿出队列里面的第一个状态
		P p = que.front(); que.pop();
		//到达终点就不用计算
		if(p.first == gx && p.second == gy) break;

		//计算四个方向的状态转移
		for (int i = 0 ; i < 4; i++){
			//算出下一个状态
			int nx = p.first + dx[i], ny = p.second + dy[i];

			//如果当前状态不超出边界而且符合条件并且没有被遍历过
			if (0 <= nx && nx < n && 0 <= ny && ny < m && path[nx][ny] != '#' && d[nx][ny] == INF){
				//向队列中压入下一个状态，更新距离数组
				que.push(P(nx, ny));
				d[nx][ny] = d[p.first][p.second] + 1;
			}
		}
	}

	return d[gx][gy];
}

void solve(){
	int res = bfs();
	cout << res;
}

int main(){
	cin >> n >> m;
	for (int i = 0 ; i < n; i++)
		for (int j = 0 ; j < m; j++)
			cin >> path[i][j];

	for (int i = 0; i < n; i++)  
        for (int j = 0; j < m; j++)  
        {  
            if (path[i][j] == 'S')  
            {  
                sx = i; sy = j;  
            }  
            if (path[i][j] == 'G')  
            {  
                gx = i; gy = j;  
            }  
        } 

	solve();

	return 0;
}
