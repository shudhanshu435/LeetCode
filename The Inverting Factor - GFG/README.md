# The Inverting Factor
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Ishaan being curious as always was playing with numbers when he started to reverse the numbers. He invented something called the "inverting factor" of two numbers.<br>
The inverting Factor of 2 integers is defined as the absolute difference between the reverse of the 2 integers.<br>
Ishaan has an array A of N integers. He wants to find out the smallest possible Inverting Factor among all pairs of his integers. Help him find that.<br>
<strong>Note :</strong> Trailing zeros in a number of ignored while reversing, i.e. 1200 becomes 21 when reversed.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>â€‹Input :</strong> arr[ ] = {56, 20, 47, 93, 45}
<strong>Output :</strong> 9
<strong>Explanation:</strong>
The minimum inverting factor is 9, of the pair (56,47)
Reverse 56 -&gt; 65 and 47 -&gt; 74
difference between them is 9.
</span></pre>

<p><br>
<span style="font-size:18px"><strong>â€‹Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> arr[ ] = {48, 23, 100, 71, 56, 89} <strong>
Output :</strong>  14 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
This is a function problem. The input is already taken care of by the driver code. You only need to complete the function <strong>findMinimumInvertingFactor()</strong> that takes an array <strong>(arr)</strong>, sizeOfArray <strong>(n)</strong>, and return the smallest possible Inverting Factor among all pairs of his integers. The driver code takes care of the printing.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(N*LOG(N)).<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints :&nbsp;</strong><br>
2 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>7</sup></span></p>
 <p></p>
            </div>