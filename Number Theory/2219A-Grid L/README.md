***Observation 1: The Total Segment***

A grid of dimensions $n \times m$ consists of:

* $(n + 1)$ horizontal rows, each having $m$ unit segments.
* $(m + 1)$ vertical columns, each having $n$ unit segments.

The total number of unit segments $T$ is:

$$T = m(n + 1) + n(m + 1) = 2nm + n + m$$

Since we have $p$ single segments and $q$ L-shapes (2 units each), our total available length is $p + 2q$. Our first equation is:

$$2nm + n + m = p + 2q$$

***Observation 2: Simon's Favorite Factoring Trick***

The equation $2nm + n + m = K$ is hard to solve for $n$ and $m$ directly. We apply a symmetry transformation:

1. Multiply both sides by 2: $4nm + 2n + 2m = 2(p + 2q)$
2. Add 1 to both sides: $4nm + 2n + 2m + 1 = 2p + 4q + 1$
3. Factor the left side: $(2n + 1)(2m + 1) = 2p + 4q + 1$

Let $K = 2p + 4q + 1$. We are looking for two odd factors $X$ and $Y$ of $K$ such that $X \cdot Y = K$. Since $n, m \geq 1$, we must have $X, Y \geq 3$.

***Observation 3: The L-Shape Invariant***

Every L-shape, no matter how it is rotated, **must** consist of exactly **one horizontal unit segment** and **one vertical unit segment**.

This means that to use $q$ L-shapes, we need at least $q$ horizontal slots and $q$ vertical slots in our grid.

* Let $H = m(n + 1)$ be total horizontal slots.
* Let $V = n(m + 1)$ be total vertical slots.

The remaining $p$ straight segments must fill the remaining slots: $p = (H - q) + (V - q)$.

For this to be valid, the "imbalance" between $H$ and $V$ cannot exceed our $p$ segments.

$$|H - V| \leq p$$




Substituting $H$ and $V$:

$$|m(n + 1) - n(m + 1)| \leq p \implies |m - n| \leq p$$

In terms of our factors $X$ and $Y$:

$$\left| \frac{X - 1}{2} - \frac{Y - 1}{2} \right| \leq p \implies |\mathbf{X} - \mathbf{Y}| \leq \mathbf{2p}$$

**The Algorithm**

1. Calculate $K = 2p + 4q + 1$.
2. Iterate through factors of $K$ to find a pair $(X, Y)$ such that $X \cdot Y = K$ and $X, Y \geq 3$.
   * *Note:* Start searching from $\sqrt{K}$ downwards to find factors closest to each other, as this minimizes $|X - Y|$.
3. Check if $|X - Y| \leq 2p$.
4. If true, $n = (X - 1)/2$ and $m = (Y - 1)/2$. Otherwise, no solution exists for those factors.

**Complexity:** $O(\sqrt{p + q})$ per test case, which easily passes for $10^8$.
