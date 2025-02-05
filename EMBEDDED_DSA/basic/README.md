# 2. Basic

**[2.1 Pointers](#2-1-pointers)**

**[2.1.1 Uses of Pointers](#2-1-1-uses-of-pointers)**

**[2.1.2 Pointer Arithmetic Operations](#2-1-2-pointer-arithmetic-operations)**

**[2.1.3 Generic (Universal) Pointer](#2-1-3-generic-universal-pointer)**

**[2.2 Arrays](#2-2-arrays)**

**[2.2.1 Basic Array Operations](#2-2-1-basic-array-operations)**

---

## 2-1 Pointers

In C programming, a pointer is a variable that stores the memory address of another variable. Pointers are powerful tools in C because they allow for dynamic memory management, efficient array handling, and the implementation of complex data structures like linked lists, trees, and graphs.

### 2-1-1 Uses of Pointers

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

### 2-1-2 Pointer Arithmetic Operations

Pointer arithmetic in C allows you to perform arithmetic operations on pointer values, making it possible to navigate through arrays and other data structures efficiently. The rules of pointer arithmetic depend on the data type the pointer is pointing to. 

**Addition:** You can add an integer to a pointer. This moves the pointer forward by that number of elements, not bytes. For example, if you have a pointer to an integer and you add 1 to it, it will point to the next integer, which is typically 2 or 4 bytes away on most systems.

**Subtraction:** You can subtract an integer from a pointer, which moves it backward by that number of elements.

**Pointer Subtraction:** You can also subtract one pointer from another when both point to elements of the same array. This gives you the number of elements between them.

**Comparison:** Pointers can be compared using relational operators. You can check if one pointer points to an earlier or later element in an array.

### 2-1-3 Generic Universal Pointer

In C, a generic pointer, often referred to as a "universal pointer," is a pointer that can point to any data type. The most commonly used type for a
generic pointer in C is `void *`. This type of pointer does not have a specific data type associated with it, allowing it to be used for pointing to
any type of variable, including function pointers or data structures.

Example:

```C
void printValue(void *ptr, char type) 
{
    switch(type) {
        case 'i': // integer
            printf("Integer value: %d\n", *(int *)ptr);
            break;
        case 'f': // float
            printf("Float value: %.2f\n", *(float *)ptr);
            break;
        case 'c': // character
            printf("Character value: %c\n", *(char *)ptr);
            break;
        default:
            printf("Unknown type\n");
    }
}
```

## 2-2 Arrays

An array in C is a collection of elements of the same data type, stored in contiguous memory locations. It allows you to store multiple values of the same type using a single variable name, and you can access individual elements using their index.

Examples:

```C
#include <stdio.h>

int x, *pt;

int main() {
    int data[5] = {10, 20, 30, 40, 50}; // Declaration and initialization of an array

    // same
    x = data[0];
    x = *data;

    // same
    pt = data;
    pt = &data[0];

    // same
    x = data[3];
    x = *(data+3);

    // same
    pt = data;
    data[2] = 0x1234;
    pt[2]   = 0x1234;
    *(pt+2) = 0x1234;

    // Accessing elements
    printf("First element: %d\n", data[0]); // Output: 10
    printf("Second element: %d\n", data[1]); // Output: 20

    return 0;
}
```

### 2-2-1 Basic Array Operations
