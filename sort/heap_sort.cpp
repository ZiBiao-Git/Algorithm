#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void heapify(vector<int>&v,int index,int heapSize)
{
   int left = 2*index +1;
	 while(left < heapSize)
	 {
     int largest = (left + 1 < heapSize)&&(v[left+1] > v[left])?left +1 : left;
		 largest = v[largest]>v[index]?largest:index;
		 if(largest == index)
						 break;
		  swap(v[index],v[largest]);
			index = largest;
			left = 2 *index +1;
	 }

}
void heap_insert(vector<int>&v,int index)
{
    if(v[index]> v[(index-1)/2])
		{
        swap(v[index],v[(index-1)/2]);
		}
}
void heap_sort(vector<int>&v)
{
   if(v.empty()||v.size() ==1)
					 return;
  for(int i = 0;i<v.size();++i)
					heap_insert(v,i);
  
	int heapSize = v.size();
	swap(v[0],v[--heapSize]);
	while(heapSize > 0)
	{
      heapify(v,0,heapSize);   
			swap(v[0],v[--heapSize]);
	}
}


int main()
{
		vector<int>	 v = {3,51,2,5,1};
    heap_sort(v);
		for(auto const temp:v)
						cout<<temp<<" ";
		cout<<endl;
   return 0;
}
