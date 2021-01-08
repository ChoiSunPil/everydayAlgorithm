#include <iostream>
#include <bitset>
#include <vector>
#include <string>
using namespace std;
 void rotate(vector<vector<int> > &key);
int main(){


vector< vector<int> > a(10, vector<int>(10,0));
vector< vector<int> > b(10, vector<int>(10,0));
for(int i =0 ; i < 10 ; i++)
{
    for(int j = 0 ; j <10 ;j++)
    {
        a[i][j] = i ;
    }


}

for(int i =0 ; i < 10 ; i++)
{
    for(int j = 0 ; j <10 ;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;

}
b = a;
rotate(a);
cout<<endl;

for(int i =0 ; i < 10 ; i++)
{
    for(int j = 0 ; j <10 ;j++)
    {
        cout<<a[i][j]<<" ";
    }
    cout<<endl;

}

cout<<endl;

for(int i =0 ; i < 10 ; i++)
{
    for(int j = 0 ; j <10 ;j++)
    {
        cout<<b[i][j]<<" ";
    }
    cout<<endl;

}


}
 void rotate(vector<vector<int> > &key){
     vector<vector<int> > tmp(key.size() , vector<int>( key.size() ,0));
      

    for(int  i = 0 ; i < key.size() ; i++)
    {
        for(int  j = 0 ; j < key.size(); j++)
        {
            tmp[j][key.size()-1-i] = key[i][j];
        }
    }
    key = tmp;
}