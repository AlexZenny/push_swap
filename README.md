*This project has been created as part of the 42 curriculum by azieniuk, tmalyshi.*

# push_swap

## Descrition
push_swap is a sorting project built around two stacks, A and B, and a restricted set of stack operations.

The goal is to sort the integers in stack A in ascending order, with the smallest value at the top, while producing a valid sequence of push_swap instructions.

The project focuses on algorithm design and complexity, linked-list and stack manipulation, input parsing and validation, benchmarking, and runtime strategy selection.

Stack A initially contains the input integers and stack B starts empty.

### Allowed operations

| Operation | Description |
| --- | --- |
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | Perform `sa` and `sb` simultaneously |
| `pa` | Push the top element of stack B onto stack A |
| `pb` | Push the top element of stack A onto stack B |
| `ra` | Rotate stack A upward |
| `rb` | Rotate stack B upward |
| `rr` | Perform `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | Perform `rra` and `rrb` simultaneously |

### Features

The program supports four strategies:

- `--simple` — forces the O(n²) strategy.

- `--medium` — forces the O(n√n) strategy.

- `--complex` — forces the O(n log n) strategy.

- `--adaptive` — selects a strategy according to the input disorder.

If no strategy selector is provided, adaptive mode is used.

`--bench` enables benchmark output on `stderr` while normal stack operations remain on `stdout`.

## Instructions
### Compilation
Compile the program with:

```bash
make
```

Useful Makefile rules:

```bash
- `make clean` removes object files.
- `make fclean` removes object files and the compiled program.
- `make re` rebuilds the project from scratch.
```

The executable is:

`./push_swap`

### Execution 

./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
./push_swap --simple 4 67 3 87 23
./push_swap --medium 4 67 3 87 23
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
./push_swap --bench 4 67 3 87 23
./push_swap --complex --bench 4 67 3 87 23

Only one strategy selector may be supplied.

If no arguments are supplied:

./push_swap

the program must print nothing and exit.

### Count operations

./push_swap 4 67 3 87 23 | wc -l

### Input Validation

The program prints `Error` followed by a newline to stderr for invalid input.

Validation should cover:

- non-numeric values;

- malformed signs;

- integer overflow/underflow;

- duplicate integers;

- duplicate flags;

- invalid flags;

- multiple strategy selectors;

- empty or otherwise invalid numeric arguments.

### Project strtucture

```text
push_swap/
├── push_swap.c
├── init_structs.c
├── benchmark.c
├── general_utils.c
├── general_utils_2.c
├── split.c
│
├── parser/
│   ├── parser_utils.c
│   ├── split_arg.c
│   └── stack_funcs.c
│
├── operations/
│   ├── push_ops.c
│   ├── swap_ops.c
│   ├── rotate_ops.c
│   └── rev_rotate_ops.c
│
├── algorithms/
│   ├── disorder.c
│   ├── sorting_selector.c
│   ├── tiny_sorting.c
│   ├── simple_sorting.c
│   ├── medium_sorting.c
│   ├── medium_sorting_utils.c
│   └── complex_sorting.c
│
├── ft_printf/
│   ├── ft_printf.c
│   └── ft_extras.c
│
└── Makefile
```
- `push_swap.c` — program entry point and main execution flow.
- `init.c` — initialization of program data and options.
- `benchmark.c` — benchmark statistics and output.
- `general_utils*.c` — shared utility functions.
- `split.c` — string splitting utilities.

- `parser/`
  - input validation and argument parsing
  - conversion of arguments into stack data
  - stack creation helpers

- `operations/`
  - implementation of the allowed push_swap operations:
    `pa`, `pb`, `sa`, `sb`, `ss`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`

- `algorithms/`
  - `disorder.c` — disorder/inversion calculation
  - `sorting_selector.c` — strategy selection
  - `tiny_sorting.c` — small-stack sorting
  - `simple_sorting.c` — O(n²) strategy
  - `medium_sorting.c` — O(n√n) strategy
  - `complex_sorting.c` — O(n log n) strategy

- `ft_printf/`
  - custom formatted output implementation

### Data structures inside the project

#### `t_list`

Represents one node in a stack.

- `value` — original integer value provided by the user.
- `rank` — normalized position of the value after ranking, used by sorting algorithms such as radix sort.
- `next` — pointer to the next node in the circular doubly linked list.
- `prev` — pointer to the previous node in the circular doubly linked list.

#### `t_mode`

Enum representing the available sorting strategies.

- `SIMPLE` — O(n²) strategy.
- `MEDIUM` — O(n√n) strategy.
- `COMPLEX` — O(n log n) strategy.
- `ADAPTIVE` — automatically selects a strategy based on the disorder of the input.

#### `t_options`

Stores command-line options selected by the user.

- `mode` — selected sorting mode.
- `mode_status` — tracks whether a sorting mode was explicitly selected, helping prevent multiple strategy flags.
- `bench` — indicates whether benchmark output is enabled.

#### `t_ops_counters`

Stores statistics about emitted push_swap operations.

- Individual counters track how many times each operation was executed:
  `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.
- `total_count` — total number of emitted operations.

#### `t_data`

Main structure containing the program state.

- `options` — command-line configuration.
- `stack_a` — pointer to stack A.
- `stack_b` — pointer to stack B.
- `ops` — operation counters used for benchmarking.

`t_data` acts as the central context passed through the program, allowing sorting algorithms and stack operations to access the stacks, options, and benchmark statistics without using global variables.

## Simple Strategy — O(n²)

The simple strategy repeatedly finds the smallest element in stack A, moves it to the top using the shorter rotation direction, and pushes it to B.

```text
while A is not empty:
    find minimum in A
    rotate/reverse-rotate it to the top
    pb

