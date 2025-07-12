# 🧮 Smallest Number with N Divisors

---

## 📝 Problem Statement

> Given a positive integer `N`, find the **smallest positive integer** that has exactly `N` positive divisors (including 1 and itself).

---

## 🧠 Key Insight

If a number `X` has the prime factorization:

$X = p_1^{e_1} \times p_2^{e_2} \times \dots \times p_k^{e_k}$

Then the number of positive divisors of `X` are:

$D(X) = (e_1 + 1) \times (e_2 +1) \times \dots \times (e_k + 1)$

Why do we add + 1?

To consider a case where power of prime `p_i` is `0`


So we want to:

> Find the smallest `X` such that the product of `(ei + 1)` over all prime exponents `ei` equals `N`.

---

## 🔍 Approach

### ✅ Step-by-Step Plan

1. **Factorize `N`** as a product of integers ≥ 2 → these will become `(ei + 1)` in solution these factors are `[x1 ,x2 ,x3 ....]`
2. Subtract 1 from each factor → this gives us the exponent list `e1, e2, ...`
3. **Sort exponents in descending order**
4. Assign **smallest primes to largest exponents** (greedy strategy)
5. Construct the number:  
   `X = p₁^e₁ × p₂^e₂ × ...`  
   Track the minimum such value

### 🛡️ Optimization

- Use **backtracking** to explore all factorizations of `N`
- Prune branches where the candidate number grows beyond current minimum
- Guard against **overflow** during multiplication

---

## 💻 Code Link

👉 [C++ Implementation](../problems/smallest-number-with-n-divisors.cpp)

---

## 🔁 Example

**Input:** `N = 9`  
**Output:** `36`

**Explanation:**

- Factor 9 as: `3 × 3 → exponents = 2, 2`
- Assign primes: `2^2 × 3^2 = 36`
- 36 has exactly 9 divisors, and it's the smallest such number.

---

## ⏱️ Time & Space Complexity

| Complexity | Description |
|------------|-------------|
| 🕒 Time     | Depends on number of ways to factorize `N` (generally small for `N ≤ 1000`) |
| 🧠 Space    | O(depth of recursion) + O(number of primes used) |

---

## ✅ Edge Cases

- `N = 1` → Output: `1` (Only `1` has 1 divisor)
- Large `N` like `1024` → Ensure no multiplication overflow
- Don’t assign large exponents to large primes (use greedy logic!)

---

## 📌 Takeaways

- Deep use of **number theory** and **prime exponent patterns**
- Good blend of **combinatorics**, **greedy**, and **backtracking**
- A strong example of how **math powers up algorithm design**

---

**Author:** Ronak Ganesh Sawant  
📌 BTech CSE @ VIT Vellore  
📧 ronsawant1@gmail.com






