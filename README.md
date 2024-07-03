# 42_push_swap

![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)

Author: Martijn Wallage

Project of the 42 Core Curriculum. 

Score: 125%.

## About

Push_swap is a program which sorts any series of unique positive numbers, using two "stacks", as the subject call them, though they are better thought of as discs: they rotate.

Both discs have a current, next and previous element: you can imagine a reading head, or the ball in a roulette wheel, which always picks out one element and can move only to the next or to the previous element. 

Of each disc, the next element of the last element is the first element, and the previous element of the first element is the last element.

```
    current element
          |
          v
  <- 10 3 7 5 11 123 -> wrap around
```

## Rules

You have 2 stacks named **a** and **b**.

At the beginning:
- The stack **a** contains a random amount of negative and/or positive numbers which cannot be duplicated.
- The stack **b** is empty.

The goal is to sort in ascending order numbers into stack **a**. To do so you have the following operations at your disposal:
- `sa` (swap **a**): Swap the first 2 elements at the top of stack **a**. Do nothing if there is only one or no elements.
- `sb` (swap **b**): Swap the first 2 elements at the top of stack **b**. Do nothing if there is only one or no elements.
- `ss` : `sa` and `sb` at the same time.
- `pa` (push **a**): Take the first element at the top of **b** and put it at the top of **a**. Do nothing if b is empty.
- `pb` (push **b**): Take the first element at the top of **a** and put it at the top of **b**. Do nothing if a is empty.
- `ra` (rotate **a**): Shift up all elements of stack a by 1. The first element becomes the last one.
- `rb` (rotate **b**): Shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` (reverse rotate **a**): Shift down all elements of stack **a** by 1. The last element becomes the first one.
- `rrb` (reverse rotate **b**): Shift down all elements of stack **b** by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time

## Data Structure

Since you often have to access the previous and next element on each disc, it is best to implement them as doubly linked lists.

## Algorithm

I tried many different algorithms but ended up implementing something close to the famous <a href="https://medium.com/@ayogun/push-swap-c1f5d2d41e97">Turk algorithm</a>.

Question: why do successful push_swap algorithms start by pushing almost all numbers to the B stack? You might think that sometimes two numbers in the A stack can be sorted by, for example, swapping them. Or they are already sorted and we can just move on to the next element.

Answer: when you push an element to the B stack, the next element on the A stack will automatically become the current element. So you get that operation for free.

## Bonus

Write a checker. Once you have functions for all the operations, which you do if you have written push_swap, it is straightforward to write a checker. This is one of the easiest bonuses in the 42 core curriculum.

A better kind of checker, very useful for evaluations, is the <a href="https://github.com/o-reo/push_swap_visualizer">Push_swap Visualizer</a>
