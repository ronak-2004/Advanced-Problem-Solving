#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;
ll ans=LLONG_MAX;
vector<int> primes={2,3,5,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void generate(int idx,int n,vector<int>&factors){
    if(n==1){
        vector<int>exponent;
        for(x:factors) exponent.push_back(x-1);
        sort(exponent.rbegin(),exponent.rend());
        
        ll val=1;
        for(int i=0;i<exponent.size();i++){
            int exp = exponent[i];
            int p = primes[i];
            for(int j=0;j<exp;j++){
                if(val>ans/p){
                    return;
                }
                val*=p;
            }
        }
        ans=min(ans,val);
    }
    for(int i=idx;i<=n;i++){
        if(n%i==0){
            factors.push_back(i);
            generate(i,n/i,factors);
            factors.pop_back();
        }
    }
}
ll smallestNumWithNFactors(int n){
    vector<int>factors;
    generate(2,n,factors);
    return ans;
}

int main(){
    int N;
    cin>>N;
    cout<<smallestNumWithNFactors(N)<<endl;
    return 0;   
}
