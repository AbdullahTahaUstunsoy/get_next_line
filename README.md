*This project has been created as part of the 42 curriculum by austunso.*

# get_next_line

## Description

`get_next_line` is a C function that returns the next line read from a file
descriptor each time it is called:

```c
char *get_next_line(int fd);
```

Called in a loop, it reads a file or the standard input one line at a time.
The returned line includes the `\n`, except for a last line that does not end
with one. When there is nothing left to read, or on error, it returns `NULL`.

The project's main concept is the **static variable**: data read beyond the
current line must be kept between calls, without global variables and without
moving back in the file. Only `read`, `malloc` and `free` are allowed.

## Instructions

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

`BUFFER_SIZE` sets how many bytes `read()` reads at a time. Without the `-D`
flag, the default value in `get_next_line.h` (42) is used. Each returned line
is allocated with `malloc` and must be freed by the caller. Pass `0` as the
file descriptor to read from the standard input.

## Algorithm

`read()` returns a fixed number of bytes, not lines, so one call may return
part of a line or several lines at once. A **static `buffer`** keeps everything
that has been read but not returned yet. It keeps its value between calls and
is only visible inside `get_next_line()`.

Each call:

1. Returns `NULL` if `fd < 0` or `BUFFER_SIZE <= 0`.
2. If `buffer` already contains a `\n`, skips reading.
3. Otherwise reads `BUFFER_SIZE` bytes into a temporary buffer, terminates it
   at the number of bytes actually read, appends it to `buffer` and frees the
   old one. Repeats until a `\n` is found or `read()` returns `0` / `-1`.
4. On end of file: if `buffer` is empty, frees it and returns `NULL`;
   otherwise returns `buffer` itself as the last line and sets the static
   pointer to `NULL`.
5. On read error: frees everything, resets `buffer` and returns `NULL`.
6. Otherwise splits `buffer` at the first `\n`: the part up to and including
   `\n` is returned, the rest becomes the new `buffer`.

Example with `"ab\ncd\nef"` and `BUFFER_SIZE = 4`:

| Call | Read | `buffer` | Returned | `buffer` after |
|---|---|---|---|---|
| 1 | `"ab\nc"` | `"ab\nc"` | `"ab\n"` | `"c"` |
| 2 | `"d\nef"` | `"cd\nef"` | `"cd\n"` | `"ef"` |
| 3 | EOF | `"ef"` | `"ef"` | `NULL` |
| 4 | EOF | `NULL` | `NULL` | `NULL` |

**Why this approach:** checking `buffer` before reading means the function
never reads more than needed for the current line, and the file is never loaded
at once. The temporary buffer is allocated on the heap, so very large
`BUFFER_SIZE` values do not overflow the stack. Every allocation has a single
owner: the returned line belongs to the caller, `buffer` belongs to the
function. Before `buffer` is replaced, its old address is freed, and after it
is freed or returned it is set to `NULL`, which prevents leaks and double
frees. All `malloc` failures are handled the same way: free, reset, return
`NULL`.

## Resources

- get_next_line subject (42)
- `man 2 read`, `man 2 open`, `man 3 malloc`
- [Storage duration and `static` in C – cppreference](https://en.cppreference.com/w/c/language/storage_duration)
- [Pointer arithmetic in C – cppreference](https://en.cppreference.com/w/c/language/operator_arithmetic)

### Use of AI

I used an AI assistant for the following situations:

- **Understanding the subject:** getting short explanations of the key
  concepts, such as file descriptors, how `read()` behaves, static variables
  and memory ownership.
- **Reviewing my code:** asking it to point out problems in my implementation
  (memory leaks, missing `NULL` checks, edge cases) in the form of hints, then
  fixing them myself.
- **Testing:** getting suggestions for test cases (empty files, lines without
  `\n`, different `BUFFER_SIZE` values, standard input) and a simple test
  `main` to run them.
- **Documentation:** help with structuring and wording this README.