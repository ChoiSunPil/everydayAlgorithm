#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int max_profit;
vector<pair<int,int> > counselor;
int N;
void findProfit(int n, int sum);
int main(){
cin>>N;
for(int  i = 0 ; i < N ; i++)
{
int T;
int P;
cin>>T>>P;
counselor.push_back(pair<int,int>(T,P));
}
findProfit(0,0);

cout<<max_profit;

}
void findProfit(int n, int sum)
{

if(n == N-1)
{
  int tmp = counselor[n].first == 1? sum+counselor[n].second :sum;
  if(tmp > max_profit)
  {
      max_profit = tmp;
  }
}
else if(n == N)
{
    if(sum > max_profit)
  {
    max_profit =sum;
  }
}
else
{

    if(n+counselor[n].first <= N)
    {   
        findProfit(n+counselor[n].first , sum+counselor[n].second);
    }
    


    for(int i = n+1 ; i < N ; i++)
    {
        findProfit(i,sum);
    }
}

    
    

}

// else if(n >= N)
// {
//     if(sum > max_profit)
//   {
//     max_profit =sum;
//   }
// }

