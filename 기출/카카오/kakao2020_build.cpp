
/**
 * 
 * 기둥과 보
 *  URL : https://programmers.co.kr/learn/courses/30/lessons/60061
 * 기둥 조건 : 바닥 위 또는 보의 끝 또는 기둥 위 (y좌표 최대 n-1)
 * 보 조건 : 기둥 위 또는 보가 양쪽 끝에 있는 지 (x좌표 최대 n-1)
 * 벽을 벗어나면 안됨
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > solution(int n, vector<vector<int> > build_frame);
bool verify_concreate(vector<int> & frame,vector<vector<int> > & build);
bool verify_destroy(vector<int> & frame,vector<vector<int> > & build);
bool compare(vector<int>&a, vector<int> &b);
/**
 * 결과값 sort 함수
 **/
bool compare(vector<int>&a, vector<int> &b)
{
    if(a[0] < b[0])
    {
        return true;
    }
    else if(a[0] == b[0])
    {
        if(a[1] < b[1])
        {
            return true;
        }
        else if(a[1] == b[1])
        {
            if(a[2] > b[2])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}


int main(){

int arr[][4] = {{1,0,0,1},{1,1,1,1},{2,1,0,1},{2,2,1,1},
                {5,0,0,1},{5,1,0,1},{4,2,1,1},{3,2,1,1}};

vector<vector<int> > v(8);
for(int  i = 0 ; i < v.size();i++)
{
    v[i].resize(4);
    copy(arr[i],arr[i]+sizeof(int)*4,v[i].begin());
}



}


vector<vector<int> > solution(int n, vector<vector<int> > build_frame) {
    vector<vector<int> > answer;

    
    for(int i = 0 ; i <build_frame.size();i++)
    {

        //설치
        if(build_frame[i][3] == 1)
        {
           //보
           if(build_frame[i][2] ==1)
           {
               if(build_frame[i][0]> 0 &&build_frame[i][0] < n && verify_concreate(build_frame[i],answer))
               {
                vector<int> tmp(build_frame[i].begin() , build_frame[i].end()-1);
                answer.push_back(tmp);
               }
           }
           else//기둥
           {
               if(build_frame[i][1] ==0||(build_frame[i][1] < n && verify_concreate(build_frame[i],answer)))
               {
                vector<int> tmp(build_frame[i].begin() , build_frame[i].end()-1);
                answer.push_back(tmp);
               }
           }
        }
        else //삭제
        {
            if(verify_destroy(build_frame[i],answer))
            {
                vector<vector<int> >::iterator it;
                for(it = answer.begin() ; it != answer.end();it++)
                {
                    if(((*it)[0] == build_frame[i][0])&&((*it)[1] == build_frame[i][1])&&((*it)[2] == build_frame[i][2]))
                    {
                        break;
                    }
                }
                answer.erase(it);
            }
        }
    }


    sort(answer.begin(),answer.end(),compare);
    return answer;
}

bool verify_concreate(vector<int> & frame,vector<vector<int> > & build)
{
    vector<int> tmp(frame.begin(),frame.end());
    vector<int> tmp1(frame.begin(),frame.end());
    vector<int> tmp2(frame.begin(),frame.end());
    vector<int> tmp3(frame.begin(),frame.end());
    int count = 0;
    if(frame[3] ==0){ //기둥
        tmp[1] -= 1;
        tmp1[0] -= 1;
        tmp1[2] = 1;
        tmp2[2] =1;
        for(int  i = 0 ; i< build.size();i++)
        {
            if(build[i][2] ==0)//기둥
            {   
                if(build[i] == tmp || build[i] == tmp1)
                    return true;    
            }
            else
            {
                if(build[i]== tmp1 || build[i] == tmp2)
                    return true;
            }
        }
    }
    else
    {
        tmp[1] -= 1;
        tmp[2] = 0;
        tmp1[0] += 1;
        tmp1[1] -= 1;
        tmp1[2] = 0;
        tmp2[0] -= 1;
        tmp3[0] += 1;
    
        for(int  i = 0 ; i< build.size();i++)
        {
            if(build[i][2] ==0)//기둥
            {   
                if(build[i] == tmp || build[i] == tmp1)
                    return true;    
            }
            else
            {
                if(build[i]== tmp2 || build[i] == tmp3)
                   count++;
            }

            if(count == 2)
                return true;
        }     
    }
    
    return false;



}

bool verify_destroy(vector<int> & frame,vector<vector<int> > & build)
{
  
  vector<vector<int> > tmp(build.begin(),build.end());
  vector<vector<int> >::iterator it;
                for(it = tmp.begin() ; it != tmp.end();it++)
                {    
                    tmp.erase(it);
                }

    vector<int> tmp1(frame.begin(),frame.end()); //기둥
    vector<int> tmp2(frame.begin(),frame.end()); //왼 보
    vector<int> tmp3(frame.begin(),frame.end()); // 오른 보


    if(frame[3]==0) //기둥
    {
        tmp1[1] +=1;
        tmp2[1] +=1;
        tmp2[0] -=1;
        tmp3[1] += 1;
        for(int  i = 0 ; i< tmp.size();i++)
        {
            if(tmp[i]== tmp1)
            {
                return false;
            }
            else if(tmp[i] ==tmp2)
            {
                if(!verify_concreate(tmp2, tmp[i]))
                    return false;

            }
            else(tmp[i] == tmp3)
            {
                if(!verify_concreate(tmp3,tmp[i]))
                    return false;

            }
        }
    }
    else
    {
        tmp1[0] +=1;
        tmp1[1] +=1;
        tmp2[0] -=1;
        tmp3[0] +=1;
        for(int  i = 0 ; i< tmp.size();i++)
        {
            if(tmp[i]== tmp1)
            {
                return false;
            }
            else(tmp[i] ==tmp2)
            {
                if(!verify_concreate(tmp2,tmp[i]))
                    return false;

            }
            else(tmp[i] == tmp3)
            {
                if(!verify_concreate(tmp3,tmp[i]))
                    return false;

            }
        }

        
    }



    return true;

}

