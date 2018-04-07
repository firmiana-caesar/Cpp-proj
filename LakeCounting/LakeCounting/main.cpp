//
//  main.cpp
//  LakeCounting
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//有一个大小为N*M的院子，雨后积起了水，八连通的积水被认为是连接在一起的，请求出院子里总共有多少水洼
//input:
//W........WW.
//.WWW.....WWW
//....WW...WW.
//.........WW.
//.........W..
//..W......W..
//.W.W.....WW.
//W.W.W.....W.
//.W.W......W.
//..W.......W.
//output:3
//limit:0 < N, M <= 100

#include <iostream>
using namespace std;
#define MAX 100

int n, m;
char water[MAX][MAX];
int counter = 0;


//在递归时出错

void dfs(int x, int y){
	water[x][y] = '.';

	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if((x + i >= 0) && (y + j >= 0) && (x + i < n) && (y + j < m) && (water[x + i][y + j] == 'W'))
				dfs(x + i, y + j);
	return;
}

void solve(){
	int res = 0;
	for (int i = 0 ; i < n; i++)
		for (int j = 0 ; j < m; j++)
			if (water[i][j] == 'W'){
                dfs(i, j);
				res++;
			}

			cout << res;
}

int main(){
	cin >> n >> m;
	for (int i = 0 ; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> water[i][j];
    
    /*cout << n << " " << m << endl;
    for (int i = 0 ; i < n; i++){
        for (int j = 0 ; j < m; j++)
            cout << water[i][j] ;
        cout << endl;
    }*/

	/*    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (water[i][j] == 'W'){
                dfs(i, j);
                counter++;
            }
        }
    }*/

    solve();

	return 0;
}
