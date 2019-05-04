
package pal

def isPal(n: Int) = n.toString == n.toString.reverse

assert( isPal(101))
assert(!isPal(102))
assert( isPal(1))
assert(!isPal(12))
assert( isPal(12321))

(for {x <- 100 to 999
     y <- 100 to 999} yield x * y)
  .filter(isPal)
  .max
