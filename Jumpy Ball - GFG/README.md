# Jumpy Ball
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">You have a jumpy ball. You throw it up from the ground up to a height of H. The ball is jumpy, so when it comes back to the ground, it rebounds and goes up again to a distance of floor(H/2). This keeps on repeating until it can't rebound anymore. You need to find the total distance traveled by the ball.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:
</strong>H = 10</span>

<span style="font-size:18px"><strong>Output:
</strong>36</span>

<strong><span style="font-size:18px">Explanation:
</span></strong><span style="font-size:18px">H is 10. From ground to H it travels d=10.
From H to ground it travels d=10+10. Now H
becomes floor(10/2). So ball rebounds to d=10+10+5.
It goes down to the ground. d=10+10+5+5. Now H
becomes floor(5/2). So ball rebounds to d=10+10+5+5+2.
The ball goes down. d=10+10+5+5+2+2. H becomes
floor(2/2). So ball rebounds to d=10+10+5+5+2+2+1.
It goes down to the ground. d=10+10+5+5+2+2+1+1.
H becomes floor(1/2). H is zero so no rebound.
Total d=36.</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><strong><span style="font-size:18px">Input:
</span></strong><span style="font-size:18px">H = 20</span>

<strong><span style="font-size:18px">Output:
</span></strong><span style="font-size:18px">76</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>jumpyBall() </strong>which takes&nbsp;an integer <strong>H</strong>&nbsp;as an input parameter and returns the total distance traveled by the ball.<br>
<br>
<strong>Expected Time Complexity:</strong>&nbsp;O(log H)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
0 &lt;= H &lt;= 10<sup>15</sup></span></p>

<p>&nbsp;</p>
 <p></p>
            </div>