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
#include <stack>
#include <algorithm>

using namespace std;


string CheckPS(string s){

    int num = 0;
    
    for(int i=0; i< s.size(); i++){
    
        if(s[i] == '('){
            num ++;
        }
        else{
            num--;
        }
        
        if(num < 0){
            return "NO";
        }
    }
    
    if(num == 0){
        return "YES";
    }
    else{
        return "NO";
    }
}


int main(){

    int n;
    
    cin >> n;
   
    for(int i=0; i<n; i++){
        
        string str;
        
        cin >> str;
        
        cout << CheckPS(str) << '\n';
        
    }

    return 0;
}






