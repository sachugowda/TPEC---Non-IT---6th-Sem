**Puzzles**
--------------------------------------------------------------------------------------------------------------------------------------------------
**Question 1:** In a one day international cricket match, considering no extras(no wides, no ‘no’ balls, etc.) and no overthrows.

What is the maximum number of runs a batsman can score in an ideal case?

Note:” Here we assume an ideal and little practical scenario. We assume that a batsman can not run for more than 3 runs in a ball, as otherwise there is no limit, he can run infinite runs(theoretically) in a ball, as far as the opposite team does not catch the ball.”

https://www.geeksforgeeks.org/puzzle-37-maximum-run-in-cricket/

**Question 2:** Four people need to cross a rickety bridge at night. Unfortunately, they have one torch and the bridge is too dangerous to cross without a torch. The bridge can support only two people at a time. All the people don’t take the same time to cross the bridge. Time for each person: 1 min, 2 mins, 7 mins, and 10 mins. What is the shortest time needed for all four of them to cross the bridge?

https://www.geeksforgeeks.org/four-people-rickety-bridge/

**Question 3:**: A car has 4 tyres and 1 spare tyre. Each tyre can travel a maximum distance of 20000 km before wearing off. What is the maximum distance the car can travel before you are forced to buy a new tyre? You are allowed to change tyres (using the spare tyre) an unlimited number of times. 

https://www.geeksforgeeks.org/puzzle-29-car-wheel-puzzle/

[More Puzzles](https://www.geeksforgeeks.org/puzzles/)

-------------------------------------------------------------------------------------------------------------------------------------------------
<hr>
<b>Complete Road Map for Placements</b> <br/>
https://takeuforward.org/strivers-a2z-dsa-course/
<hr>

## Basics Recap
<hr>

**Input and Output**
Write a program that takes a character as input and prints 1, 0, or -1 according to the following rules:

- 1, if the character is an uppercase alphabet (A - Z).
- 0, if the character is a lowercase alphabet (a - z).
- -1, if the character is not an alphabet.

**Example:**

Input: The character is 'a'.

Output: 0

Explanation: The input character is lowercase, so the output is 0.

---

**Data Types**

Data type refers to the type of value a variable has and the way the computer interprets it.

Each data type has a different size. You've studied 5 different data types and their sizes:

- Integer: 4 bytes
- Long: 8 bytes
- Float: 4 bytes
- Double: 8 bytes
- Character: 1 byte

Given a data type, print its size in bytes.

**Example:**

Input: Long

Output: 8

Explanation: The size of a Long variable is 8 bytes.

---

**Switch Case Statement**

Programming languages have some conditional / decision-making statements that execute when some specific condition is fulfilled.

Switch-case is one of the ways to implement them.

In a menu-driven program, the user is given a set of choices of things to do (the menu) and then is asked to select a menu item.

There are 2 choices in the menu:

1. Choice 1 is to find the area of a circle having radius 'r'.
2. Choice 2 is to find the area of a rectangle having dimensions 'l' and 'b'.

You are given the choice 'ch' and an array 'a'.

If ‘ch’ is 1, ‘a’ contains a single number ‘r’. If ‘ch’ is 2, ‘a’ contains 2 numbers, ‘l’ and ‘b’.

Consider the choice and print the appropriate area.

**Example**

Input:
- ‘ch’ = 2
- ‘a’ = [3, 2]

Output:
- area = 6

Explanation:
Since the choice ‘ch’ is 2, we have to print the area of the rectangle having ‘l’ = 3 and ‘b’ = 2, which is 6.

---

### Nth Fibonacci Number

The n-th term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula:

```
F(n) = F(n - 1) + F(n - 2)
```

Where, F(1) = 1 and F(2) = 1.

Provided 'n', you have to find out the n-th Fibonacci Number. Handle edge cases like when 'n' = 1 or 'n' = 2 by using conditionals like if else and return what's expected.

**Indexing starts from 1.**

### Example

**Input:**

```
6
```

**Output:**

```
8
```

**Explanation:**

The number is ‘6’, so we have to find the 6th Fibonacci number. Using the given formula of the Fibonacci series, we get the series:    
[1, 1, 2, 3, 5, 8, 13, 21]. So the 6th element is 8, hence we get the output.

