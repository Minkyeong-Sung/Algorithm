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
#include <queue>
#include <algorithm>

using namespace std;


int main(){

    queue<int> q;
    int n, m;
    
    
    cin >> n >> m;
    
    for(int i=1; i<=n; i++){
        q.push(i);
    }
    
    
    cout << '<';
    
    while(n--){
        for(int i=0; i<m-1; i++){
            q.push(q.front());
            q.pop();
        }
    
        cout << q.front();
        
        if(n!=0){
        cout << ", ";
        }
        
        q.pop();
    }
    
    cout << '>';
    
    
    return 0;
}






