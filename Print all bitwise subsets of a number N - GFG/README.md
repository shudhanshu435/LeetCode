# Print all bitwise subsets of a number N
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a number <strong>N</strong>, print all the numbers which are a bitwise subset of the binary representation of N. Bitwise subset of a number <strong>N</strong> will be the numbers <strong>i</strong> in the range <strong>0 </strong>≤<strong> i </strong>≤ <strong>N</strong> which satisfy the below condition:<br>
<strong>N &amp; i == i</strong></span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>:
N = 5
<strong>Output:</strong>&nbsp;5 4 1 0
<strong>Explanation</strong>:
   0 &amp; 5 = 0
&nbsp; &nbsp;1&nbsp;&amp; 5 = 1
&nbsp; &nbsp;2 &amp; 5 = 0
&nbsp; &nbsp;3 &amp; 5 = 1
&nbsp; &nbsp;4 &amp; 5 = 4
&nbsp; &nbsp;5 &amp; 5 = 5
&nbsp;&nbsp;</span>
</pre>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 9
<strong>Output: </strong>9 8 1 0
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>printSubsets()</strong>&nbsp;which takes the integer N as input parameters and returns the&nbsp;array of integers that satisfy the above condition.<br>
<br>
<strong>Expected Time Complexity:</strong> </span>&nbsp;<span style="font-size:18px">O(K), where K is the number of bitwise subsets of N.</span><br>
<span style="font-size:18px"><strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10000</span></p>
 <p></p>
            </div>