/*
 动态规划 划分零钱
 给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：
输入：coins = [1], amount = 0
输出：0
示例 4：

输入：coins = [1], amount = 1
输出：1
示例 5：

输入：coins = [1], amount = 2
输出：2

 
 */

/*
defchange(coins:list[int],amount:int) 
  def dp(n):
    #做选择，选择需要最少的那个结果
	for coin in coins
         res = min(res,1+dp(n-coin));
		return res;

     return dp[amount];

假设数组[1,2,5];组成11


f(0) = 0	 
f(1) = 1
f(2) = 1+min(f[2-1],f[2-2])
f(3) = 1+min(f[3-1],f[3-2])
-~~~~~~~~

 */
 #include<vector>
 #include<iostream>
using namespace std;
int coinChange(vector<int>& coins, int amount) 
    {
       if (amount == 0)
          return 0;
        vector<int> dp(amount+1,amount+1);//注意将数组初始化为amount+1；dp[amount]表示每一个对应的amount的最少次数
        dp[0] = 0;
        for(int i = 1;i<=amount;i++)
        {
            for(auto coin:coins)
            {
                if(coin<=i)
                {
                    dp[i] = min(dp[i],1+dp[i-coin]);//循环对coins数组里面的值进行相减，拿最小值存入amount对应的数组
                }
            }
        }  
        return dp[amount]>amount?-1:dp[amount];
    }
int main()
{
   
   return 0;
}




