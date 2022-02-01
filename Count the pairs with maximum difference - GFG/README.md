# Count the pairs with maximum difference
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array <strong>a[ ] </strong>of <strong>N</strong> elements, the task is to find the number of ways to choose&nbsp;pairs <strong>{a[i], a[j]}</strong> such that their absolute difference is&nbsp;maximum.</span></p>

<p><span style="font-size:18px"><strong>Example:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5
a[] = {3, 2, 1, 1, 3}
<strong>Output:</strong>
4</span>
<span style="font-size:18px"><strong>Explanation:</strong>
The maximum difference you can find is 2
which is from 3 - 1 = 2.
Number of ways of choosing it:
1) Choosing the first and third element
2) Choosing the first and fourth element
3) Choosing the third and fifth element
4) Choosing the fourth and fifth element
Hence, the answer is 4.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>countPairs() </strong>that take <strong><em>array(a) </em></strong><em>and</em><strong>&nbsp;<em>sizeOfArray(N)</em></strong>&nbsp;as input parameters, and returns the count of pairs which has the maximum difference. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>