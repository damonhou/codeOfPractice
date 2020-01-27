#include <iostream>
#include <vector>
using namespace std ;
/*
 *<div class="description__2b0C"><div class="content__1Y2H"><div class="notranslate"><p>我们将给定的数组&nbsp;<code>A</code>&nbsp;分成&nbsp;<code>K</code>&nbsp;个相邻的非空子数组 ，我们的分数由每个子数组内的平均值的总和构成。计算我们所能得到的最大分数是多少。</p>

<p>注意我们必须使用 A 数组中的每一个数进行分组，并且分数不一定需要是整数。</p>

<pre><strong>示例:</strong>
<strong>输入:</strong> 
A = [9,1,2,3,9]
K = 3
<strong>输出:</strong> 20
<strong>解释:</strong> 
A 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
我们也可以把 A 分成[9, 1], [2], [3, 9].
这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
</pre>

<p><strong>说明: </strong></p>

<ul>
	<li><code>1 &lt;= A.length &lt;= 100</code>.</li>
	<li><code>1 &lt;= A[i] &lt;= 10000</code>.</li>
	<li><code>1 &lt;= K &lt;= A.length</code>.</li>
	<li>答案误差在&nbsp;<code>10^-6</code>&nbsp;内被视为是正确的。</li>
</ul>
</div></div></div>
 * */
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int length = A.size() ;          
        vector<double>sum(length+1, 0) ;
        for(int i=0; i<length; i++) { //对于数组A进行求和
            sum[i+1] = sum[i]+A[i] ;
        }
        vector<vector<double>>dp(length+1, vector<double>(K+1)) ;
        for(int i=1; i<=length; i++) {
            dp[i][1] = sum[i]/i ; //当数组A划分成一段时的值
        }

        for(int i=2; i<=K; i++) {
            for(int j=i; j<=length; j++) {
                for(int l=1; l<j; l++) {
                    //0-i之间的某个位置j前的k-1段的最大平均值
                    //和j到i之间的平均值
                    //dp[i][k] = max(dp[j][k-1]+sum(j~i)/(i-j))
                    dp[j][i] = max(dp[j][i], dp[l][i-1]+(sum[j]-sum[l])/(j-l)) ;
            }
        }
        return dp[length][K];
    }
};

int main() {
        
    return 0;
}

