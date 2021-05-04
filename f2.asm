;f_2(x) -1 / x

section .text
global f2
f2:
    push ebp
    mov ebp, esp
    finit
    fld1
    fchs
    fld qword[esp + 8]
    fdiv
    leave
    ret
    