while B is not empty:
    pa
```

The strategy is O(n²) in emitted stack operations because an element may require O(n) rotations and this is repeated for O(n) elements.

### Why this algorithm was selected

It is easy to reason about, provides a clear baseline strategy, and satisfies the required O(n²) mode.

## Medium Strategy — O(n√n)

The medium strategy uses chunk-based sorting.

First, all values in stack A are assigned ranks from `0` to `n - 1`. The input is then divided into approximately `√n` chunks of similar size.

Each chunk is pushed from stack A to stack B by selecting all ranks that belong to the current chunk. After all chunks are transferred, stack B is processed in reverse rank order: the shortest rotation direction is chosen to bring the current maximum rank to the top, and that value is pushed back to stack A.

This results in stack A being rebuilt in ascending order while keeping the operation complexity around **O(n√n)**.

### Why this algorithm was selected

This algorithm was selected because dividing the input into about `√n` chunks keeps the number of passes and rotations significantly lower than the simple O(n²) strategy, while remaining easier to implement and reason about than the radix-based complex strategy.

The resulting operation complexity is approximately **O(n√n)**.

## Complex Strategy — O(n log n)

The complex strategy uses binary LSD radix sort on normalized ranks.

For every bit position:

```text
repeat once for each element:
    if current rank bit == 0:
        pb
    else:
        ra

move all elements from B back to A using pa
```

The current bit is inspected with:

```c
(rank >> bit_position) & 1
```

Ranks range from `0` to `n - 1`, so the number of required bit positions is O(log n). Each pass requires O(n) stack operations, giving:

```text
O(n) * O(log n) = O(n log n)
```

### Why this algorithm was selected

Binary radix sort fits naturally with two stacks, works cleanly on normalized ranks, has predictable operation counts, and satisfies the required O(n log n) complexity.

## Adaptive Strategy

Adaptive mode selects a strategy based on normalized inversion count.

An inversion is a pair `(i, j)` for which:

```text
i < j
```

but:

```text
value[i] > value[j]
```

The maximum possible number of inversions is:

```text
n * (n - 1) / 2
```

and:

```text
disorder = inversion_count / maximum_inversions
```

Selection:

```text
disorder < 0.2              -> simple
0.2 <= disorder < 0.5       -> medium
disorder >= 0.5             -> complex
```

### Why disorder is used

The inversion ratio measures how far the initial stack is from ascending order and allows the program to choose a strategy based on input structure rather than size alone.

## Benchmark Mode

With `--bench`, operations remain on `stdout` and benchmark information is written to `stderr`.

The benchmark should contain:

- initial disorder percentage;
- selected strategy;
- effective complexity;
- total operation count;
- counts of `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

Example redirection:

```bash
./push_swap --bench 4 67 3 87 23 > operations.txt 2> benchmark.txt
```

## Error Handling and Memory Management


### Cleanup Strategy


The program uses separate cleanup functions for linked-list stacks and dynamically allocated token arrays.

- `ft_deallocate()` frees every node in the circular doubly linked list. Since the list is circular, it stores the first node, walks until it reaches that node again, frees each node, then sets the stack pointer to `NULL`.
- Split/token memory is freed immediately after use. Each allocated token string is freed first, followed by the `char **` array itself.
- If parsing fails partway through, already allocated token memory is freed before returning an error.
- Stack cleanup is also performed on normal exit and error paths so that partially built stacks do not remain allocated.


Memory management was checked with Valgrind.


Example:


```bash
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
```

Errors go to `stderr`; normal operations go to `stdout`.

### Resources

The following resources were useful for understanding the concepts and
algorithms used in this project:

- **Big O Notation and Algorithm Complexity**
  - [GeeksforGeeks — Big O Notation](https://www.geeksforgeeks.org/dsa/analysis-algorithms-big-o-analysis/)

- **Linked Lists and Data Structures**
  - [GeeksforGeeks — Circular Linked List](https://www.geeksforgeeks.org/dsa/circular-linked-list/)

- **Radix Sort and Bitwise Operations**
  - [GeeksforGeeks — Radix Sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
  - [Wikipedia — Radix Sort](https://en.wikipedia.org/wiki/Radix_sort)
  - [Wikipedia — Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)

- **Unix File Descriptors**
  - [Wikipedia — File Descriptor](https://en.wikipedia.org/wiki/File_descriptor)

- **Memory Management and Debugging**
  - [Valgrind — Quick Start Guide](https://valgrind.org/docs/manual/quick-start.html)
  - [Valgrind — Memcheck Manual](https://valgrind.org/docs/manual/mc-manual.html)

- **General C and Algorithms**
  - [GeeksforGeeks](https://www.geeksforgeeks.org/)
  - [CS50](https://www.youtube.com/@cs50)

### Topics researched

Topics studied during development included pointers, pointer-to-pointer usage, circular doubly linked lists, stack operations, binary representation, radix sort, algorithmic complexity, inversion counts, command-line parsing, `stdout`/`stderr`, Makefiles, GDB, and memory management.

### Use of AI

AI was used as a learning and review aid for:

- explaining C pointers and linked-list concepts;
- reasoning about algorithmic complexity;
- explaining GDB, Makefiles, shell redirection, and testing commands;
- explaining Big-O complexity

AI was not used as a substitute for implementing the complete project. The final program logic, integration, debugging, testing, and submitted code were completed and verified by the project author.