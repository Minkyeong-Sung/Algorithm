#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int N, M;
int arr[51][51];
vector<pair<int, int>> vt;
vector<pair<int, int>> home;
int ans = 987654321;

int caculation(vector<pair<int, int>> ch){
    
    int sum = 0;
    
    for(int i=0; i< home.size(); i++){
        int tmp = 10000000;
        
        for(int j=0; j<ch.size(); j++){
            
            int n = abs( home[i].first - ch[j].first) + abs(home[i].second - ch[j].second);
            if(n < tmp){
                tmp = n;
            }
        }
        sum += tmp;
    }
    
    return sum;
}

void solve(vector<pair<int, int>> ch, int idx, int cnt){
    
    if(cnt == M){
        // 계산
        ans = min(ans, caculation(ch));
        /*
        for(int i=0; i< ch.size(); i++){
            cout << ch[i].first << " " << ch[i].second <<"\n";
        }
         */
        return;
    }
    
    if(idx >= vt.size()) return;
    
    
    // 뽑지 않는 경우
    solve(ch, idx+1, cnt);
    
    // 뽑는 경우
    ch.push_back({vt[idx].first, vt[idx].second});
    solve(ch, idx+1, cnt+1);
    ch.pop_back();
    
    
}

int main(){
    
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<= N; j++){
            cin >> arr[i][j];
            
            if(arr[i][j] == 2){
                vt.push_back({i, j});
            }
            if(arr[i][j] == 1){
                home.push_back({i, j});
            }
        }
    }
    
    
    vector<pair<int, int>> chick;
    solve(chick, 0, 0);
    
    cout << ans;
    
    return 0;
}
