# RecursiveDigitSum

## Description

We define the super digit of an integer _x_ using the following rules:

Given an integer, we need to find the super digit of the integer.

- If _x_ has only _1_ digit, then its super digit is _x_.
- Otherwise, the super digit of _x_ is equal to the super digit of the sum of the digits of _x_.

For example, the super digit of _9875_ will be calculated as:

```
	super_digit(9875)   	9+8+7+5 = 29 
	super_digit(29) 	2 + 9 = 11
	super_digit(11)		1 + 1 = 2
	super_digit(2)		= 2  
```

## Returns

- int: the super digit of repeated times
  
## Input

- The first line contains two space-separated integers, _n_ and _k_. 
