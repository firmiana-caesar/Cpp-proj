//
//  static_mem_in_class.cpp
//  Review_cpp
//
//  Created by 郭杰 on 2018/3/18.
//  Copyright © 2018年 郭杰. All rights reserved.
//
#include <stdio.h>
#include "static_mem_in_class.h"
int Data::number = 0;

int main(){
    /*Data::showData();
    Data::number = 100;
    Data d;
    d.show();
    d.showData();*/
    Data d;
    d.say();
    
    return 0;
}
