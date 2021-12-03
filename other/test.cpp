#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//荷兰国旗问题
void fun_1(vector<int>&v,int num)
{
		int left = 0,cur = 0,right = v.size()-1;
		while(cur <=  right)
		{
        if(v[cur]>num)
				{
						swap(v[cur],v[right--]);

				}
				else
								cur++;
		}
}
void fun_2(vector<int>&v,int num)
{
		int left = 0,cur = 0,right = v.size()-1;
		while(cur <=right)
		{
        if(v[cur]<num)
						swap(v[cur++],v[left++]);
				else if(v[cur] == num)
							cur++;
				else
							swap(v[cur],v[right--]);	
		}
}
int main()
{
		vector<int>	 v = {2,5,1,6,3,8,5,9,7,1};
    fun_2(v,5);
		for(auto const temp:v)
						cout<<temp<<" ";
		cout<<endl;
   return 0;
}
