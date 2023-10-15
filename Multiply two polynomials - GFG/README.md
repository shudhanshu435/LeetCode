# Multiply two polynomials
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given two polynomials represented by two arrays&nbsp;that&nbsp;contains the coefficients of poynomials, returns the polynomial in form of array formed after multiplication of given polynomials.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
M = 4, N = 3
Arr1 = {1 , 0, 3, 2}
Arr2 = {2, 0, 4}
<strong>Output:</strong> {2, 0, 10, 4, 12, 8}
<strong>Explaination:</strong> 
First polynomial:&nbsp;
1 + 0x<sup>1</sup> + 3x<sup>2</sup> + 2x<sup>3</sup>
Second polynomial:&nbsp;
2 + 0x<sup>1</sup> + 4x<sup>2</sup>
Product polynomial:
2 + 0x<sup>1</sup> + 10x<sup>2</sup> + 4x<sup>3</sup> + 12x<sup>4</sup> + 8x<sup>5</sup></span></pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
M = 5, N = 4
Arr1 = {1, 9, 3, 4, 7}
Arr1 = {4, 0, 2, 5}
<strong>Output:</strong> {4, 36, 14, 39, 79, 23, 34, 35</span><span style="font-size:18px">}
<strong>Explaination:</strong> 
First polynomial:&nbsp;
1 + 9x<sup>1</sup> + 3x<sup>2</sup> + 4x<sup>3 </sup>+ 7x<sup>4</sup>
Second polynomial:&nbsp;
4 + 0x<sup>1</sup> + 2x<sup>2 </sup>+ 5x<sup>3</sup>
Product polynomial:
4 + 36x<sup>1</sup> + 14x<sup>2</sup> + 39x<sup>3</sup> + 79x<sup>4</sup>&nbsp;+ 23x<sup>5 </sup>+ 34x<sup>6</sup>&nbsp;+ 35x<sup>7</sup></span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>polyMultiply()</strong>&nbsp;which takes the array <strong>Arr1[]</strong>&nbsp;and <strong>Arr2[]</strong>and their&nbsp;size M and N<strong>&nbsp;</strong>as input parameters&nbsp;and returns the polynomial in form of array formed after multiplication of given polynomials..</span></p>

<p><br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(M*N)<br>
<strong>Expected Auxiliary Space:</strong> O(M+N)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ M, N&nbsp;≤ 100<br>
1 ≤&nbsp; Arr1[i] , Arr2[i]&nbsp; ≤ 100</span></p>
</div>