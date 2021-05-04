; -2(x+1) / 3

section .text
global f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld1
    fld qword[ebp+8]
    fadd
    push dword 2
    fld dword[esp]
    add esp, 4
    fchs
    fmul
    push dword 3
    fld dword[esp]
    add esp, 4
    fdivp
    leave
    ret