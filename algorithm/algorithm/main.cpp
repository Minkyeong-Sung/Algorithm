//
//  main.cpp
//  algorithm
//
//  Created by 성민경 on 2017. 11. 27..
//  Copyright © 2017년 성민경. All rights reserved.
//
// 1662
// 압축


#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int> &u, const pair<int, int> &v){

    if(u.second == v.second) return u.first < v.first;
    else return u.second < v.second; // 오름차순


    return true;
}


int main(){

    int n;
    
    scanf("%d", &n);
    
    vector<pair<int, int>> arr(n);
    
    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].first, &arr[i].second);
    }
    
    sort(arr.begin(), arr.end(), cmp);
    
    for(int i=0; i< arr.size() ; i++){
        printf("%d %d\n", arr[i].first, arr[i].second );
    }
    
    
    
    return 0;
}






