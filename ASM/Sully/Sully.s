section .bss
    cmd: resb 256

section .data
    orig: db __FILE__, 0
    first: db "Sully.s", 0
    name: db "Sully5.s", 0
    fmt: db "section .bss%2$c    cmd: resb 256%2$c%2$csection .data%2$c    orig: db __FILE__, 0%2$c    first: db %3$cSully.s%3$c, 0%2$c    name: db %3$cSully%4$c.s%3$c, 0%2$c    fmt: db %3$c%s%3$c, 0%2$c    cmdline: db %3$cnasm -f elf64 %%1$s.s -o %%1$s.o && gcc %%1$s.o -o %%1$s; ./%%1$s%3$c, 10, 0%2$c%2$csection .text%2$c    global main%2$c    extern strstr%2$c    extern dprintf%2$c    extern snprintf%2$c    extern system%2$cmain:%2$c    push rbx%2$c    lea rdi, [rel name]%2$c    mov bl, byte [rdi + 5]%2$c%2$c    push rdi%2$c    lea rdi, [rel orig]%2$c    lea rsi, [rel first]%2$c    call strstr wrt ..plt%2$c    test rax, rax%2$c    jnz .skip_dec%2$c%2$c    dec bl%2$c%2$c.skip_dec:%2$c    pop rdi%2$c    mov rax, 2%2$c    mov byte [rdi + 5], bl%2$c    mov rsi, 577%2$c    mov rdx, 0644o%2$c    syscall%2$c%2$c    mov rdi, rax%2$c    lea rsi, [rel fmt]%2$c    lea rdx, [rel fmt]%2$c    mov rcx, 10%2$c    mov r8, 34%2$c    mov r9b, bl%2$c    xor eax, eax%2$c    call dprintf wrt ..plt%2$c%2$c    cmp bl, 48%2$c    jz .end%2$c%2$c    lea rdi, [rel cmd]%2$c    mov rsi, 256%2$c    lea rdx, [rel cmdline]%2$c    lea rcx, [rel name]%2$c    mov byte [rcx + 5], bl%2$c    mov byte [rcx + 6], 0%2$c    xor eax, eax%2$c    call snprintf wrt ..plt%2$c%2$c    lea rdi, [rel cmd]%2$c    call system wrt ..plt%2$c    mov eax, 0%2$c.end:%2$c    pop rbx%2$c    ret", 0
    cmdline: db "nasm -f elf64 %1$s.s -o %1$s.o && gcc %1$s.o -o %1$s; ./%1$s", 10, 0

section .text
    global main
    extern strstr
    extern dprintf
    extern snprintf
    extern system
main:
    push rbx
    lea rdi, [rel name]
    mov bl, byte [rdi + 5]

    push rdi
    lea rdi, [rel orig]
    lea rsi, [rel first]
    call strstr wrt ..plt
    test rax, rax
    jnz .skip_dec

    dec bl

.skip_dec:
    pop rdi
    mov rax, 2
    mov byte [rdi + 5], bl
    mov rsi, 577
    mov rdx, 0644o
    syscall

    mov rdi, rax
    lea rsi, [rel fmt]
    lea rdx, [rel fmt]
    mov rcx, 10
    mov r8, 34
    mov r9b, bl
    xor eax, eax
    call dprintf wrt ..plt

    cmp bl, 48
    jz .end

    lea rdi, [rel cmd]
    mov rsi, 256
    lea rdx, [rel cmdline]
    lea rcx, [rel name]
    mov byte [rcx + 5], bl
    mov byte [rcx + 6], 0
    xor eax, eax
    call snprintf wrt ..plt

    lea rdi, [rel cmd]
    call system wrt ..plt
    mov eax, 0
.end:
    pop rbx
    ret