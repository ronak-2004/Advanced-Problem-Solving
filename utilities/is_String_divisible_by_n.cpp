#include <iostream>
#include <string>
using namespace std;

bool isDivisibleByN(string &str,int n){
    int rem=0;
    for(char c:str){
        rem = (10*rem+(c-'0'))%n;
    }
    return rem==0;
}

int main(){
    string s;
    int n;
    //Enter string: 
    cin>>s;
    //Enter n (divisor)
    cin>>n;
    if(isDivisibleByN(s,n)){
        cout<<"Is divisible";
    }
    else cout<<"Is not Divisible";
    return 0;
}


/*
TC : O(s.length)
Aux. Space: o(1)
*/
