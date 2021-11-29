#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void merge(vector<int>&v,int left,int mid,int right)
{
   int *temp = new int[right-left+1];
	 int p1 = left,p2 = mid +1,i = 0;
	 while(p1 <= mid && p2 <= right)
					 temp[i++] = v[p1]<=v[p2]?v[p1++]:v[p2++];

	 while(p1<= mid)
					 temp[i++] = v[p1++];
	 while(p2<= right)
					 temp[i++] = v[p2++];
	 for(int i = 0;i<right-left+1;++i)
					 v[left+i]=temp[i];
	 delete []temp;

}
void sort(vector<int>&v,int left,int right)
{
	if(left == right)
					return;
  int mid = left +((right - left)>>1);
	sort(v,left,mid);
	sort(v,mid+1,right);
	merge(v,left,mid,right);
}

//小和问题
int merge_1(vector<int>&v,int left,int mid,int right)
{
   int *temp = new int[right-left+1];
	 int p1 = left,p2 = mid +1,i = 0,sum = 0;
	 while(p1 <= mid && p2 <= right)
	 {
			sum+= v[p1]<v[p2]?(right-p2+1)*v[p1]:0; 		 
	 temp[i++] = v[p1]<=v[p2]?v[p1++]:v[p2++];

	 }

	 while(p1<= mid)
					 temp[i++] = v[p1++];
	 while(p2<= right)
					 temp[i++] = v[p2++];
	 for(int i = 0;i<right-left+1;++i)
					 v[left+i]=temp[i];
	 delete []temp;
	 return sum;

}
int sort_1(vector<int>&v,int left,int right)
{
	if(left == right)
					return 0;
  int mid = left +((right - left)>>1);
	return sort_1(v,left,mid)+
	sort_1(v,mid+1,right)+
	merge_1(v,left,mid,right);
}
int main()
{
		vector<int>	 v = {1,3,2,51,5};
    sort(v,0,4);
		for(auto const temp:v)
						cout<<temp<<" ";
		cout<<endl;
		cout<<sort_1(v,0,4)<<endl;;
   return 0;
}
