; This is a comment

%macro NAME 0
name: db "Grace_kid.s", 0
%endmacro
%macro STR 0
fmt: db "; This is a comment%2$c%2$c%%macro NAME 0%2$cname: db %3$cGrace_kid.s%3$c, 0%2$c%%endmacro%2$c%%macro STR 0%2$cfmt: db %3$c%s%3$c, 0%2$c%%endmacro%2$c%2$csection .data%2$c    NAME%2$c    STR%2$c%2$csection .text%2$c    global main%2$c    extern dprintf%2$c%%macro MAIN 0%2$cmain:%2$c    mov rax, 2%2$c    lea rdi, [rel name]%2$c    mov rsi, 577%2$c    mov rdx, 0644o%2$c    syscall%2$c%2$c    mov rdi, rax%2$c    lea rsi, [rel fmt]%2$c    lea rdx, [rel fmt]%2$c    mov rcx, 10%2$c    mov r8, 34%2$c    xor eax, eax%2$c    sub rsp, 8%2$c    call dprintf wrt ..plt%2$c    add rsp, 8%2$c    mov eax, 0%2$c    ret%2$c%%endmacro%2$c%2$cMAIN", 0
%endmacro

section .data
    NAME
    STR

section .text
    global main
    extern dprintf
%macro MAIN 0
main:
    mov rax, 2
    lea rdi, [rel name]
    mov rsi, 577
    mov rdx, 0644o
    syscall

    mov rdi, rax
    lea rsi, [rel fmt]
    lea rdx, [rel fmt]
    mov rcx, 10
    mov r8, 34
    xor eax, eax
    sub rsp, 8
    call dprintf wrt ..plt
    add rsp, 8
    mov eax, 0
    ret
%endmacro

MAIN