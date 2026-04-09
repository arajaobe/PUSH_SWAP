*This project has been created as part of the 42 curriculum by arajaobe, samrazaf.*

# push_swap

## Description

push_swap is a sorting algorithm project from the 42 School curriculum. Given a list of integers passed as command-line arguments, the program must sort them in ascending order using exactly two stacks (`a` and `b`) and a restricted set of eleven operations, while minimizing the total number of operations used.

The core challenge is not just sorting, but sorting *efficiently*. A naive approach will sort correctly but use too many operations to pass the performance thresholds. The project therefore requires implementing multiple algorithms of different complexity classes and selecting the most appropriate one based on how disordered the input is — a value computed before any sorting begins.

Stack `a` starts filled with the input numbers. Stack `b` starts empty. At the end, all numbers must be in stack `a` in ascending order, with stack `b` empty.

---

## Instructions

### Compilation

```bash
make          # build the push_swap binary
make clean    # remove object files
make fclean   # remove object files and binary
make re       # full rebuild from scratch
```

### Execution

```bash
# basic usage
./push_swap 5 3 1 4 2

# quoted arguments (also valid)
./push_swap "5 3 1 4 2"

# check correctness using the provided checker
./push_swap 5 3 1 4 2 | ./checker 5 3 1 4 2

# run with benchmark output (printed to stderr)
./push_swap 5 3 1 4 2 --bench
```

The `--bench` flag must be placed after the numbers. Benchmark output goes to stderr and never interferes with the checker reading stdout.

### Requirements

- `cc` compiler with `-Wall -Wextra -Werror`
- The `ft_printf` folder must be present in the project root

---

## Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top two elements of stack a |
| `sb` | Swap the top two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of stack b to top of stack a |
| `pb` | Push top of stack a to top of stack b |
| `ra` | Rotate stack a upward (top goes to bottom) |
| `rb` | Rotate stack b upward (top goes to bottom) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (bottom goes to top) |
| `rrb` | Reverse rotate stack b (bottom goes to top) |
| `rrr` | `rra` and `rrb` simultaneously |

Each operation is applied to the linked list and its name is printed to stdout.

---

## Algorithm Explanation & Justification

### Disorder Metric

Before sorting, the program computes a **disorder value** between `0.0` and `1.0` measuring how unsorted the input is. It counts **inversions** — pairs where a larger number appears before a smaller one:

```
disorder = mistakes / total_pairs

where:
  total_pairs = n * (n - 1) / 2
  mistakes    = number of pairs (i, j) where i < j but a[i] > a[j]
```

- `0.0` means already sorted
- `1.0` means fully reversed
- Anything in between reflects partial disorder

This metric drives the adaptive strategy: instead of always using the heaviest algorithm, we match the cost of the algorithm to the actual difficulty of the input.

---

### Adaptive Strategy

| Disorder | Strategy | Complexity |
|----------|----------|------------|
| `= 0` | Already sorted, exit immediately | O(1) |
| `< 0.2` | Simple sort | O(n²) |
| `0.2 – 0.5` | Medium sort (chunk-based) | O(n√n) |
| `≥ 0.5` | Complex sort (radix sort) | O(n log n) |

**Justification for thresholds:**
- Below `0.2`, the stack has very few inversions. An O(n²) algorithm's worst case never materializes because so few elements are out of place — in practice it runs in near-linear time.
- Between `0.2` and `0.5`, the disorder is moderate. Chunk-based sorting reduces the number of full scans needed, making O(n√n) the right balance between simplicity and efficiency.
- At `0.5` and above, the input is significantly shuffled. Only an O(n log n) algorithm can reliably stay within the operation count thresholds for 500 numbers.

---

### Simple Sort — O(n²)

**How it works:**
Repeatedly finds the element closest to the top or bottom of stack a (either the minimum or maximum, whichever requires fewer rotations) and pushes it to stack b. Everything is then pushed back from b to a.

**Justification:**
For nearly sorted inputs (disorder < 0.2), the number of rotations needed per element is very small. The theoretical O(n²) bound is loose — in practice the operation count is close to O(n). This makes it the most efficient choice for low-disorder inputs.

---

### Medium Sort — O(n√n)

**How it works:**
The sorted range is divided into chunks of size √n. For each chunk, stack a is scanned and any element belonging to the current chunk is rotated to the top and pushed to stack b. After all chunks are processed, everything is pushed back from b to a in order using `push_findmax`.

**Justification:**
Chunk partitioning avoids the repeated full scans that make simple sort expensive on larger disordered inputs. With √n chunks of size √n, the total number of operations is bounded by O(n√n). This is a natural fit for two-stack sorting since stack b acts as the intermediate partition buffer.

