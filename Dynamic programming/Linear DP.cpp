f(n) = a f(n-1) + b f(n-2) + c f(n-3) 

f(n)     a b c     f(n-1)
f(n-1) = 1 0 0   * f(n-2)
f(n-2)   0 1 0     f(n-3)
-->
f(n)     a b c^n   f(1)
f(n-1) = 1 0 0   * f(2)
f(n-2)   0 1 0     f(3)