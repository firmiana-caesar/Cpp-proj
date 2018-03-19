//
//  static_mem_in_class.h
//  Review_cpp
//
//  Created by 郭杰 on 2018/3/18.
//  Copyright © 2018年 郭杰. All rights reserved.
//

#ifndef static_mem_in_class_h
#define static_mem_in_class_h
#include <iostream>

#define random(x) (rand()%x)
class Data
{
public:
    Data(){
        //as we can see, the const member can also initialized in the constructor
        //const int pdata = 1000;
        
        //about thread_local, this data member just can be modified in the thread which they are
        //eg. thread a has a thread_local member a, thread b has a thread_local member b, a can not be modified
        //in thread b
        //thread_lock = 0;
    }
    ~Data(){}
    void show(){
        std::cout << this->data << std::endl;
        std::cout << std::numeric_limits<int>::max << std::endl;
    }
    
    static void showData(){
        std::cout << " " << number << std:: endl;
    }
    
    void yell() const{
        std::cout << "i am yelling" << std::endl;
        //can not modified the non-static data member because this is a static function
        //data++
    }
    
    void say() const{
        int d = 10;
        int c = d++;
        std:: cout << c << std::endl;
        
        d = 10;
        c = d--;
        std::cout << d << std::endl;
        std::cout << c << std::endl;
        
        (d == 10) ? std::cout << "fuck u" : std::cout << "shit" << std::endl;
    }
    
    //this is a function that call by value
    static void swap_value(int a, int b){
        int temp;
        temp = a;
        a = b;
        b = temp;
        return;
    }
    
    //this is a function that call by reference
    static void swap_reference(int& a, int& b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    
    //this is a function that call by pointer
    static void swap_pointer(int *a, int *b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }
    
private:
    int data;
    //the const member must be initialized in constructor
    const int pdata = 100;
    //thread_local static int thread_lock;

    
    
public:
    static int number;
};
#endif /* static_mem_in_class_h */
