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
    
    /*
    //this part is test three types of call function
    int a = 10;
    int b = 20;
    
    srand((unsigned)time(NULL));
    static int time = random(10);
    for (int j = 0; j < time; j++){
        Data::swap_value(a, b);
            std::cout << a << " " << b << std::endl;
        Data::swap_reference(a, b);
            std::cout << a << " " << b << std::endl;
        Data::swap_pointer(&a, &b);
            std::cout << a << " " << b << std::endl;
    }
    std::cout << time << std::endl;*/
    
    double fuck_me_jerry[100] = {0};
    double *p = fuck_me_jerry;
    std::cout << p << std::endl;
    for (int i = 0; i < 100; i++)
    {
        *(p + i) = random(100);
        std::cout << *(p + i) << std::endl;
    }
    
    
    
    return 0;
}
