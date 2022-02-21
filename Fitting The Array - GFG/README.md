# Fitting The Array
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Adobe is playing an array game. He is weak in the concepts of arrays. Adobe is given two arrays a[ ] and b[ ] of the same size. The array a[ ] will be said to fit in array b[ ]&nbsp;if by arranging the elements of both array, there exists a solution such that i_th&nbsp;element of a[ ] is less than or equal to an i_th&nbsp;element&nbsp;of b[ ]. Help Adobe find if the given arrays are fit or not.</span></p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> A[] = {7, 5, 3, 2} and 
        B[] = {5, 4, 8, 7}
<strong>Output :</strong> YES
<strong>Explanation:</strong>
Transform A = {2, 3, 5, 7} and 
B = {4, 5, 7, 8}. then both array will 
fit in between.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> A[] = {1, 2, 3} and B[] = {1, 2, 3} <strong>
Output :</strong>  YES </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>isFit()</strong> that takes an array <strong>(a)</strong>, another array <strong>(b),</strong>&nbsp;sizeOfArray <strong>(n)</strong>, and return <strong>true</strong>&nbsp;if array a[ ] fit in array b[ ] otherwise print <strong>false</strong>. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*LOG(N)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p><br>
<br>
<br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
0 ≤ a[i], b[i] ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>