;df3 = -2/3

section .text
global df3
df3:
    push ebp
    mov ebp, esp
    fld1
    fld1
    fadd
    fld1
    fld1
    fadd
    fld1
    fadd
    fchs
    fdivp
    leave
    ret
    