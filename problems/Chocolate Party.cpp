#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool dfs(vector<int>&c,vector<bool>&vis,int k,int target,int idx,int sum){
    if(k==0)return true;
    if(sum==target) return dfs(c,vis,k-1,target,0,0);
    for(int i=idx;i<vis.size();i++){
        if(vis[i]||sum+c[i]>target) continue;
        vis[i]=true;
        if(dfs(c,vis,k,target,i+1,sum+c[i])){
            return true;
        }
        vis[i]=false;
    }
    return false;
}

bool canPartition(vector<int>&c,int k,int target){
    vector<bool>vis(c.size(),false);
    return dfs(c,vis,k,target,0,0);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    int sum=0;
	    cin>>n>>k;
	    vector<int>chocolates(n);
	    for(int i=0;i<n;i++){
	        cin>>chocolates[i];
	        sum+=chocolates[i];
	    }
	    int target = ceil(sum*1.0/k);
	    int count=0;
	    if(target*k!=sum){
	        cout<<"No"<<endl;
	        continue;
	    }
	    if(canPartition(chocolates,k,target)){
	        cout<<"Yes"<<endl;
	    }
	    else cout<<"No"<<endl;
	}
	return 0;
}
