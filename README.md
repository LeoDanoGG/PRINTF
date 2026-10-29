*This project has been created as part of the 42 curriculum by legomez.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the standard C `printf` function. The goal of the project is to learn how to write **variadic functions** (functions with an unknown number of arguments) and to build a small, clean and extensible formatted-output library from scratch.

The function has the following prototype and returns the number of characters printed:

```c
int ft_printf(char const *format, ...);
```

**Supported conversions:**

| Specifier | Description |
|-----------|-------------|
| `%c` | A single character |
| `%s` | A string (prints `(null)` if the pointer is `NULL`) |
| `%p` | A `void *` pointer in lowercase hexadecimal, prefixed with `0x` (prints `(nil)` if `NULL`) |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` | An unsigned integer in lowercase hexadecimal |
| `%X` | An unsigned integer in uppercase hexadecimal |
| `%%` | A literal percent sign |

**Allowed external functions:** `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
This implementation only uses `write` and the `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`).

### Project Files

<!-- FILES_START -->
```c
ft_printf.c ft_printf_utils.c
```
<!-- FILES_END -->

| File | Purpose |
|------|---------|
| `ft_printf.h` | Prototypes, includes and constants (`VALID_FORMAT`, `HEX_LOW`, `HEX_UP`) |
| `ft_printf.c` | Entry point `ft_printf`, the format parser and the `%c` / `%s` helpers |
| `ft_printf_utils.c` | Number printers: `print_nbr`, `print_unsigned`, `print_hex`, `print_ptr` |
| `main.c` | Test program comparing `ft_printf` against the original `printf` |

## Algorithm / Architecture: explanation and justification

### Design

The project uses a **dispatcher pattern**: `ft_printf` walks through the format string, and every time it finds a `%` it delegates to `ft_parser`, which selects the right printing function based on the next character. Each conversion has its own small function that **returns the number of characters it wrote**, so `ft_printf` only needs to add up those return values.

- **No data structures** are needed. The only state is an integer counter and the `va_list`, which keeps the code simple and stack-only.
- **Hexadecimal digits** are looked up in a constant string (`HEX_LOW` / `HEX_UP`) used as a table, so the same function serves `%x`, `%X` and `%p` just by changing the base string.
- **Recursion** is used to print numbers: the most significant digits are printed first by recursing on `n / base`, then the last digit is printed. This avoids buffers and reversing strings.

### Flow (worked example)

`ft_printf("Hi %s, %d\n", "Ana", 42)`

1. `va_start` initialises the argument list.
2. `H`, `i`, ` ` are ordinary characters → `print_chr` each (count = 3).
3. `%` found → move to `s` → `ft_parser` calls `print_str("Ana")` (count = 6).
4. `,` and ` ` are printed (count = 8).
5. `%` found → move to `d` → `ft_parser` calls `print_nbr(42)`. It recurses: `print_nbr(4)` prints `4`, then `2` is printed (count = 10).
6. `\n` is printed (count = 11).
7. `va_end` cleans up and `ft_printf` returns **11**.

### Memory management and performance

- No dynamic allocation: there is no `malloc`, so there are **no leaks** by design.
- Output is not buffered: each character is sent with its own `write` call. This is the simplest and most predictable approach, at the cost of more system calls.
- Recursion depth is bounded by the number of digits (max 10 for 32-bit values, 16 for pointers), so stack usage is negligible.

### Trade-offs and limitations

- Flags, field width and precision (`-`, `0`, `.`, `#`, space, `+`) are **not supported**; only the mandatory conversions are implemented.
- Unbuffered output favours simplicity over speed.
- `write` errors are not propagated: the return value counts attempted characters.
- `%p` with a `NULL` pointer prints `(nil)`, which matches glibc on Linux (macOS prints `0x0`).

## Instructions

### Usage

Compile the library with the project's Makefile and link it with your program:

```bash
make
cc -Wall -Wextra -Werror main.c libftprintf.a -o test
./test
```

Minimal example:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello %s, you are %d years old (0x%x)\n", "42", 42, 42);
    ft_printf("Printed %d characters\n", len);
    return (0);
}
```

### Testing

The following program compares `ft_printf` against the original `printf`, checking both the output and the returned length. A correct implementation shows identical output and equal return values in every test.

<details>
<summary>Dislay main.c</summary>

```c
#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

int main(void)
{
    int ret_orig;
    int ret_mi;
    int val = 42;

// --- Test 1: Character (%c) ---
    printf("--- Test 1: Character (%%c) ---\n");
    ret_orig =    printf("Char: %c\n", 'A');
    ret_mi   = ft_printf("Char: %c\n", 'A');
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 2: String (%s) ---
    printf("--- Test 2: String (%%s) ---\n");
    ret_orig =    printf("String: %s | Null: %s\n", "Hello World!", (char *)NULL);
    ret_mi   = ft_printf("String: %s | Null: %s\n", "Hello World!", (char *)NULL);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 3: Pointer (%p) ---
    printf("--- Test 3: Pointer (%%p) ---\n");
    ret_orig =    printf("Pointer: %p | Null: %p\n", &val, NULL);
    ret_mi   = ft_printf("Pointer: %p | Null: %p\n", &val, NULL);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 4: Integers (%d / %i) ---
    printf("--- Test 4: Integers (%%d / %%i) ---\n");
    ret_orig =    printf("Positive: %d | Negative: %i | Zero: %d\n", 42, INT_MIN, 0);
    ret_mi   = ft_printf("Positive: %d | Negative: %i | Zero: %d\n", 42, INT_MIN, 0);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 5: Unsigned (%u) ---
    printf("--- Test 5: Unsigned (%%u) ---\n");
    ret_orig =    printf("Unsigned: %u | Max: %u\n", 42, 4294967295U);
    ret_mi   = ft_printf("Unsigned: %u | Max: %u\n", 42, 4294967295U);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 6: Hexadecimal Lowercase (%x) ---
    printf("--- Test 6: Hexadecimal (lower) (%%x) ---\n");
    ret_orig =    printf("Hex low: %x | Zero: %x\n", 255, 0);
    ret_mi   = ft_printf("Hex low: %x | Zero: %x\n", 255, 0);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 7: Hexadecimal Uppercase (%X) ---
    printf("--- Test 7: Hexadecimal (upper) (%%X) ---\n");
    ret_orig =    printf("Hex UP: %X | Zero: %X\n", 255, 0);
    ret_mi   = ft_printf("Hex UP: %X | Zero: %X\n", 255, 0);
    printf("Return -> Original: %d | Mine: %d\n\n", ret_orig, ret_mi);

// --- Test 8: Percent (%%) ---
    printf("--- Test 8: Percent (%%%%) ---\n");
    ret_orig =    printf("Percent: %%\n");
    ret_mi   = ft_printf("Percent: %%\n");
    printf("Return -> Original: %d | Mine: %d\n", ret_orig, ret_mi);

	return (0);
}
```
</details>

## Resources

- [printf(3) - Linux manual page](https://man7.org/linux/man-pages/man3/printf.3.html) - reference behaviour of the original function and its return value.
- [stdarg(3) - Linux manual page](https://man7.org/linux/man-pages/man3/stdarg.3.html) - how `va_list`, `va_start`, `va_arg` and `va_end` work.
- [write(2) - Linux manual page](https://man7.org/linux/man-pages/man2/write.2.html) - the only output primitive used by the project.

### Use of AI

AI (Claude) was used as a support tool for:

- **Documentation:** drafting and structuring this README.
- **Code review:** reviewing the code and suggesting test cases for edge conditions.

All the code was written, understood and tested by me. AI suggestions were reviewed and validated before being applied.
