#include<iostream>
using namespace std;
int gcd(int A, int B);
int main(){

int A ,B ,C;
int R;
cin>>A;
cin>>B;
R = gcd(A,B);
cout<<R<<endl;
cout<<(A*B)/R;
}
int gcd(int A, int B)
{
    if(B== 0)
    {
        return  A;
    }
    else{
        return gcd(B,A%B);
    }


}