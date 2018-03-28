//
//  main.cpp
//  GetPosition
//
//  Created by 郭杰 on 2018/3/27.
//  Copyright © 2018年 郭杰. All rights reserved.
//
//做以下假定，场景中有两个物体A和B，对应的三维坐标为（10， 10， 10）以及（20， 20， 20）
//cam1根据比例得到的两个物体xy坐标为（9.5， 10.1）、（22.0， 17.5）
//cam2根据比例得到的两个物体xz坐标为（13.0， 11.2）、（19.8， 19.5）
//cam3根据比例得到的两个物体xz坐标为（11.2， 10.8）、（20.1， 19.6）
//cam4根据比例得到的两个物体yz坐标为（11.1， 9.6）、（18.2， 20.1）
//
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//四个数组存储对应摄像头计算出来的物体在图像上的位置
double cam1[2][2] = {{9.5, 10.1},{22.0, 17.5}};//俯拍，得到物体的x、y坐标
double cam2[2][2] = {{13.0, 10.3}, {22.0, 17.6}};//侧拍，得到物体的x、z坐标
//原则上只需要两个即可定位，以下两个用于位置校正
double cam3[2][2] = {{11.2, 10.8}, {20.3, 19.6}};//侧拍，得到物体的x、z坐标
double cam4[2][2] = {{11.1, 9.6}, {18.2, 20.2}};//正拍，得到物体的y、z坐标
//存储计算结果的数组
double result[2][3];
#define NaN 1000000


int main(){
    void GetPair(int number);
    void Correction(int number);
    
    for(int i = 0; i < 2; i++){
        GetPair(i);
    }

    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            cout << result[i][j] << endl;
        }
    }
    
    return 0;
}

void Correction(int number)
{
    //使用cam3校正x
    int distance = NaN;
    int flag = -1;
    for(int i = 0; i < 2; i++){
        int temp = abs(result[number][0] - cam3[i][0]);
        if(temp < distance){
            distance = temp;
            flag = i;
        }
    }
    result[number][0] = (result[number][0] + cam3[flag][0]) / 2;
    cout << "cam3-flag-0 x " <<cam3[flag][0] << endl;
    flag = -1;
    distance = NaN;
    
    //使用cam4校正y
    for(int i = 0; i < 2; i++){
        int temp = abs(result[number][1] - cam4[i][0]);
        if(temp < distance){
            distance = temp;
            flag = i;
        }
    }
    result[number][1] = (result[number][1] + cam4[flag][0]) / 2;
    cout << "cam4-flag-0 y " << cam4[flag][0] << endl;
    flag = -1;
    distance = NaN;
    
    //使用cam3校正z
    for(int i = 0; i < 2; i++){
        int temp = abs(result[number][1] - cam3[i][1]);
        if(temp < distance){
            distance = temp;
            flag = i;
        }
    }
    result[number][2] = (result[number][2] + cam3[flag][1]) / 2;
    cout << "cam3-flag-1 z " << cam3[flag][1] << endl;
    
}

void GetPair(int number){
    int distance = NaN;
    int flag = -1;
    for(int i = 0; i < 2; i++)
    {
        int temp = abs(cam1[number][0] - cam2[i][0]);
        if(temp < distance){
            distance = temp;
            flag = i;
        }
    }
        result[number][0] = cam1[number][0];
        result[number][1] = cam1[number][1];
        result[number][2] = cam2[flag][1];
    Correction(number);
}

