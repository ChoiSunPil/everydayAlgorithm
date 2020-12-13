/**
 * 문제 URL : https://programmers.co.kr/learn/courses/30/lessons/60057
 * 
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int find_compress_string_size(int unit, string s);
int solution(string s);
int main(){

cout<< solution("xxxxxxxxxxyyy") <<endl;
cout<<solution("a")<<endl;
cout<< solution("xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx")<<endl;
}

int solution(string s) {
    int answer = -1;
    int size = s.length();

    if(size ==1)
    {
        return 1;
    }

    for(int  i = 1 ;i <= size/2 ; i++)
    {
        int result = find_compress_string_size(i,s);

        if(answer == -1)
        {
            answer = result;
        }
        else if(answer > result)
        {
            answer = result;
        }
    }
    return answer;
}
int find_compress_string_size(int unit, string s){

    string tmp = "";
    
    vector<string > string_unit;

    



    for(int  i = 0 ; i <s.length(); i+=unit)
    {
        string_unit.push_back(s.substr(i,unit));
    }

    string past = string_unit[0];
    int past_count = 1;
    for(int  i = 1 ; i < string_unit.size(); i++)
    {
        if(past.compare(string_unit[i]) != 0)
        {
            if(past_count != 1)
           {
            tmp += (to_string(past_count)+past); 
                
            }
            else
            {
            tmp += past; 
            }
    
            past = string_unit[i];
            past_count = 1;

        
     
        }
        else
        {
            past_count++;
        }

        if(i == string_unit.size()-1)
        {
            if(past_count != 1)
           {
              tmp += (to_string(past_count)+past); 
        
            }
            else
            {
            tmp += past; 
            }
            

        }


    }


    return tmp.length();
} 