#include <iostream>
#include <algorithm>

using namespace std;

long long int two[3];
long long int five[3];

void cntNum(long long int n, int flag){

    long long int tmp_two=0, tmp_five=0;
    long long int i;
    
    for(i=2; i<=n ; i *=2){
        tmp_two += n/i;
    }
    
    for(i=5; i<= n; i *= 5){
        tmp_five  += n/i;
    }

    two[flag] = tmp_two;
    five[flag] = tmp_five;
}

int main(){

    long long int n, m;
    
    cin >> n >> m;
   
    //  n! / (m! * (n-m)!)
    cntNum(n, 0);
    cntNum(m, 1);
    cntNum(n-m, 2);
    
    long long int ans = min(two[0] - two[1] - two[2], five[0] - five[1] - five[2]);
    
    cout << ans ;
    
    
    return 0;
}
