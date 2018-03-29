//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//


#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;


int main() {
    
    string input;
    int cnt = 0;
    stack<int> st;
    
    cin >> input;
    
    int n = input.size();
    
    
    for(int i=0; i<n; i++){
        
        // 쇠막대기 시작
        if(input[i] == '('){
            st.push(i);
        }
        else{// ')'
            // 막대기 자를 때
            if(st.top() + 1 == i){
                st.pop();
                cnt += st.size();
            } // 안자른다면 1개씩 막대기가 증가함
            else{
                st.pop();
                cnt++;
            }
        }
    
    }
    
    cout << cnt ;
    
    
    
    
    return 0;
}



