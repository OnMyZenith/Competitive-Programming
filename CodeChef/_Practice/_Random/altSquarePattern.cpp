#include<iostream>

using namespace std;

int main(){
    int line;
    cin>>line;
    for(int i = 1;i<=line;i++){
    if(i%2==1){
        cout<<i*5-4<<" "<<i*5-3<<" "<<i*5-2<<" "<<i*5-1<<" "<<i*5<<endl;
    }
    else{
        cout<<i*5<<" "<<i*5-1<<" "<<i*5-2<<" "<<i*5-3<<" "<<i*5-4<<endl;
    }
    }
    return 0;
}