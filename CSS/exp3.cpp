#include<bits/stdc++.h>
using namespace std;

int main(){
    int g=7,p=23,a=3,b=5,k1,k2,A,B;
    
    

    int x = pow(g,a);
    int y = pow(g,b);
    k1= x%p;
    k2=y%p;

    int l = pow(k2,a);
    int i= pow(k1,b);

    A=l%p;
    B=i%p;

    cout<<"Value of k1: "<<k1<<endl<<"Value of k2: "<<k2<<endl;
    cout<<"Value of A: "<<A<<endl<<"Value of B: "<<B<<endl;

    if(A==B){
        cout<<"Key Exchange Successful"<<endl;
    }
    else{
        cout<<"Key Exchange Failed";
    }
}