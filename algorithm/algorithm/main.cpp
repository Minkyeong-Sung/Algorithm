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


int main(){

    int n, cnt;
    string tmp;
    char ch;
    
    stack<char> left, right;
    
    cin >> tmp ;
    cnt = tmp.size();
    for(int i=0; i<cnt; i++){
        left.push(tmp[i]);
    }
    
    cin >> n;
    
    for(int i=0; i<n; i++){
        
        cin >> ch;
        
        if(ch == 'L'){ // 왼쪽으로 커서 이동
            
            if(!left.empty()){ // 비어있는 경우 대비
                right.push(left.top());
                left.pop();
            }
        }
        else if(ch == 'D'){ // 오른쪽으로 커서 이동
            
            if(!right.empty()){
                left.push(right.top());
                right.pop();
            }
            
        }else if(ch == 'B'){ // 왼쪽에 있는 문자 삭제
            
            if(!left.empty()){
                left.pop();
            }
        }
        else{ // P $ ; $라는 문자를 왼쪽에 추가
            
            char addChar;
            
            cin >> addChar;
            
            left.push(addChar);
        }
    }

    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while(!right.empty()){
        cout << right.top();
        right.pop();
    }
    
    
    return 0;
    

}






