#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int gcd(int A, int B);
int lcm(int a, int b);
int main()
{
    
    int count = 0;
    cin >> count;
    vector<int> result;
    for (int i = 0; i < count; i++)
    {
        int M,N,x,y;
        cin>>M>>N>>x>>y;
        int find_year = -1;
        int max_year =  lcm(M,N);
        for(int i= 0 ; M*i+x<= max_year ;i++)
        {
            int cur_year = M*i+x;
            int tmp_y = cur_year%N;
            
            if(y == tmp_y ||(N==y &&tmp_y == 0))
            {
                find_year = cur_year;
                break;
            }
        }

        result.push_back(find_year);

    }

    for(int i = 0 ; i <count ; i++)
    {
        cout<<result[i]<<endl;
    }
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
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

/**
 *
 * 느낀점 : 코드로 시간복잡도를 줄일 수 없을때는 수학적인 기법을 이용하자 
 **/