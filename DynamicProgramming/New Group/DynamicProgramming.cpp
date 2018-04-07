//
//  DynamicProgramming.cpp
//  DynamicProgramming
//
//  Created by 郭杰 on 2018/4/7.
//  Copyright © 2018年 郭杰. All rights reserved.
//
/*
 背包问题：
 有n个重量和价值为wi，vi的物品，从这些物品中方挑选出总重量不超过W的物品，求所有挑选方案中价值总和的最大值
 1 <= n <= 100
 1 <= wi, vi <= 100
 1 <= W <= 10000
 
 输入样例：
 n = 4， （w， v） = {(2,3), (1,2),(3,4),(2,2)}
 W = 5
 输出样例：
 7
 */
/*
#include <iostream>
using namespace std;
#define MAX_W 10000
int N = 0;
int w[MAX_W];
int v[MAX_W];
int W;
int MAX_VALUE = 0;

int main(){
    cin >> N;
    for (int i = 0 ; i < N; i++)
        cin >> w[i] >> v[i];
    cin >> W;
    
    void rec(int weight_rest, int choose_num);
    rec(W, 0);
    
    cout << MAX_VALUE;
    
    return 0;
}

void rec(int weight_rest, int choose_num){
    int weight_new = W - w[choose_num];
    if(weight_new >= 0){
        MAX_VALUE += v[choose_num];
        rec(weight_new, choose_num++);
    }
    else
        rec(weight_rest, choose_num);
    
    //return MAX_VALUE;
}
*/

//simple version, use time 140
#include <iostream>
#define MAX_N 100
int n, W;
int w[MAX_N], v[MAX_N];
using namespace std;
int rec(int i, int j){//i = the number of chose thing, j = left weight
    int res;
    if(i == n){//no left thing
        res = 0;
    }else if(j < w[i]){//overweight, can not be chose
        res = rec(i + 1, j);
    }else{//choose i thing or not
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    return res;
}

void solve(){
    cout << rec(0, W) << endl;;
}

int main(){
    clock_t start_time;
    clock_t end_time;
    start_time = clock();
    
    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> w[i] >> v[i];
    cin >> W;
    solve();
    
    end_time = clock();
    cout << end_time - start_time << endl;
    
    return 0;
}

//use dynamic programming, using time 2689
#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_W 10000
int n, W;
int w[MAX_N], v[MAX_N];
int dp[MAX_N + 1][MAX_W + 1];

int rec(int i , int j){
    
    if(dp[i][j] > 0){
        return dp[i][j];
    }
    
    int res;
    
    if(i == n){
        res = 0;
    }
    else if (j < w[i]){
        res = rec(i + 1, j);
    }else{
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i]);
    }
    
    return dp[i][j] = res;
}

void solve(){
    memset(dp, -1, sizeof(dp));
    cout << rec(0, W) << endl;
}

int main(){
    clock_t start_time;
    clock_t end_time;
    start_time = clock();
    
    cin >> n;
    for (int i = 0 ; i < n; i++)
        cin >> w[i] >> v[i];
    cin >> W;
    solve();
    
    end_time = clock();
    cout << end_time - start_time << endl;
    
    return 0;
}

/*
 int dp[MAX_N + 1][MAX_W + 1];
 void solve(){
 for (int i = n - 1; i >= 0 ; i--){
    for (int j = 0; j <= W; j++){
        if(j < w[i]){
            dp[i][j] = dp[i + 1][j];
        }else{
            dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
        }
    }
 }
 cout << dp[0][W];
 }
*/
