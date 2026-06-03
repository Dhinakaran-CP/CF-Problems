### Mathematical Formulation

The expected value $E$ is defined as the sum of all possible outcomes divided by the total number of outcomes.

**Total Outcomes:** The number of ways to choose $2$ distinct indices from $n$ elements is given by the combination:
$$\binom{n}{2} = \frac{n(n-1)}{2}$$

**Sum of Outcomes:** We need to find the sum of products of all unique pairs $(a_i, a_j)$:
$$S = \sum_{1 \le i < j \le n} a_i \cdot a_j$$

The expected value is therefore:
$$E = \frac{S}{\binom{n}{2}}$$

### Algebraic Optimization

Calculating $S$ with a nested loop takes $O(n^2)$ time, which is too slow for $n = 2 \cdot 10^5$. To optimize this, we use the symmetric sum identity:
$$\left( \sum_{i=1}^{n} a_i \right)^2 = \sum_{i=1}^{n} a_i^2 + 2 \sum_{1 \le i < j \le n} a_i a_j$$

Rearranging this expression for our target sum $S$ yields:
$$2S = \left( \sum_{i=1}^{n} a_i \right)^2 - \sum_{i=1}^{n} a_i^2$$

### Final Derivation

Substituting the expression for $S$ into our expected value formula:
$$E = \frac{\frac{\left( \sum_{i=1}^{n} a_i \right)^2 - \sum_{i=1}^{n} a_i^2}{2}}{\frac{n(n-1)}{2}}$$

The factor of $2$ in the denominators cancels out, leaving us with the simplified formula:
$$E = \frac{\left( \sum_{i=1}^{n} a_i \right)^2 - \sum_{i=1}^{n} a_i^2}{n(n-1)}$$

### Implementation Details (Modular Arithmetic)

Since we need the answer modulo $M = 10^9 + 7$, we perform the operations as follows:

$$\text{Sum} \equiv \left( \sum_{i=1}^{n} a_i \right) \pmod{M}$$

$$\text{SumSq} \equiv \left( \sum_{i=1}^{n} a_i^2 \right) \pmod{M}$$

$$P \equiv \left( \text{Sum}^2 - \text{SumSq} + M \right) \pmod{M}$$

$$Q \equiv \left( n \cdot (n - 1) \right) \pmod{M}$$

To perform division under modular arithmetic, we compute the modular multiplicative inverse of the denominator using Fermat's Little Theorem:
$$Q^{-1} \equiv Q^{M-2} \pmod{M}$$

The final expected value is then calculated as:
$$E \equiv P \cdot Q^{-1} \pmod{M}$$
