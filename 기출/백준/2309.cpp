#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
void findHobits(vector<int> &hobits,int i, vector<int> result);
void print(vector<int>& v);
int main()
{
vector<int> hobits;
for(int  i = 0 ; i < 9 ; i++)
{
int tmp;
cin >> tmp;
hobits.push_back(tmp);
}

sort(hobits.begin(),hobits.end());
for(int  i = 0 ; i < 3; i++)
{
vector<int> result;
findHobits(hobits,i,result);
}
}
void findHobits(vector<int> &hobits,int i, vector<int> result)
{
    result.push_back(hobits[i]);
    int sum = accumulate(result.begin(),result.end(),0);
    //7명이고 100이면 출력하고 프로그램 종료
    if(result.size() == 7 && sum== 100){

        print(result);
        exit(0);
    }//7명 미만, 100 이면 리턴
    else if(result.size() < 7 && sum >= 100)
    {
        return;
    }
    else
    {
        for(int  j = i+1; j < hobits.size();j++)
        {
            findHobits(hobits,j,result);
        }
    }
    
    //7명 미안, 100 이하면  다음 꺼
}
void print(vector<int>& v)
{
    vector<int>::iterator itr;
    for(itr = v.begin() ; itr != v.end();itr++)
    {
        cout<<*itr;
        if(itr != v.end()-1)
        {
            cout<<endl;
        }
    }
}
