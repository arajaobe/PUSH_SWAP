*This project has been created as part of the 42 curriculum by arajaobe*

# ft_printf

## Description

ft_printf is a custom implementation of the standard C library function `printf`, created as part of the 42 project "ft_printf".

The goal of this project is to recreate the behavior of `printf` with support for various format specifiers, learning about variadic functions, and understanding how formatted output works at a lower level.

This implementation allows to:

- Understand variadic functions and the stdarg library
- Learn about format string parsing and type handling
- Master number base conversions (decimal, hexadecimal)
- Provide a custom printf function for other 42 projects

## Supported Format Specifiers

ft_printf supports the following conversions:

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a signed decimal integer
- `%i` - Print a signed decimal integer (same as %d)
- `%u` - Print an unsigned decimal integer
- `%x` - Print a number in lowercase hexadecimal
- `%X` - Print a number in uppercase hexadecimal
- `%%` - Print a literal percent sign

## Instructions

### Compiling the library

The project includes a ready-to-use Makefile.

- To compile ft_printf:
`````````make```

This creates the static library libftprintf.a.

- To clean object files:
````````make clean```

- To remove both object files and the library:
```````make fclean```

- To rebuild everything from scratch:
``````make re```

### Using ft_printf in another project

- Include the header ft_printf.h in your .c files:
`````#include "ft_printf.h"```

- Compile your files using the library:
````cc main.c -L/path/to/ft_printf -lftprintf -o main```

* L/path/to/ft_printf : path to the folder containing libftprintf.a
* lftprintf : link the library libftprintf.a

### Example usage
```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello, %s!\n", "world");
    ft_printf("Characters printed: %d\n", count);

    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &count);

    return (0);
}
```

## Technical Implementation

### Key Features

- **Variadic functions**: Uses `va_list`, `va_start`, `va_arg`, and `va_end` from `<stdarg.h>`
- **Character counting**: Returns the total number of characters printed
- **Base conversion**: Implements decimal to hexadecimal conversion for `%x`, `%X`, and `%p`
- **Recursion**: Uses recursive algorithms for number-to-string conversion
- **Edge case handling**: Properly handles NULL pointers, zero values, negative numbers, and INT_MIN

### Architecture

The implementation is structured as follows:

- **ft_printf.c**: Main function that parses the format string and coordinates output
- **Handler functions**: Individual functions for each format specifier (`ft_putchar`, `ft_putstr`, `ft_putnbr`, etc.)
- **Helper functions**: Utility functions for base conversion and number printing

Each helper function returns the number of characters it printed, allowing accurate counting of total output.

## Edge Cases Handled

- `NULL` pointer for `%s` → prints "(null)"
- `NULL` pointer for `%p` → prints "(nil)" or "0x0"
- Zero values for all numeric types
- INT_MIN (-2147483648) for `%d` and `%i`
- Trailing `%` in format string (ignored, matching printf behavior)
- Empty strings
- `%%` → prints a single `%`

## Resources

- Man pages for printf, stdarg functions
- [C Programming: A Modern Approach](http://knking.com/books/c2/) - Variadic functions
- Articles on number base conversion
- Stack Overflow discussions on printf implementation
- 42 Norm

Artificial intelligence was used as a complementary learning tool in order to:

- clarify theoretical concepts related to variadic functions and format specifiers,
- understand number base conversion algorithms,
- debug edge cases and undefined behavior,
- assist in drafting and structuring the project README.

AI was not used to generate final code. All functions were implemented, tested, and debugged manually.

## Function Breakdown

### Core Functions

- `ft_printf` - Main variadic function that processes format string
- `handlers` - Dispatcher function that routes to appropriate format handler

### Format Handler Functions

- `ft_putchar` - Outputs a single character
- `ft_putstr` - Outputs a string (handles NULL)
- `ft_putnbr` - Outputs signed decimal integers
- `ft_putunsnbr` - Outputs unsigned decimal integers
- `ft_printhexa` - Outputs hexadecimal (lowercase or uppercase)
- `ft_printhexalong` - Outputs unsigned long in hexadecimal (for pointers)
- `ft_printpointer` - Outputs pointer addresses with "0x" prefix

Each function has been implemented according to the 42 Norm and returns the number of characters printed.

## Algorithm & Implementation

### General Approach

ft_printf uses a **parsing and dispatch** strategy:

1. **Parse the format string** character by character
2. **Regular characters** are printed directly
3. **Format specifiers** (after `%`) are dispatched to specialized handler functions
4. Each handler function returns the number of characters it printed
5. The main function accumulates and returns the total count

### Number Conversion

**Decimal numbers** (`%d`, `%i`, `%u`): Uses recursive division by 10 to extract digits from right to left, then prints them in correct order through recursion.

**Hexadecimal** (`%x`, `%X`, `%p`): Uses recursive division by 16, mapping remainders 0-9 to '0'-'9' and 10-15 to 'a'-'f' (or 'A'-'F').

**Negative numbers**: Print minus sign first, convert to positive using `long` type to safely handle INT_MIN, then print digits.

### Key Design Decisions

- **Variadic functions**: Uses `va_list`, `va_start`, `va_arg`, `va_end` from `<stdarg.h>`
- **Recursion**: Simplifies number-to-string conversion and ensures correct digit order
- **Modular design**: Each format specifier has its own handler function
- **Character counting**: Every function returns its output length for accurate total count

## Testing

The function has been tested against various scenarios including:

- All supported format specifiers
- Multiple conversions in a single call
- Edge cases (NULL, zero, INT_MIN, empty strings)
- Comparison with the original printf behavior
- Memory leak checks with valgrind

## Notes

- This implementation does not support field width, precision, or flags (bonus features)
- Type mismatches between format specifiers and arguments result in undefined behavior (as with the original printf)
- The function uses only allowed functions: `write`, `malloc`, `free`, `va_start`, `va_arg`, `va_copy`, `va_end`
````
