## You can calculate 2^n using bit shift instead of using pow(2, n)
```
int power = (1 << n);
```

## Using __lg(n) instead of (int)log2(n), it returns interger number of log2(n) too but the syntax is shorter
```
int log2_of_n = std::__lg(n); // same with (int)log2(n)
```

## So you can find the number is an exponentional of 2 not greater than n by using __lg and bit shift
```
int Exp_of_2_not_greater_than_n = (1 << __lg(n));
```
