; This is a comment outside
fmt: db "; This is a comment outside%2$cfmt: db %3$c%s%3$c, 0%2$csection .text%2$c    global main%2$c    extern printf%2$cother:%2$c    mov eax, 1%2$c    ret%2$cmain:%2$c    call other%2$c    lea rdi, [rel fmt] ; This is a comment in the entry point%2$c    lea rsi, [rel fmt]%2$c    mov rdx, 10%2$c    mov rcx, 34%2$c    xor eax, eax%2$c    sub rsp, 8%2$c    call printf wrt ..plt%2$c    add rsp, 8%2$c    mov eax, 0%2$c    ret", 0
section .text
    global main
    extern printf
other:
    mov eax, 1
    ret
main:
    call other
    lea rdi, [rel fmt] ; This is a comment in the entry point
    lea rsi, [rel fmt]
    mov rdx, 10
    mov rcx, 34
    xor eax, eax
    sub rsp, 8
    call printf wrt ..plt
    add rsp, 8
    mov eax, 0
    ret