# 2. Basic

**[2.1 Pointers](#2-1-pointers)**

**[2.1.1 Uses of Pointers](#2-1-1-uses-of-pointers)**

**[2.1.2 Pointer Arithmetic Operations](#2-1-2-pointer-arithmetic-operations)**

**[2.1.3 Generic (Universal) Pointer](#2-1-3-generic-universal-pointer)**

**[2.2 Arrays](#2-2-arrays)**

**[2.2.1 Basic Array](#2-2-1-basic-array)**

**[2.3 Structures and Unions](#2-3-structures-and-unions)**

**[2.3.1 Examples](#2-3-1-examples)**

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

### 2-2-1 Basic Array

- [Array 2 max value](Src/arr_max.c)
- [Abstract Data Type (ADT)](Src/arr_adt.c)
- [Array Insertion](Src/arr_insertion.c)
- [Array Reverse and Delete](Src/arr_rev_del.c)
- [Array Sort](Src/arr_sort.c)
- [Array Statistics](Src/arr_statistics.c)
- [Array Merge](Src/arr_merge.c)

## 2-3 Structures and Unions

In C, a **struct** (short for structure) is a user-defined data type that allows you to group variables of different data types under a single name.
This enables you to create complex data types that represent a single entity with multiple attributes.

A **union** is similar to a struct in that it also groups different data types under a single name. However, in a union, all members share
the same memory location. This means that a union can hold only one of its members at a time, and the size of a union is determined by the
size of its largest member.

The **typedef** keyword in C is used to create an alias for existing types, making your code more readable and manageable. When used with structs,
it allows you to define a new name for a struct type, so you don't have to repeat the struct keyword every time you declare a variable of that type.

### 2-3-1 Examples

Typedef and struct:

```C
#include <stdio.h>

// Defining a struct
struct Person {
    char name[50];
    int age;
};

// Using typedef to create an alias
typedef struct Person Person;

int main() {
    Person p1;  // Now you can use Person instead of struct Person
    strcpy(p1.name, "Alice");
    p1.age = 30;

    printf("Name: %s, Age: %d\n", p1.name, p1.age);
    return 0;
}
```

Union:

```C
#include <stdio.h>

// Defining a union
union Data {
    int intValue;
    float floatValue;
    char charValue;
};

int main() {
    union Data data;
    
    data.intValue = 5; // Assigning an int
    printf("Integer: %d\n", data.intValue);
    
    data.floatValue = 5.5; // Now assigning a float
    printf("Float: %.2f\n", data.floatValue);
    
    // The intValue is overwritten by floatValue
    printf("Integer after float assignment: %d\n", data.intValue); // This is now garbage value

    return 0;
}
```

More examples in code:

- [Structures](Src/structures.c)
- [Unions](Src/unions.c)
- [Struct Array](Src/struct_array.c)
- [Nested structures](Src/nested_structures.c)