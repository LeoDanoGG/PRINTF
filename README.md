*This project has been created as part of the 42 curriculum by legomez.*

# ft_printf

## Description

<!-- Goal of the project, short overview and allowed external functions. -->

### Project Files

<!-- FILES_START -->
```c
ft_printf.c print_hex.c print_int.c print_ptr.c print_str.c
```
<!-- FILES_END -->

## Algorithm / Architecture: explanation and justification

<!--
- Data structures or classes used and why.
- Step-by-step flow, ideally with a worked example.
- Memory management / performance.
- Trade-offs and limitations.
-->

## Instructions

### Usage

<!-- How to run it, with a short example. -->

### Testing

```c
#include <stdio.h>

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
    ret_orig =    printf("Positive: %d | Negative: %li | Zero: %d\n", 42, -2147483648, 0);
    ret_mi   = ft_printf("Positive: %d | Negative: %i | Zero: %d\n", 42, -2147483648, 0);
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

## Resources

- [Resource name](https://example.com) - what it was used for.

### Use of AI

<!-- Which AI tools were used, for which tasks and for which parts of the project. -->
