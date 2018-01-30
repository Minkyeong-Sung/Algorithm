//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//
// 1019
// 책 페이지 개수 세기


#include <iostream>
#include<vector>

using namespace std;


// 일의 자리수 세기
string solve(int page, int comp){
    
    int cnt = 0, now;
    vector<int> arr;
    int i=0, tmp = 0;
    
    for(now = 1; now <= page; ++now, i++){
        
        tmp = now;
        
        //만약 두자리 수 이상이면 한자리수로 변환
        while(tmp/10 != 0){
            arr.push_back(tmp%10);
            tmp = tmp/10;
        }
        arr.push_back(tmp);
        
        for(auto it = arr.begin(); it != arr.end(); ++it){
            
            if(*it == comp){
                cnt++;
            }
        }
        
        arr.clear();
    }
    
    return to_string(cnt);
}



int main(){
    
    int n;
    
    cin >> n;
    
    for(int i=0; i<=9; i++){
        cout << solve(n, i);
        cout << " ";
    }
    
    return 0;
}








