# Input/output module

## io.open
### Definition
`macro open([char] filename`

## io.read
### Definition
```
macro read
(
    c_uint fd,
    [@const char] buf,
    c_size_t count
) -> c_ssize_t
```

### Inputs
fd - the file descriptor to read from
buf - the string of characters to read from
count - number of bytes to read

### Returns
The number of characters read or `-1` if an error was encountered.

## io.write
### Definition
```
macro write
(
    c_uint fd,
    [char] buf,
    c_size_t count
) -> c_ssize_t
```
### Inputs
fd - the file descriptor to write to
buf - the string of characters to write to
count - number of bytes to write

### Returns
The number of characters written or `-1` if an error was encountered.
