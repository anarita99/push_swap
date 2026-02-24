*This project has been created as part of the 42 curriculum by adores.*

# push_swap

## Description
**push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations with the minimum number of moves. The goal is to implement an efficient sorting algorithm using two stacks (a and b) and a specific set of stack operations. This project explores algorithm complexity, optimization techniques, and data structure manipulation in C.

## About

A sorting algorithm project that sorts integers using two stacks with a limited set of operations, implementing different sorting strategies based on stack size for optimal performance.

`C` `Algorithms` `Data Structures` `Stack Operations` `Radix Sort` `Optimization` `Complexity`

## Instructions

### Compilation

To compile the project, run:
```bash
make
```

### Running the Program

Execute the program by providing a list of integers as arguments:
```bash
./push_swap <number1> <number2> <number3> ...
```

**Examples:**
```bash
./push_swap 3 2 5 1 4
./push_swap 0 -5 10 3
./push_swap "3 2 1"
```

The program outputs a series of operations that will sort the stack.

## Available Operations

| Operation | Description |
|:---------:|:------------|
| `sa` | Swap first 2 elements at the top of stack a |
| `sb` | Swap first 2 elements at the top of stack b |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push first element of stack b to stack a |
| `pb` | Push first element of stack a to stack b |
| `ra` | Rotate stack a up (first element becomes last) |
| `rb` | Rotate stack b up |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack a (last element becomes first) |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` at the same time |

## Algorithm Strategy

The program uses different sorting algorithms depending on the size of the input:

### Small Stacks (2-5 elements)
- **2 elements**: Simple swap if needed
- **3 elements**: Hardcoded optimal solution with maximum 2 operations
- **4 elements**: Push minimum to stack b, sort remaining 3, push back
- **5 elements**: Push two minimums to stack b, sort remaining 3, push back in order

### Large Stacks (6+ elements)
- **Radix Sort**: A sorting algorithm that processes numbers bit by bit from least significant to most significant
- **How it works**:
  1. For each bit position (starting from bit 0):
     - If the bit is 0: push the element to stack b (`pb`)
     - If the bit is 1: rotate it to the bottom of stack a (`ra`)
  2. After processing all elements, push everything back from b to a (`pa`)
  3. Repeat for the next bit position until all bits are processed

## Implementation Details

### Index Assignment
Before sorting, the program assigns each number a normalized index (0 to n-1) based on its relative size. This allows the radix sort algorithm to work efficiently with any range of integers.

### Input Validation
The program validates all input and handles:
- Non-numeric values
- Duplicate numbers
- Integer overflow (values outside INT_MIN to INT_MAX range)
- Empty or invalid arguments

All errors output `Error\n` to stderr.

## Project Structure

```
push_swap/
├── assign.c            # Index assignment for normalization
├── list_op.c           # Linked list operations and utilities
├── parsing.c           # Input validation and parsing
├── push_op.c           # Push operations (pa, pb)
├── push_swap.c         # Main program logic
├── radix_sort.c        # Radix sort implementation
├── revrot_op.c         # Reverse rotate operations (rra, rrb, rrr)
├── rotate_op.c         # Rotate operations (ra, rb, rr)
├── sort_5.c            # Sorting algorithm for 5 elements
├── sort_small.c        # Sorting algorithms for 2-4 elements
├── swap_op.c           # Swap operations (sa, sb, ss)
├── push_swap.h         # Header file with prototypes and structures
└── Makefile            # Build automation
```

## Performance Guidelines

The 42 evaluation considers the number of operations required:

| Stack Size | Maximum Operations (for full score) |
|:----------:|:-----------------------------------:|
| 3 elements | 3 operations |
| 5 elements | 12 operations |
| 100 elements | ~700 operations (5 points), ~900 (4 points), ~1100 (3 points) |
| 500 elements | ~5500 operations (5 points), ~7000 (4 points), ~8500 (3 points) |

## Testing

Test the program with various inputs:
```bash
# Test with small numbers
./push_swap 2 1 3

# Test with negative numbers
./push_swap -1 -5 0 3

# Test with large dataset
ARG=$(seq 1 100 | shuf | tr '\n' ' '); ./push_swap $ARG | wc -l

# Check if result is sorted (using checker if available)
ARG="3 2 5 1 4"; ./push_swap $ARG | ./checker $ARG
```

## Error Handling

The program handles errors gracefully and outputs `Error\n` to stderr for:
- Non-integer arguments
- Numbers outside INT range
- Duplicate values
- Invalid input format

Resources

The main resource that contributed to my understanding of this project was discussing the radix sort implementation and optimization strategies with my colleagues.

Additional references that were helpful include:

- [Radix Sort - GeeksforGeeks](https://www.geeksforgeeks.org/dsa/radix-sort/)

AI tools were used to assist with the writing and structuring of this README file.

---
