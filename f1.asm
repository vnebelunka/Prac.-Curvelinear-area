;f1 = e^x + 2
section .text
global f1
f1:
    push ebp
    mov ebp, esp
    finit   
    fld qword[ebp + 8]
    fldl2e
    fmulp ; log_2(e) * x
    frndint ; log_2(e) * x rounded
    fld1 ; for fscale: st(0) * 2^(st(1))
    fscale ; 2^(log_2(e) * x) = e ^ x rounded
    fld qword[ebp + 8]
    fldl2e
    fmulp ; log_2(e) * x
    fld qword[ebp + 8]
    fldl2e
    fmulp
    frndint; log_2(e) * x rounded
    fsubp ; log_2(e)*x(true - rounded)
    f2xm1
    fld1
    fadd ; e^x(true - rounded)
    fmul ; e^x
    fld1
    fadd
    fld1
    faddp ; e^x + 2
    leave
    ret