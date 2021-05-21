# What is `get_next_line`?

`get_next_line` is a function that reads a line ending with a newline character from a file descriptor, without knowing its size beforehand.

### Specs

To maximize my learning experience, **I Implemented it using only the most fundamental functions**.

- open
- close
- read
- write
- malloc
- free
- exit

**I did not use:**

- `lseek()` between two calls of `get_next_line()` on the same file descriptor.
- global variables

**It manages multiple file descriptors.**
For example, if the file descriptors 3, 4 and 5 are accessible for reading, then I can call `get_next_line()` once on 3, once on 4, once again on 3 then once on 5 etc. without losing the reading thread on each of the descriptors.

### What I've learned

Through this project, I gained a deep understanding of memory allocations, whether they happen on the stack memory or in the heap memory, the manipulation and the life cycle of a buffer, the unexpected complexity implied in the use of one or many static variables.

### Prototype

```c
int get_next_line(const int fd, char **line);
```
