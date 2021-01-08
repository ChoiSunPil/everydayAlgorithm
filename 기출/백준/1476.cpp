#include <iostream>
#include <algorithm>
using namespace std;
int main(){

int E , S, M;
cin>>E;
cin>>S;
cin>>M;
if(E== 15)E=0;
if(S==28)S=0;
if(M==19)M=0;
int year = 0;

while(1)
{

if(year%15 == E && year%28 == S && year%19 == M && year !=0)
{
    cout<<year;
    return 0;
}
year++;
}



}