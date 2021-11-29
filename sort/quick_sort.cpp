#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void pos_fun(vector<int>&v,int left,int right)
{
				if(left < right)
				{
								int key = v[left];
								int i = left;
								int j = right;
								while(i<j)
								{
												while(i<j && v[j]>=key)
																j--;
												v[i]=v[j];
												while(i<j &&v[i]<= key)
																i++;
												v[j]=v[i];
								}
								v[i]=key;
								pos_fun(v,left,i-1);
								pos_fun(v,i+1,right);
				}
				else
								return;
}

int main()
{
				vector<int>	 v = {1,3,2,51,5};
				pos_fun(v,0,4);
				for(auto const temp:v)
								cout<<temp<<" ";
				cout<<endl;
				return 0;
}
