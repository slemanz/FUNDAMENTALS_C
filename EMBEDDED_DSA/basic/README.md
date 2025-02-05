# 2. Basic

**[2.1 Pointers](#2.1-pointers)**

**[2.1.1 Uses of Pointers](#2.1.1-uses-of-pointers)**

**[2.1.2 Pointer Arithmetic Operations:](#2.1.2-pointer-arithmetic-operations)**

---

## 2.1 Pointers

In C programming, a pointer is a variable that stores the memory address of another variable. Pointers are powerful tools in C because they allow for dynamic memory management, efficient array handling, and the implementation of complex data structures like linked lists, trees, and graphs.

### 2.1.1 Uses of Pointers

**Dynamic Memory Allocation:** Pointers are used with functions such as malloc, calloc, realloc, and free to manage memory dynamically during program execution.

**Array Manipulation:** Arrays in C can be accessed using pointers. The name of the array acts as a pointer to its first element.

**Functions:** Pointers allow functions to modify variable values directly by passing the address of the variable (pass-by-reference), which can improve performance when working with large data structures.

**Data Structures:** Pointers are essential for creating various data structures such as linked lists, stacks, queues, trees, etc. They enable the linking of nodes and elements.

**Strings and Character Arrays:** Strings in C are manipulated using pointers, allowing for convenient string handling and manipulation.

Example:

```C
#include <stdio.h>

int main() {
    int var = 20;  // An integer variable
    int *ptr;     // A pointer to an integer

    ptr = &var;   // Store the address of var in ptr

    printf("Value of var: %d\n", var);
    printf("Address of var: %p\n", (void *)&var);
    printf("Value of ptr: %p\n", (void *)ptr);
    printf("Value pointed by ptr: %d\n", *ptr); // Dereferencing pointer to get the value

    return 0;
}
```

### 2.1.2 Pointer Arithmetic Operations

