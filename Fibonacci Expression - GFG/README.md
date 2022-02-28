# Fibonacci Expression
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a number <strong>N</strong>, evaluate the following&nbsp;expression.&nbsp;<br>
f(n-1)*f(n+1) - f(n)*f(n) where f(n) is the n-th&nbsp;<a href="http://www.geeksforgeeks.org/program-for-nth-fibonacci-number/" target="_blank">Fibonacci number</a>&nbsp;with n &gt;= 1.<br>
Fibonacci Sequence&nbsp;is&nbsp;0, 1, 1, 2, 3, 5, 8, 13,…&nbsp;(here 0 is the&nbsp;0th Fibonacci number)</span></p>

<p><br>
<strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 1
<strong>Output:</strong> 1
<strong>Explaination:</strong> f(n+1)*f(n-1) - f(n)*f(n) 
= 1*0 - 1*1 = -1.</span></pre>

<p><br>
<strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 2
<strong>Output:</strong> 1
<strong>Explaination:</strong> f(n+1)*f(n-1) - f(n)*f(n) 
= 2*1 - 1*1 = 1.</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your Task is to complete the function <strong>fibExpresssion()</strong> which takes the value N as input parameters and returns the required difference.</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(1)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>