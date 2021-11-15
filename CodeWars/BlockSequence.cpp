#include<bits\stdc++.h>
using namespace std;

int solve(long long n){
    int d = 1;
    long long m = 9;
    long long sum = d * m * (m + 1) / 2;
    while(sum<n){
        d++;
        m *= 10;
        sum += d * m * (m + 1) / 2;
    }
    sum -= d * m * (m + 1) / 2;
    long long idx = n - sum - 1;
    string s, l;
    m = 1;
    while(d>1)
        m *= 10, d--;
    while((int)s.length()<idx+1){
        s += l + to_string(m);
        l = l + to_string(m);
        m++;
    }
    return s[idx] - '0';
}
int main(){
    assert(solve(1)== 1);
    assert(solve(2)==1);
    assert(solve(3)==2);
    assert(solve(100)==1);  
    assert(solve(55)==1);
    assert(solve(123456)==6);
    assert(solve(31000)==2);
    assert(solve(2100)== 2);
    assert(solve(123456789)==3);  
    assert(solve(999999999999999999)== 4);
    assert(solve(1000000000000000000)==1);
    assert(solve(999999999999999993)==7);
}