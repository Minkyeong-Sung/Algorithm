//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//
// 1662
// 압축


#include <iostream>

using namespace std;


int gcd(int a, int b){

    int tmp;
    
    while(b != 0){
    
        tmp = a % b;
        a = b;
        b = tmp;
    }
    
    return a;
}


int main(){

    int a, b, g,l;

    
    cin >> a >> b;
    
    g = gcd(a,b);
    l = a*b / g;
    
    cout << g<< '\n' << l;
    
    
    return 0;
}








