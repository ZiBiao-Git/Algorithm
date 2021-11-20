/*
	 选择排序是一种简单直观的排序算法。
	 它的工作原理是：第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
	 然后再从剩余的未排序元素中寻找到最小（大）元素，继续放在起始位置知道未排序元素个数为0。

	   选择排序的步骤：
	 1>首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
	 2>再从剩余未排序元素中继续寻找最小（大）元素，然后放到未排序序列的起始位置。
	 3>重复第二步，直到所有元素均排序完毕。

	 稳定性

	   在选择排序中，每趟都会选出最大元素与最小元素，然后与两端元素交换，此时，待排序序列中如果存在与原来两端元素相等的元素，稳定性就可能被破坏。如[5,3,5,2,9]，在array[0]与array[3]元素交换时，序列的稳定性就被破坏了，所以选择排序是一种不稳定的排序算法。

	 时间复杂度

	   选择排序的时间复杂度为O(n2)。

	 适用场景

	   待排序序列中，元素个数较少时。

 */
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void select(vector<int> &v)
{
				if(v.empty() || v.size()<= 2)
								return;	
				for(int i = 0;i<v.size(); ++i)
				{
								int min = i;
								for (int j = i+1 ; j<v.size();j++ )
								{
												if(v[min] > v[j])
												{
																min = j;
												}
								}
								swap(v[i],v[min]);
				}
}

//优化 同时找出最大值与最小值，放到数组两端，这样就能将遍历的趟数减少一半。第一次选择最大值与最小值，
void select2(vector<int> &v)
{
				if(v.empty() || v.size()<= 2)
								return;
				int left = 0,right = v.size() - 1;
				while(left < right)
				{
								//这里的min 和max 不能赋值为0；因为left和right是变化的
								int min = 0;
								int max = 0;
								for (int i = left ; i<=right;i++ )
								{
												if(v[min] > v[i])
												{
																min = i;
												}
												if (v[max] < v[i])
																max = i;
								}
								swap(v[max],v[right]);
								if(min == right) //防止最大值在第一个；被交换
								{
												min = max;
								}
								swap(v[min],v[left]);
								++left;
								--right;
				}
}
void select3(vector<int> &arr)
{
				        /*初始化左端、右端元素索引*/
	    int left = 0;
	    int right = arr.size() - 1;
	    while (left < right){
	    	/*初始化最小值、最大值元素的索引*/
	        int min = left;
	        int max = right;
	        for (int i = left; i <= right; i++){
	        	/*标记每趟比较中最大值和最小值的元素对应的索引min、max*/
	            if (arr[i] < arr[min])
	                min = i;
	            if (arr[i] > arr[max])
	                max = i;
	        }
	        /*最大值放在最右端*/
					swap(arr[max],arr[right]);
	        /*此处是先排最大值的位置，所以得考虑最小值（arr[min]）在最大位置（right）的情况*/
	        if (min == right)
	            min = max;
	        /*最小值放在最左端*/
					swap(arr[min],arr[left]);
	        /*每趟遍历，元素总个数减少2，左右端各减少1，left和right索引分别向内移动1*/
	        left++;
	        right--;
	    }

}
int main()
{
				vector<int> v = {9,3,1,5,8,2,5};
				select2(v);
				for(const int &temp:v)
								cout<<temp<<" ";
				cout<<endl;
				return 0;
}
