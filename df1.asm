section .text
global df1
df1:; -exp(-x)
    push ebp
    mov ebp, esp
    finit   
    fld qword[ebp + 8]
    fldl2e
    fmulp
    frndint
    fld1
    fscale
    fld qword[ebp + 8]
    fldl2e
    fmulp
    fld qword[ebp + 8]
    fldl2e
    fmulp
    frndint
    fsubp
    f2xm1
    fld1
    fadd
    fmulp
    leave
    ret