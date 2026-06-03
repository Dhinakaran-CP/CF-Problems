### 1. Problem Statement

Given two positive integers $n$ and $x$, we want to count the number of triplets of positive integers $(a,b,c)$ that satisfy the following system of inequalities:
$$(ab+bc+ca) \le n$$
$$a+b+c \le x$$

---

### 2. Mathematical Derivation



From the first identity,
$$(ab+bc+ca) \le n \implies ab+c(a+b) \le n$$

$$ab + c(a+b) \le n$$
$$c(a+b) \le n-ab$$
$$ c \le (n-ab)/(a+b)$$

From the second identity,
$$a+b+c \le x$$,
$$c \le x-a-b$$

---

### 3. Algorithm

To avoid a naive $O(x^3)$ or $O(x^2)$ search space, we can fix two variables ($a$ and $b$) and compute the allowable range for the third variable $c$ in $O(1)$ time.

Since $a$, $b$, and $c$ must be positive integers, we have $c \ge 1$. For a fixed pair $(a, b)$, the variable $c$ is bounded by two upper limits:
1. **From the sum constraint:**  
   $$c \le x - a - b$$
2. **From the product constraint:**  
   $$c(a+b) \le n - ab \implies c \le \left\lfloor \frac{n - ab}{a+b} \right\rfloor$$

Thus, the number of valid positive integers for $c$ associated with a fixed pair $(a, b)$ is given by:
$$\text{count}(c) = \max\left(0, \min\left(x - a - b, \left\lfloor \frac{n - ab}{a+b} \right\rfloor\right)\right)$$

---

### 4. Complexity Analysis

While a nested loop over $a$ and $b$ might appear to require $O(n^2)$ iterations, the constraint $ab + bc + ca \le n$ limits the state space. Because $a, b, c \ge 1$, we must have:
$$ab < n$$

The total number of iterations required to evaluate all valid pairs $(a, b)$ is bounded by the Harmonic Series:
$$\sum_{a=1}^{n} \sum_{b=1}^{\lfloor n/a \rfloor} 1 = \sum_{a=1}^{n} \left\lfloor \frac{n}{a} \right\rfloor \approx n \left(1 + \frac{1}{2} + \dots + \frac{1}{n}\right) \approx n \ln n$$

This guarantees a highly efficient time complexity of $\mathcal{O}(n \log n)$, which easily executes within typical time limits for inputs up to $n, x = 10^5$.
