//
//  main.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/3/29.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//Poj1163
/*
 输入格式：
 5      //表示三角形的行数    接下来输入三角形
 7
 3   8
 8   1   0
 2   7   4   4
 4   5   2   6   5
 要求输出最大和
 
  在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径。 三角形的行数大于1小于等于100，数字为 0 - 99
 */
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100
int D[MAX][MAX];
int n;
int maxsum[MAX][MAX];

int Maxsum_1(int i, int j){
    if (i == n)
        return D[i][j];
    
    int x = Maxsum_1(i + 1, j);
    int y = Maxsum_1(i + 1, j + 1);
    
    return max(x, y) + D[i][j];
}

int Maxsum_2(int i, int j){
    if(D[i][j] == -1)
        return D[i][j];
    
    if(i == n)
        maxsum[i][j] = D[i][j];
    else
        maxsum[i][j] = max(Maxsum_2(i + 1, j), Maxsum_2(i + 1, j + 1)) + D[i][j];
    
    return maxsum[i][j];
}

int Maxsum_3(int i, int j){
    for( int i = 1;i <= n; ++ i )
        maxsum[n][i] = D[n][i];
    for( int i = n-1; i>= 1;  --i )
        for( int j = 1; j <= i; ++j )
            maxsum[i][j] = max(maxsum[i+1][j],maxsum[i+1][j+1]) + D[i][j];
    
    return maxsum[i][j];
}

int main(int argc, const char * argv[]) {
    int i, j;
    cin >> n;
    
    for(i = 0; i < n; i++)
        for(j = 0; j <= i; j++)
            cin >> D[i][j];
    
    cout << Maxsum_1(0, 0) << endl;
    cout << Maxsum_2(0, 0) << endl;
    cout << Maxsum_3(0, 0) << endl;
    
    return 0;
}
