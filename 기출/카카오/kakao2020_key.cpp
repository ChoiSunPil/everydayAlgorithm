#include <iostream>
#include <bitset>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
void rotate(vector<vector<int> > &key);
bool solution(vector<vector<int> > key, vector<vector<int> > lock);
bool varify(vector<vector<int> > &board, int N, int M);
void print(vector<vector<int> > &board);
vector<vector<int> > pushKey(vector<vector<int> > &board, int i, int j, vector<vector<int> > &key);

int main()
{
    vector<vector<int> > key(3,vector<int>(3));
    vector<vector<int> > lock(3,vector<int>(3));
    key[0][0] = 0;
    key[0][1] = 0;
    key[0][2] = 0;
    key[1][0] = 1;
    key[1][1] = 0;
    key[1][2] = 0;
    key[2][0] = 0;
    key[2][1] = 1;
    key[2][2] = 1;

    lock[0][0] = 1;
    lock[0][1] = 1;
    lock[0][2] = 1;
    lock[1][0] = 1;
    lock[1][1] = 1;
    lock[1][2] = 0;
    lock[2][0] = 1;
    lock[2][1] = 0;
    lock[2][2] = 1;
   
    cout<<solution(key,lock);
}

bool solution(vector<vector<int> > key, vector<vector<int> > lock)
{
    bool answer = false;
    const int N = lock.size();
    const int M = key.size();
    const int size = (M * 2) + N - 2;
    vector<vector<int> > board(size, vector<int>(size, 0));
    vector<vector<int> > tmpboard(size, vector<int>(size, 0));


    

    /**
     * board 초기화
     */
    for(int i = 0 ; i < N ; i++)
    {
        for(int  j = 0 ; j <N ;j++)
        {

            board[M-1+i][M-1+j] = lock[i][j];

        }
    }

    if(varify(board,N,M))
        return true;
    /**
     * 90도씩 3번 회전하면서 key 움직이기 
     */

    for (int i = 0; i <= 3; i++)
    {
        for (int j = 0; j < (M + N - 1); j++)
        {
            for (int k = 0; k < (M + N - 1); k++)
            {
                //Key 움직이기
            
                tmpboard = pushKey(board, j, k, key);
                //검증하기(값이 true 면 바로 return)
                if (varify(tmpboard, N, M))
                {
                    return true;
                }
            }
        }

        //마지막에 회전
        if (i != 3)
        {
            rotate(key);
           
        }
    }
    
    return answer;
}

vector<vector<int> > pushKey(vector<vector<int> > &board, int i, int j, vector<vector<int> > &key)
{
    vector<vector<int> > tmpboard(board.size(), vector<int>(board.size(), 0));
    tmpboard = board;

    for(int k = 0 ;  k< key.size() ; k++)
    {
        for(int l = 0 ; l < key.size(); l++)
        {
            tmpboard[k+i][l+j] =key[k][l] ^ tmpboard[k+i][l+j];
          
        }
    }

    return tmpboard;
}

/**
 * key 90도 회전시키는 함수
 */
void rotate(vector<vector<int> > &key)
{
    vector<vector<int> > tmp(key.size(), vector<int>(key.size(), 0));

    for (int i = 0; i < key.size(); i++)
    {
        for (int j = 0; j < key.size(); j++)
        {
            tmp[j][key.size() - 1 - i] = key[i][j];
        }
    }
    key = tmp;
}

/**
 * 보드가 모두 1이 되었는지 확인
 */
bool varify(vector<vector<int> > &board, int N, int M)
{
    for (int i = M - 1; i <= N + M - 2; i++)
    {
        if (count(board[i].begin() + (M - 1), board[i].begin() + (N + M - 1), 1) != N)
        {
            return false;
        }
    }
    return true;
}



void print(vector<vector<int> > &board)
{

     cout<<endl;
    for(int  i = 0 ; i <board.size() ; i++)
    {

        for(int  j = 0 ; j < board.size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;

    }
     cout<<endl;

}
