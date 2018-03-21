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
#include <algorithm>

using namespace std;


int main(){

    int a,b,c,d;
    
    cin >> a >> b >> c >> d;
    
    string first  = to_string(a) + to_string(b);
    string second = to_string(c) + to_string(d);
    
    long long num1 = stoll(first);
    long long num2 = stoll(second);
    
    cout << num1 + num2;
    
    
    return 0;
}






