#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;



/**
 * bool이 false면 변경
 **/
bool compare(int a, int b)
{
        return a>b;
}

int main(){

int arr[] = {1,2,3,4,5};
vector<int> v(arr ,arr+5);
vector<int>::iterator it ;
it = v.end()-1;

cout<<*it<<endl;
sort(v.begin(),v.end(),compare);

v.erase(it);

for(int  i=0; i < v.size() ; i++)
{
    cout<<v[i]<<" ";
}


cout<<endl<<*it<<endl;


/**
 * 
 * 결론 : itr는 공간을 가리키고 있기 때문에, 특정 원소를 삭제 할 수 는 없다.
 * 
 **/


}
