; df2 = 1 / x^2

section .text
global df2
df2:
    push ebp
    mov ebp, esp
    finit
    fld1
    fld qword [esp+8]
    fld qword [esp+8]
    fmul
    fdivp
    leave
    ret
    