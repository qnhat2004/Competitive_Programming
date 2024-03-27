## You can calculate 2^n using bit shift instead of using pow(2, n)
```cpp
int power = (1 << n);
```

## Divide n by 2^k
```cpp
int n = 100;
int k = 3;
int result = n >> k; // result = 100 / 2^3 = 12

// or if you want to calculate n/2
result = n >> 1; // result = 100 / 2 = 50
```

## Using __lg(n) instead of (int)log2(n), it returns interger number of log2(n) too but the syntax is shorter
```cpp
int log2_of_n = std::__lg(n); // same with (int)log2(n)
```

## So you can find the number is an exponentional of 2 not greater than n by using __lg and bit shift
```cpp
int Exp_of_2_not_greater_than_n = (1 << __lg(n));
```

