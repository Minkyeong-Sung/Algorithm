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
    
    int n;
    
    cin >> n;
    vector<int> p(n+1); // 1개 선택할 경우
    vector<int> MaxPrice(n+1); //
    
    // 값 입력
    for(int i=1; i<=n; i++){
        cin >> p[i];
    }
    
    for(int i=1 ; i<= n; i++){
        for(int j=1; j<=i; j++){
            
            MaxPrice[i] = max(MaxPrice[i], MaxPrice[i-j] + p[j]);
        }
    }
    
    cout << MaxPrice[n] ;
    
    
    return 0;
}



