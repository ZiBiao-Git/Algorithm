/*
	 1.数组中其他元素都是偶数个；找出其中的奇数个数的元素
	 2.只有两种数出现了奇数个；其他都是偶数个
 
    异或运算
  
  （1）n^0 = n   n^n = 0
   (2) a^b^c = a(b^c)
    下面的交换  (a和b 必须是不同的内存地址)相同位置会变为0
     a = 甲 b = 乙
 
     1 a = 甲^乙 b = 乙
     2.a = 甲^乙 b =甲^乙^乙 ===》b = 甲
     3 a = 甲^乙^甲 ==》a = 乙 b =甲
  */
#include<iostream>
#include<vector>
using namespace std;

void fun(vector<int>&v)
{
				int i = 0;
				for(auto const temp:v)
								i^=temp;
				cout<<i<<endl;			
}
void fun(vector<int>&v)
{
				int i = 0;
				for(auto const temp:v)
								i^=temp;
				//i = a^b (其他偶数异或完都是0)				
        // a!=b ===> i!=0
}
int main()
{

				vector<int> v = {1,2,3,3,2};
				fun(v);
				return 0;
}
