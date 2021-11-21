//二分法(不一定必须有序)
/*
	 (1) 在一个有序数组中，找某一个数是否存在
	 (2) 在一个有序数组中，找>=一个数最左边（右边）的位置
	 (3) 极小值问题：无序数组，任何两个相邻的数一定不相等；就是某一个位置即小于左边；又小于右边
          这中一定会存在局部最小值
 */
#include<iostream>
#include<vector>
using namespace std;

void find_num(vector<int> v,int x)
{
				if(v.empty())
								return;
				int mid = 0;
				int left = 0;
				int right = v.size()-1;
				while(left<=right) //注意等于
				{
				   mid = left + (right - left)/2;//等同于(right+left)/2 防止溢出写成这种
          if (x > v[mid])
							 left = mid+1;
					else if(x<v[mid])
					     right = mid -1;
					else
								{
												cout<<"find it:"<<v[mid]<<endl;
												return;
								}	
				}
				cout<<"not find it"<<endl;
				return ;


}
int main()
{
				vector<int> v = { 1,2};
				find_num(v,1);
				return 0;
}
