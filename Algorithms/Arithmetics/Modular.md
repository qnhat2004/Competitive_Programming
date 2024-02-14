# Phép chia lấy dư có một số tính chất quan trọng sau:

1. Tính chất phân phối: (a + b) % x tương đương với (a % x + b % x) % x. Điều này có nghĩa là bạn có thể tính phép chia lấy dư cho từng số trước khi cộng chúng lại.
2. Tính chất giao hoán: a % x tương đương với x % a (nếu a không bằng 0).
3. Tính chất kết hợp: (a + (b + c) % x) % x tương đương với ((a + b) % x + c) % x.
4. Tính chất phân phối của phép nhân: (a * b) % x tương đương với (a % x * b % x) % x.

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
