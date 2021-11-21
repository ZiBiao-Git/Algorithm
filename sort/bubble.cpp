#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
 异或运算

 （1）n^0 = n   n^n = 0
  (2) a^b^c = a(b^c) 
	下面的交换  (a和b 必须是不同的内存地址)相同位置会变为0
	a = 甲 b = 乙

	 1 a = 甲^乙 b = 乙
	 2.a = 甲^乙 b =甲^乙^乙 ===》b = 甲
	 3 a = 甲^乙^甲 ==》a = 乙 b =甲
*/
void bubble(vector<int> &v)
{
				for(int i = 0;i<v.size();++i)
				{
								for(int j =0 ;j< v.size()-i;j++)
								{
												if(v[j]>v[j+1])
												{ 
                         v[j] ^= v[j+1];
												 v[j+1] ^=v[j];
                         v[j] ^= v[j+1];

																}
								}
				}
}
int main()
{
				vector<int> v = { 2,7,3,1,9,7};
				bubble(v);
				for_each(v.begin(),v.end(),[](int i){cout<<i<<" ";});
				return 0;
}
