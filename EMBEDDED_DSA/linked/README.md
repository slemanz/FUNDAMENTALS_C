# 4. Linked List

Is a collection of data, where:

- Successive elements are connected by pointers
- The last element points to NULL
- Can grow or shrink in size during execution of a program
- Can be made just as long as required
- Does not waste memory space

## Operations

- Insert: inserts an element into the list
- Delete: removes and returns the spcified position element from the list
- Delete List: removes all elements of the list (disposes the list)
- Count: returns the number of elements in the list

## Simple Linked-List

```C
struct node
{
    int8_t data;
    struct node *next;
};
```

## Comparisions

### Array

Pros:

- Arrays are simple and easy to use
- Faster to access array elements (It takes constant time)

Cons:

- Preallocates all needed memory up front
- Has fixed size
- Requires one block allocation
- Complex position based insertion

### Linked Lists

Pros:

- Expandable
- Less memory waste

Cons

- No random access allowed
- Difficult to manipulate

## Sinlgy Linked Lists

- Each node has next pointer to the following element
- Last node is NULL

**[CODE IMPLEMENTATION - SIMPLE LINKED LIST](Src/linked.c)**

**[CODE IMPLEMENTATION - LINKED LIST FROM ARRAY](Src/linked_from_arr.c)**

**[CODE IMPLEMENTATION - COMPLETE LINKED LIST OPERATIONS](Src/main.c)**