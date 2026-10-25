# Competitive Programming Solutions

A personal archive of C++ solutions written while preparing for and taking part in algorithm
contests, between **September 2025 and October 2026**. Every file is the version that was
accepted at the time, kept as a single self-contained translation unit, compiled with
`g++ -std=c++17 -O2`.

Most tasks come from [Luogu](https://www.luogu.com.cn/), a Chinese competitive programming
judge. The rest are course exercises, local contest tasks and a few scratch programs used to
check the toolchain.

## Layout

```
AlgorithmCodes/
├── luogu/           solutions filed under their judge problem ID
├── greedy/          greedy and constructive tasks
├── number-theory/   congruences, divisors, combinatorics
├── graph/           connectivity, minimum spanning tree
├── data-structure/  monotone queue, square-root decomposition, prefix sums
├── binary-search/   binary / ternary search on the answer
├── dp/              dynamic programming
├── search/          DFS and exhaustive enumeration
├── misc/            contest leftovers and scratch files
├── README.md
└── .gitignore
```

## Solutions

Ordered by the date each file was last written.

| Written | File | Problem | Techniques |
| --- | --- | --- | --- |
| 2025-09-06 | [`number-theory/exgcd_congruence.cpp`](number-theory/exgcd_congruence.cpp) | Extended Euclid task | Extended Euclidean algorithm, linear congruence |
| 2025-09-13 | [`number-theory/divisor_sum_mod.cpp`](number-theory/divisor_sum_mod.cpp) | Sum-of-divisors task | Fast exponentiation, divisor enumeration with modular inverse |
| 2025-09-13 | [`number-theory/linear_congruence_system.cpp`](number-theory/linear_congruence_system.cpp) | Linear congruence system | gcd, incremental CRT-style merging |
| 2025-09-28 | [`greedy/interval_cover_sprinkler.cpp`](greedy/interval_cover_sprinkler.cpp) | Course set 1.1.3 | Greedy - interval covering after a geometric transform |
| 2025-09-28 | [`greedy/interval_point_cover.cpp`](greedy/interval_point_cover.cpp) | Course set 1.1.2 | Greedy - interval point covering |
| 2025-09-28 | [`greedy/interval_scheduling.cpp`](greedy/interval_scheduling.cpp) | Course set 1.1.1 | Greedy - interval scheduling by right endpoint |
| 2025-10-02 | [`graph/mst_boruvka.cpp`](graph/mst_boruvka.cpp) | Graph construction task | Minimum spanning tree (Boruvka), disjoint-set union |
| 2025-10-02 | [`misc/interval_merge_simulation.cpp`](misc/interval_merge_simulation.cpp) | Local contest task | Simulation, interval merging |
| 2025-10-05 | [`graph/dynamic_graph_queries.cpp`](graph/dynamic_graph_queries.cpp) | Dynamic graph queries | Breadth-first search over an adjacency matrix |
| 2025-10-05 | [`luogu/P3760.cpp`](luogu/P3760.cpp) | [`P3760`](https://www.luogu.com.cn/problem/P3760) | Binary trie, XOR aggregation |
| 2025-10-06 | [`binary-search/binary_search_on_answer.cpp`](binary-search/binary_search_on_answer.cpp) | Binary search task | Binary search on the answer, difference arrays |
| 2025-10-06 | [`dp/complete_binary_tree_lis.cpp`](dp/complete_binary_tree_lis.cpp) | Complete binary tree task | DFS post-order traversal, LIS via patience sorting |
| 2025-10-06 | [`greedy/permutation_sum_construction.cpp`](greedy/permutation_sum_construction.cpp) | Constructive task | Greedy construction, permutation bounds |
| 2025-10-18 | [`luogu/P7960.cpp`](luogu/P7960.cpp) | [`P7960`](https://www.luogu.com.cn/problem/P7960) | Linear sieve |
| 2025-10-20 | [`luogu/P14253.cpp`](luogu/P14253.cpp) | [`P14253`](https://www.luogu.com.cn/problem/P14253) | Hash grouping (unordered_map) |
| 2025-10-20 | [`luogu/P1478.cpp`](luogu/P1478.cpp) | [`P1478`](https://www.luogu.com.cn/problem/P1478) | Sudoku solver - bitmask state, DFS |
| 2025-10-25 | [`data-structure/permutation_prefix_count.cpp`](data-structure/permutation_prefix_count.cpp) | Permutation task | Prefix sums, sorting statistics |
| 2025-10-25 | [`greedy/bin_packing.cpp`](greedy/bin_packing.cpp) | Class exercise | Greedy bin packing |
| 2025-10-25 | [`greedy/sort_construct_minmax.cpp`](greedy/sort_construct_minmax.cpp) | Class exercise | Sorting, constructive minimum/maximum |
| 2025-10-25 | [`misc/string_bucket_roundrobin.cpp`](misc/string_bucket_roundrobin.cpp) | String distribution task | Bucket by first character, cyclic polling |
| 2025-10-26 | [`luogu/P7913.cpp`](luogu/P7913.cpp) | [`P7913`](https://www.luogu.com.cn/problem/P7913) | Greedy allocation with a priority queue |
| 2025-10-26 | [`luogu/P7915.cpp`](luogu/P7915.cpp) | [`P7915`](https://www.luogu.com.cn/problem/P7915) | Deque-based palindrome check |
| 2025-10-31 | [`luogu/P2016.cpp`](luogu/P2016.cpp) | [`P2016`](https://www.luogu.com.cn/problem/P2016) | Tree DP over two states |
| 2025-11-01 | [`luogu/P1036.cpp`](luogu/P1036.cpp) | [`P1036`](https://www.luogu.com.cn/problem/P1036) | Combination enumeration with primality test |
| 2025-11-01 | [`luogu/P3713.cpp`](luogu/P3713.cpp) | [`P3713`](https://www.luogu.com.cn/problem/P3713) | Prefix sums |
| 2025-11-15 | [`number-theory/combinations_factorials.cpp`](number-theory/combinations_factorials.cpp) | Combinatorics task | Factorials, inverse factorials, modular inverses |
| 2025-11-16 | [`luogu/P8865.cpp`](luogu/P8865.cpp) | [`P8865`](https://www.luogu.com.cn/problem/P8865) | 2D prefix sums |
| 2025-11-16 | [`luogu/P8868.cpp`](luogu/P8868.cpp) | [`P8868`](https://www.luogu.com.cn/problem/P8868) | Offline queries, Fenwick tree |
| 2025-11-18 | [`misc/scratch_compile_test.cpp`](misc/scratch_compile_test.cpp) | Scratch file | Compiler and template sanity check |
| 2025-11-23 | [`luogu/P9868.cpp`](luogu/P9868.cpp) | [`P9868`](https://www.luogu.com.cn/problem/P9868) | Disjoint-set union with coordinate compression |
| 2025-11-23 | [`luogu/T436395.cpp`](luogu/T436395.cpp) | Luogu team problem T436395 | Array counting with modular arithmetic |
| 2025-11-27 | [`luogu/P11361.cpp`](luogu/P11361.cpp) | [`P11361`](https://www.luogu.com.cn/problem/P11361) | Binary string processing, index bookkeeping |
| 2025-11-28 | [`binary-search/ternary_search.cpp`](binary-search/ternary_search.cpp) | Convex function minimum | Ternary search |
| 2025-11-28 | [`data-structure/monotone_queue.cpp`](data-structure/monotone_queue.cpp) | Sliding window extrema | Monotone queue |
| 2025-11-28 | [`data-structure/sqrt_decomposition.cpp`](data-structure/sqrt_decomposition.cpp) | Range add / range sum | Square-root decomposition |
| 2025-12-11 | [`luogu/P1212.cpp`](luogu/P1212.cpp) | [`P1212`](https://www.luogu.com.cn/problem/P1212) | Search with deduplication (std::set) and pruning |
| 2025-12-13 | [`luogu/P11839.cpp`](luogu/P11839.cpp) | [`P11839`](https://www.luogu.com.cn/problem/P11839) | Sorting, merge-style DSU bookkeeping |
| 2025-12-13 | [`luogu/P11840.cpp`](luogu/P11840.cpp) | [`P11840`](https://www.luogu.com.cn/problem/P11840) | Breadth-first search on a tree |
| 2025-12-16 | [`luogu/P10135.cpp`](luogu/P10135.cpp) | [`P10135`](https://www.luogu.com.cn/problem/P10135) | Tree traversal with adjacency lists |
| 2025-12-25 | [`misc/scratch_win32_window.cpp`](misc/scratch_win32_window.cpp) | Scratch file | Minimal Win32 window program (toolchain check) |
| 2026-02-11 | [`misc/recurrence_mod.cpp`](misc/recurrence_mod.cpp) | Contest series AME | Linear recurrence with modular reduction |
| 2026-02-11 | [`search/dfs_binary_state.cpp`](search/dfs_binary_state.cpp) | Contest series AME | DFS over a binary-tree-shaped state space |
| 2026-02-12 | [`search/dfs_seven_elements.cpp`](search/dfs_seven_elements.cpp) | Contest series AME | Exhaustive DFS over 7-element states |
| 2026-10-09 | [`luogu/P2668.cpp`](luogu/P2668.cpp) | [`P2668`](https://www.luogu.com.cn/problem/P2668) | DFS with greedy enumeration of card groups |
| 2026-10-09 | [`luogu/P3619.cpp`](luogu/P3619.cpp) | [`P3619`](https://www.luogu.com.cn/problem/P3619) | Greedy ordering with thresholds |
| 2026-10-09 | [`luogu/P5017.cpp`](luogu/P5017.cpp) | [`P5017`](https://www.luogu.com.cn/problem/P5017) | Multi-dimensional dynamic programming |

## Notes

- Files are named after the technique they demonstrate. The original working names were kept
  for traceability and are listed at the end of this file.
- Compiled binaries (`.exe`, `.out`) are excluded via `.gitignore`; only source is tracked.
- These are not editorial-quality solutions. Some are brute force, some are hybrids that were
  written to fit the time limit, and none of them were rewritten afterwards.

## File name mapping

| Original working name | Current name |
| --- | --- |
| `bamboo.cpp` | [`binary-search/binary_search_on_answer.cpp`](binary-search/binary_search_on_answer.cpp) |
| `sanfeng.cpp` | [`binary-search/ternary_search.cpp`](binary-search/ternary_search.cpp) |
| `queue.cpp` | [`data-structure/monotone_queue.cpp`](data-structure/monotone_queue.cpp) |
| `reverse.cpp` | [`data-structure/permutation_prefix_count.cpp`](data-structure/permutation_prefix_count.cpp) |
| `treee.cpp` | [`data-structure/sqrt_decomposition.cpp`](data-structure/sqrt_decomposition.cpp) |
| `tree.cpp` | [`dp/complete_binary_tree_lis.cpp`](dp/complete_binary_tree_lis.cpp) |
| `architect.cpp` | [`graph/dynamic_graph_queries.cpp`](graph/dynamic_graph_queries.cpp) |
| `COVER.CPP` | [`graph/mst_boruvka.cpp`](graph/mst_boruvka.cpp) |
| `tx2.cpp` | [`greedy/bin_packing.cpp`](greedy/bin_packing.cpp) |
| `1.1.3.cpp` | [`greedy/interval_cover_sprinkler.cpp`](greedy/interval_cover_sprinkler.cpp) |
| `1.1.2.cpp` | [`greedy/interval_point_cover.cpp`](greedy/interval_point_cover.cpp) |
| `1.1.1.cpp` | [`greedy/interval_scheduling.cpp`](greedy/interval_scheduling.cpp) |
| `race.cpp` | [`greedy/permutation_sum_construction.cpp`](greedy/permutation_sum_construction.cpp) |
| `tx1.cpp` | [`greedy/sort_construct_minmax.cpp`](greedy/sort_construct_minmax.cpp) |
| `stair.cpp` | [`misc/interval_merge_simulation.cpp`](misc/interval_merge_simulation.cpp) |
| `AME5.cpp` | [`misc/recurrence_mod.cpp`](misc/recurrence_mod.cpp) |
| `test.cpp` | [`misc/scratch_compile_test.cpp`](misc/scratch_compile_test.cpp) |
| `test2.cpp` | [`misc/scratch_win32_window.cpp`](misc/scratch_win32_window.cpp) |
| `zigzag.cpp` | [`misc/string_bucket_roundrobin.cpp`](misc/string_bucket_roundrobin.cpp) |
| `home.cpp` | [`number-theory/combinations_factorials.cpp`](number-theory/combinations_factorials.cpp) |
| `3.cpp` | [`number-theory/divisor_sum_mod.cpp`](number-theory/divisor_sum_mod.cpp) |
| `1.cpp` | [`number-theory/exgcd_congruence.cpp`](number-theory/exgcd_congruence.cpp) |
| `4.cpp` | [`number-theory/linear_congruence_system.cpp`](number-theory/linear_congruence_system.cpp) |
| `AME10.cpp` | [`search/dfs_binary_state.cpp`](search/dfs_binary_state.cpp) |
| `AME15.cpp` | [`search/dfs_seven_elements.cpp`](search/dfs_seven_elements.cpp) |
