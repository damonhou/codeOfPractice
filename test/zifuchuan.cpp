#include <iostream>
/*<div class="notranslate"><p>给你两个长度相同的字符串，<code>s</code> 和 <code>t</code>。</p>

<p>将 <code>s</code>&nbsp;中的第&nbsp;<code>i</code>&nbsp;个字符变到&nbsp;<code>t</code>&nbsp;中的第 <code>i</code> 个字符需要&nbsp;<code>|s[i] - t[i]|</code>&nbsp;的开销（开销可能为 0），也就是两个字符的 ASCII 码值的差的绝对值。</p>

<p>用于变更字符串的最大预算是&nbsp;<code>maxCost</code>。在转化字符串时，总开销应当小于等于该预算，这也意味着字符串的转化可能是不完全的。</p>

<p>如果你可以将 <code>s</code> 的子字符串转化为它在 <code>t</code> 中对应的子字符串，则返回可以转化的最大长度。</p>

<p>如果 <code>s</code> 中没有子字符串可以转化成 <code>t</code> 中对应的子字符串，则返回 <code>0</code>。</p>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "bcdf", cost = 3
<strong>输出：</strong>3
<strong>解释：</strong>s<strong> </strong>中的<strong> </strong>"abc" 可以变为 "bcd"。开销为 3，所以最大长度为 3。</pre>

<p><strong>示例 2：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "cdef", cost = 3
<strong>输出：</strong>1
<strong>解释：</strong>s 中的任一字符要想变成 t 中对应的字符，其开销都是 2。因此，最大长度为<code> 1。</code>
</pre>

<p><strong>示例 3：</strong></p>

<pre><strong>输入：</strong>s = "abcd", t = "acde", cost = 0
<strong>输出：</strong>1
<strong>解释：</strong>你无法作出任何改动，所以最大长度为 1。
</pre>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10^5</code></li>
	<li><code>0 &lt;= maxCost &lt;= 10^6</code></li>
	<li><code>s</code> 和&nbsp;<code>t</code>&nbsp;都只含小写英文字母。</li>
</ul>
</div>*/
#include <vector>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int left = 0 ;
        int right = 0 ;
        int result = 0 ;
        int cost = 0 ;
        int n = s.size() ;
        while(right<n) { //固定窗口
            cost += abs(s[right]-t[right]) ;
            while(cost > maxCost){//窗口溢出，缩放窗口
                cost -= abs(s[left]-t[left]) ;
                left++ ;
            } 
            result=max(result, right-left+1) ;
            right++ ;
        }
        return result ;
    } 
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

