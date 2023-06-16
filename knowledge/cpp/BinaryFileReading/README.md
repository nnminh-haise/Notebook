
# Reading Binary File In C++

## Realistic problem

Given a binary file (`student.txt`) consist of a $100000$ student with each student is exactly $1$KB in size and the maximum storing capacity of the internal memory if $10000$ student.

Each student has:

- Student ID: unique int
- First name: std::string
- Last name: std::string
- Class ID: std::string
- (and more)

How to sort the file follow by the student's ID.

## Solution

At first, we can see that $100000$ student's IDs is around $400000$KB. And the maximum internal memory size is $10240000$KB which is much larger than $400000$KB. Therefore we can store all of the student's ID.

With that in mind, we can store the student's IDs in an array then sort them in the increase order using `Quick Sort` algorithm. This step will takes $O(n\log n)$ time complexity.

> *Now, we have sorted the student's IDs only, but the other infomation such as first name, last name, etc is still there. How can we relate the rest of the student's infomation with the corresponding ID?*

One in-efficient solution is that for each every student's ID in the sorted list, we search for the corresponding student in the file. This solution has the time complexity of $O(n^2)$, because basically for every elements in the list we loop through the list once.

> *Note that the data is stored in a binary file. Therefore we can think of a way to find the student which has the corresponding ID in $O(1)$ time complexity.*



