;f_3(x) -1 / x

section .text
global f3
f3:
    push ebp
    mov ebp, esp
    finit
    fld1
    fchs
    fld qword[esp + 8]
    fdiv
    leave
    ret
    