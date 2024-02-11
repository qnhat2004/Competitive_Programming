# Fastest way to calculate the $n^{th}$ Fibonacci number

## Tutorial:
https://www.nayuki.io/page/fast-fibonacci-algorithms

## Formula:
### If n is even number:
$$F(n) = F(\frac{n}{2}) \times [2.F(\frac{n}{2} + 1) - F(\frac{n}{2})]$$ 
- **or:** $$F(2n) = F(n) \times [2.F(n + 1) - F(n)]$$
### If n is odd number:
$$F(n) = F^2(\frac{n}{2} \pm 1) + F^2(\frac{n}{2})$$
- **same:** $$F(2n \pm 1) = F^2(n \pm 1) + F^2(n)$$
(Proof in above link)
