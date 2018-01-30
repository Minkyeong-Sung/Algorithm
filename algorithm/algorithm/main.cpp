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
#include <vector>
#include <queue>
#include <string>

using namespace std;


string compress(string input){
    
    int check = 0, tmp =0, lenght=0;
    string str = NULL, tmps;
    auto it = input.end()-1;
    
    for(lenght =0; lenght < input.size(); lenght++, --it){
        
        if(*it == ')'){ }
        else if(*it == '('){
            
            if(check == 1){
                it--;
                lenght++;
                tmp = atoi(&*it); // string to int
                tmps = str; // 추가해줄 문자열
                for(int i=1; i<tmp; ++i){ // 반복
                    str += tmps;
                }
                check = 0;
            }
        }
        else {
            check = 1;
            str += *it;
        }
    }
    return str;
}



int main(){

    string input, str;
    
    cin >> input;
    
    str = compress(input);
    
    cout << str.size() ;
    
    return 0;
}








