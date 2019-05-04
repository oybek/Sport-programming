
def fib(n: BigInt): BigInt = {
  def _fib(n: BigInt, cur: BigInt, prev: BigInt): BigInt = {
    if (n == 0) {
      cur
    } else {
      _fib(n-1, cur+prev, cur)
    }
  }
  _fib(n, 1, 1)
}

assert(fib(0) == 1)
assert(fib(1) == 2)
assert(fib(2) == 3)
assert(fib(3) == 5)
assert(fib(4) == 8)

(for (i <- 0 to 100
     if fib(i) <= 4000000
     if fib(i) % 2 == 0)
  yield fib(i)).sum
