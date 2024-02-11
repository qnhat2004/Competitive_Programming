# Fastest way to calculate the nth Fibonacci number

## Tutorial:
https://www.nayuki.io/page/fast-fibonacci-algorithms

## Formula:
### If n is even number:
$$F(n) = F(\frac{n}{2}) * [2.F(\frac{n}{2} + 1) - F(\frac{n}{2})]$$ 
- **or:** $$F(2n) = F(n) * [2.F(n + 1) - F(n)]$$
### If n is odd number:
$$F(n) = F^2(\frac{n}{2} + 1) + F^2(\frac{n}{2})$$

(Proof in above link)
