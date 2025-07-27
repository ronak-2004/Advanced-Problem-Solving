# 🍫 Chocolate Party – Problem Explanation

## ✅ Problem Statement

Abhi has `N` chocolate bags, each containing `arr[i]` chocolates. He wants to distribute all of them equally among `K` friends, **without making anyone angry**. Each friend must get **the same total number of chocolates**, and **all bags must be used**.

Your task is to determine whether such a distribution is possible for multiple test cases.

---

## 🧾 Input Format

* First line: Integer `T` – number of test cases  
* For each test case:
  * Line 1: Two integers `N` and `K` – number of chocolate bags and number of friends  
  * Line 2: `N` integers – the array `arr[]`, where `arr[i]` is the number of chocolates in the `i-th` bag

---

## 🖨️ Output Format

* For each test case, print `"Yes"` if it's possible to distribute chocolates equally among all `K` friends, otherwise print `"No"`.

---

## 📌 Constraints

* `1 ≤ T ≤ 10^4`  
* `1 ≤ K ≤ N ≤ 20`  
* `0 ≤ arr[i] ≤ 10^3`

---

## 💡 Approach

### Key Observations

1. **Total Chocolates:** If the sum of all chocolates `sum` is not divisible by `K`, it's **impossible** to divide them equally → output `"No"`.

2. **Subset Partitioning:** We need to partition the chocolate bags into `K` groups where **each group sums to `target = sum / K`**.

3. **Backtracking (DFS):** This is a classic **K-partition problem**, solvable with DFS + backtracking due to small size constraints (`N ≤ 20`).

4. The DFS works by finding a path then starting all over again from index 0, while it rejects the elements that have been visited in previous subsets. If multiple paths are present, it selects the ones that eventually give exactly `K` valid subsets.

---

## 🔁 Algorithm (DFS + Backtracking)

### Step-by-Step:

1. Calculate total sum of chocolates.  
2. If `sum % K != 0` → return `"No"` (early exit).  
3. Use recursive DFS to try to form `K` subsets of chocolates that each sum to `target`.  
4. Use a `visited[]` array to mark chocolate bags that are already assigned to a subset.  
5. For each subset:
   - Try to build a subset starting from index 0
   - Skip used or oversized values
   - Backtrack if dead-end

---

## 🧠 Time Complexity

* Worst-case exponential due to backtracking: `O(K * 2^N)`  
* Efficient in practice because `N` is small (`≤ 20`) and pruning with backtracking helps.

---

## ✅ Sample Input

```
4
5 3
1 2 2 3 4
4 3
1 2 3 4
18 3
921 928 66 489 203 46 65 452 488 62 490 492 289 831 862 99 107 493
13 4
980 566 741 427 918 43 767 208 56 81 60 221
```

---


## ✅ Sample Output

```
Yes
No
Yes
No
```
---

## 🎯 Conclusion

This problem is a real-world variation of the "Partition to K Equal Sum Subsets" and is ideal for practicing:

1. DFS + backtracking

2. Subset-sum partitioning

3. Pruning and base case design

