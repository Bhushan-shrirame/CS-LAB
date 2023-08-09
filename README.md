<h1>CSLAB Assignments [CS6P001]</h1>
This Repo Contains the Solutions for CSLAB Assignments(CS6P001)[Computer Systems Lab] taught @ IITBBS.
<h2>Assignment 1</h2>
<ul>
  <li>
    Catalan numbers C(n), n &gt; 0, are defined recursively as follows.<br>
    C(0) = 1,<br>
    C(n) = C(0)C(n−1) + C(1)C(n−2) + C(2)C(n−3) + · · · + C(n−1)C(0) for n &gt; 1<br>
    Write a recursive function to return C(n).<br>
  </li>
  <li>
    In a circular linked list, the next pointer of the last node points back to the first node
    in the list. Write a function that, given a circular linked list and a positive integer k,
    replaces the key at each node by the maximum of the next k elements in the list. For
    example, if the input list is <strong>3,1,6,2,7,4,5,2,9,8,5,2,</strong> and k = 3, the list should be
    updated to <strong> 6,7,7,7,5,9,9,9,8,5,3,6</strong>. So that you know, no new linked list is to be created. The
    existing list must be modified.
  </li>
  <li>
    A file input.txt stores student records. The first line of the file stores the count n of
    students. This is followed by n lines, each storing a roll number (a string like
    23CS06033), the CGPA of the student (a real number like 8.76), and finally the name
    of the student (may contain spaces). The three fields in each line are separated by
    one or more spaces (or tabs). Read the student records, sort the records based on
    student names, and write the sorted records to a file output.txt in the format Name
    RollNo CGPA. You may use any sorting algorithm.
  </li>
  <li>
    You are given an n×n matrix M of integers.<br>
    (a) Sort each row of M in the ascending order.<br>
    (b) Sort each column of M in descending order.<br>
    (c) Write a function that, given an integer x, finds out whether x is an element of M.<br>
    Assume that you have applied the sorting phases of Parts (a) and (b). Your
    program should run in O(n) time.
  </li>
  <li>
    (a) Build a stack S of integers. Write functions to implement the initialize, top, push,
    and pop operations for S.<br>
    (b) Use the stack operations to evaluate a postfix expression involving integer
    operands and the operators +, -, *, /, and %.<br>
  </li>
</ul>

<h2>Assignment 2</h2>
<ul>
  <li>
    Given a directed graph with N nodes and E edges where the weight of each of the
edges is greater than one, also given a source S and a destination D. Write a program
to find the path with the minimum product of edges from S to D. If there is no path
from S to D then print -1. (10 Marks)
Input: N = 3, E = 3, Edges = {{{1, 2}, 5}, {{1, 3}, 9}, {{2, 3}, 1}}, S = 1, and D = 3
Output: 5
The path with the smallest product of edges will be 1->2->3
with the product as 5*1 = 5.
Input: N = 3, E = 3, Edges = {{{3, 2}, 5}, {{3, 3}, 9}, {{3, 3}, 1}}, S = 1, and D = 3
Output: -1
  </li>
  <li>
    Consider the task of multiplying two integer matrices A and B, each of size 500 × 500.
Each matrix can have at most 500 non-zero entries. Any row of A or B that contains at
least one non-zero element must have no less than 50 non-zero elements. (10 Marks)
(a) Propose a space-efficient data structure for this task.
(b) Based on your proposed data structure, design an efficient algorithm to multiply
A and B. The resulting matrix should be stored separately.
(c) What is the maximum number of integer multiplications needed to complete this
task as per your implementation?
  </li>
  <li>
    The houses in a village are connected by dirt roads. The panchayat of the village
wanted to plan the paving of proper roads to make travel easy for villagers. They had
two requirements:
● Enough roads must be paved so that it is possible for everyone to travel from
their house to anyone else's house only along paved roads, and
● The paving should cost as little as possible. The houses are numbered from 0
to n-1, and the number of dirt roads is m, where each dirt road connects any
2 houses.
The input should be in the following format:
➢ 1. n //no of houses
➢ 2. m //no of dirt roads
➢ 3. 2D array of size m x 3

where every row of the 2D array describes a dirt road; in every row, the first 2
elements represent the house number that the road connects, and the 3rd element
represents the cost of building that road.
The output should be the expense required to build the roads that satisfy the above
requirements. (10 Marks)
Input:
5 6
1 2 6
2 3 5
3 4 4
1 4 1
1 3 2
3 5 3
Output:
11
  </li>
  <li>
    Let S = {x1
, x2
, . . .xn
} be a set of n integers. A pair (xi

, xj ) (where i ≠ j) is said to be the

closest pair if |xi-xj | ≤ |xi’-xj’|, for all possible pairs (xi’

, xj’), i′, j′ = 1, 2, . . . , n, i′ ≠ j′. (10

Marks)
(a) Describe a method for finding the closest pair among the set of integers in
S using O(n log2 n) comparisons.
(b) Now suggest an appropriate data structure for storing the elements in S
such that if a new element is inserted into the set S or an already existing
element is deleted from the set S, the current closest pair can be reported in
O(log2 n) time.
(c) Briefly explain the method of computing the current closest pair and the
necessary modification of the data structure after each update. Justify the
time complexity.
  </li>
</ul>