---

### Complex Sort — O(n log n)

**How it works:**
Implements **LSD radix sort** adapted for two stacks. Before sorting, each element is assigned an index (rank) based on its position in the fully sorted order. The algorithm then performs one pass per bit, from least significant to most significant:

- If the current bit of the element on top of a is `0` → push to b (`pb`)
- If the current bit is `1` → rotate a (`ra`)
- After each bit pass → push all of b back to a (`pa`)

**Justification:**
Radix sort runs in O(n × bits) where bits = log₂(n). For 500 elements, this is approximately O(500 × 9) = O(4500) operations — well within the 5500 excellent threshold. Unlike comparison-based sorts, radix sort's performance does not degrade with disorder, making it the correct choice for highly shuffled inputs.

---

### Small Input Handling

For inputs of 2 or 3 elements, all possible arrangements are hardcoded directly. For 4 or 5 elements, a dedicated short sort function handles them without invoking the full adaptive pipeline. This avoids the overhead of computing disorder and allocating memory for very small inputs.

---

## Performance

Targets from the subject:

| Numbers | Pass | Good | Excellent |
|---------|------|------|-----------|
| 100 | < 2000 | < 1500 | < 700 |
| 500 | < 12000 | < 8000 | < 5500 |

### Benchmark output

Run with `--bench` after the arguments to see a performance report on stderr:

```
[bench] disorder:   49.93%
[bench] strategy:   Adaptive / O(n√n)
[bench] total_ops:  7997
[bench] sa: 0   sb: 0   ss: 0   pa: 500  pb: 500
[bench] ra: 4840  rb: 1098  rr: 0  rra: 0  rrb: 1059  rrr: 0
```

---

## Error Handling

The program prints `Error` to stderr and exits on:

- Non-integer arguments (`abc`, `1.5`, `@!`)
- Integers outside the range of `INT_MIN` / `INT_MAX`
- Duplicate values
- Sign-only arguments (`-`, `+`)
- Double signs (`++`, `--`, `+-`)
- Empty arguments (`""`, `" "`)
- Flags only

Space-separated numbers inside a single quoted argument are valid:
```bash
./push_swap "3 1 2"   # same as: ./push_swap 3 1 2
```

---


## Bonus

The bonus implements a **checker** program that verifies whether a sequence of operations correctly sorts a stack.

### How it works

```bash
./push_swap 3 1 2 | ./checker 3 1 2
OK   # or KO
```

The checker:
1. Takes the same arguments as `push_swap` (the numbers to sort)
2. Reads operations from stdin line by line (using `get_next_line`)
3. Applies each operation to the stacks
4. Prints `OK` if stack a is sorted and stack b is empty, `KO` otherwise
5. Prints `Error` to stderr for invalid arguments or unrecognized operations

### Compile the bonus

```bash
make bonus    # builds the checker binary
```

### Error cases

The checker prints `Error` to stderr on:
- Non-integer arguments
- Integers outside `INT_MIN` / `INT_MAX`
- Duplicate values
- Unrecognized or malformed operations

---


## Contributions

| | arajaobe | samrazaf |
|---|---|---|
| Simple sort (O(n²)) | ✅ | |
| Medium sort (O(n√n)) | ✅ | |
| All operations (sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr) | ✅ | |
| Benchmark print (`--bench`) | ✅ | |
| Makefile | ✅ | |
| ft_printf | ✅ | |
| Complex sort (O(n log n) radix) | | ✅ |
| Adaptive strategy selector | | ✅ |
| Error management | | ✅ |
| Flags (`--simple`, `--medium`, `--complex`) | | ✅ |
| Bonus | | ✅ |
| Argument parsing | ✅ | ✅ |
| Readme | ✅ | ✅ |

---

## Resources

### References

- **Radix Sort** — https://en.wikipedia.org/wiki/Radix_sort
- **Insertion Sort** — https://en.wikipedia.org/wiki/Insertion_sort
- **Inversion Count / Disorder** — https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
- **push_swap visualizer** — https://sorts.roiu.eu/
- **push_swap visualizer (alternate)** — https://visualizer.phreaks.fr/
- **push_swap overview (community)** — https://medium.com/@ayogun/push-swap-c1f5d2d41e97

### AI Usage

- **Conceptual understanding** — explaining how operations map to linked list manipulation, and how classic sorting algorithms translate into the two-stack model
- **Debugging support** — helping trace edge cases in argument parsing (quoted arguments, lone signs, out-of-range integers)
- **README drafting** — this README was written with AI assistance based on the actual project implementation

All code was written, understood, and validated by arajaobe and samrazaf.
