# Doctors Clinic
## Easy
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given two positive integers <strong>N</strong> and <strong>X</strong>, where N is the number of total patients and X is the time duration(in minutes) after which a new patient arrives. Also, doctor will give only 10 minutes to each patient. The task is to calculate the time (in minutes) the<strong> last patient</strong> needs to wait.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 4, X = 5
<strong>Output:</strong> 15
<strong>Explaination:</strong> The arrival time of the 
patients are 0, 5, 10 and 15 respectively. 
The times when the first three patients 
are checked are respectively 10, 20, 30. 
So the Waiting time is 30 - 15 = 15.</span></pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 3, X = 10
<strong>Output:</strong> 0
<strong>Explaination:</strong> The incoming time of the 
patients are 0, 10 and 20 and the firts 
two patients are finished checking at 10, 
20. So the last patient does not need to 
wait.</span></pre>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You do not need to read input or print anything. Your task is to complete the function <strong>waitingTime()</strong> which takes N and X as input parameters and returns the waiting time of the last patient.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(1)<br>
<strong>Expected Auxiliary Space:</strong> O(1)</span></p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 100<br>
1 ≤ X ≤ 30</span></p>
 <p></p>
            </div>