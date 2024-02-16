# Modular arithmetic has some important properties:
- Distributivity: (a + b) % x $\equiv$ (a % x + b % x) % x.
- Commutative: a % x $\equiv$ x % a (if a != 0).
- Cohesive: (a + (b + c) % x) % x $\equiv$ ((a + b) % x + c) % x.
- Distributivity of multiplication: (a * b) % x $\equiv$ (a % x * b % x) % x.

# Modular Arithmetic
- (x + y) mod m = (x mod m + y mod m) mod m
- (x - y) mod m = (x mod m - y mod m + m) mod m   (*)
- (x * y) mod m = (x mod m + y mod m) mod m
- $x^n$ mod m = $(x \ mod \ m)^n$ mod m

> [!IMPORTANT]
> At expression `(x - y + m) mod m`, we must add the value m because the result of `x - y` can be negative, then `(x-y) mod m` is other with expectation. Example `-10 mod 3 = 2` instead of 1, because the remainder r is always positive and `-10 = (-4)*3 + 2`, so it return 2 instead of 1 **(Except Python, in python it also return 1, so we may not need to add m)**. Thus, to ensure the result of `x - y` is always a positive number, we add the value `m` before performing modulo `m`. It's not change the result because **(a + m) mod m = a mod m**

### Practice:
https://www.hackerrank.com/contests/300-bai-code-thieu-nhi/challenges/fibonacci-tle/problem

---

# Modulo, Modular and Modulus
See details: https://www.geeksforgeeks.org/difference-between-modulo-and-modulus/

## Modulo
It basicaly an operator and denoted by **mod** and in programming used **"%"**, it is a function which return a remainder value of division between two numbers
```
1. 12 mod 5 // 12 modulo 15
2. 38 ≡ 14 (mod 12) // 38,14 are congruent modulo 12 - (Đồng dư), it mean 38 mod 12 = 14 mod 12 = 2
```

## Modulus
- It's simply a **noun** which is the value N of "x mod N"
- We abbreviate it as: **"N is the modulus"**
> [!NOTE]
> In the previous example, the **congruent modulo** basically means that the different of two numbers 38 and 24 is an interger the multiple of **modulus** 12
```
38 ≡ 14 (mod 12) -> so 38 - 14 = 24 is double of 12
```

# Modular (mô-đun)
It basically means that arithmetic operation (modular arithmetic)
