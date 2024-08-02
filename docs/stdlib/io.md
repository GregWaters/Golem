# Input/output module


## SYNOPSIS
```nasm
export <io>

macro io.print(str string) -> int
{
    ; implementation defined
}
```

## POSSIBLE CODE GENERATED
```nasm
; x86_64 Linux, netwide assembler
; `string` is stored in rsi in this example
; has no label due to being defined as a macro
    mov edx, [rsi - 4]
    mov eax, 1
    mov edi, 1
    syscall
```

## INPUT
`string`: a character pointer holding the address of the first character and immediately following the `uint<32>` length value of the string

## RETURN VALUE
The number of characters output, -1 if an error was encountered.
