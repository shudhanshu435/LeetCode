# 6. Xoring and Clearing
## Easy 
<div class="problem-statement">
                <p></p><p><em><span style="font-size:18px">Bitwise operations help us in a lot of problems. We can find the non-repeating element in an array, find number of set-bits, do division, find subsets and so on. Indeed, we can see that learning to cleverly use bitwise operations is vital to any programmer.</span></em></p>

<p><span style="font-size:18px">You are given an array<strong> A of size N</strong>. You need to do the following:</span></p>

<ol>
	<li><span style="font-size:18px">You need to <strong>xor </strong>the elements of the arrays with their<strong> respective indices</strong>(index starting from 0).</span></li>
	<li><span style="font-size:18px">After step1, <strong>print the array.</strong></span></li>
	<li><span style="font-size:18px">Now,<strong> set all the elements of A to zero</strong>.</span></li>
	<li><span style="font-size:18px">Now, <strong>print A.</strong></span></li>
</ol>

<p><span style="font-size:18px"><strong>Hint: </strong>Use <a href="https://www.geeksforgeeks.org/memset-in-cpp/" target="_blank">memset function </a>to complete the step 3.</span></p>

<p><span style="font-size:18px"><strong>Example:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 10
A[] = 1 2 3 4 5 6 7 8 9 10
<strong>Output:
</strong>1 3 1 7 1 3 1 15 1 3
0 0 0 0 0 0 0 0 0 0
<strong>Explanation:
</strong>First we take xor of every element with
their indices, like 1xor0, 2xor1, 3xor2, 
4xor3 and so on.
Now print the resultant array
Now set all the elements of array to zero
Now print the resultant array</span>
</pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
Since this is a function problem, you don't need to take any input. Just complete the provided functions.&nbsp;In a new line, print the <strong>output</strong>.</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 &lt;= N &lt;= 1000<br>
1 &lt;= A<sub>i</sub> &lt;= 1000</span></p>

<p>&nbsp;</p>
 <p></p>
            </div>