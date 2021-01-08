#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int m;
int x[] = {0, 0, -1, 1};
int y[] = {1,-1,0,0};
void findMax(vector<vector <int> > &board ,vector<vector <int> > visited, int i , int j , int depth, int sum);
int main(){
int N,M;
cin>>N;
cin>>M;
vector<vector <int> >board(N,vector <int>(M));
for(int  i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j<M; j++)
    {
        int tmp;
        cin >>tmp;
        board[i][j] = tmp;
    }
}


for(int  i = 0 ; i < N ; i++)
{
    for(int j = 0 ; j<M; j++)
    {
        vector<vector <int> >visited(N,vector <int>(M));
        findMax(board, visited,i ,j, 0, 0);
    }
}

cout<<m<<endl;

}
void findMax(vector<vector <int> > &board ,vector<vector <int> > visited, int i , int j , int depth, int sum)
{
int tmpSum = sum + board[i][j];
int tmpDepth = depth + 1;
vector<vector <int> > tmpVisted = visited;
tmpVisted[i][j] = 1;
if(tmpDepth == 4)
{
     m =  m< tmpSum ? tmpSum: m;
}
else if(tmpDepth <4)
{
    for(int k = 0 ; k <4; k++)
    {
        if(i+y[k] >= 0 && i+y[k] < board.size()&& j+x[k] >= 0 && j+x[k]< board.size() && tmpVisted[i+y[k]][j+x[k]] == 0)
        {
            findMax(board,tmpVisted,i+y[k],j+x[k],tmpDepth,tmpSum);
        }
    }

}



}