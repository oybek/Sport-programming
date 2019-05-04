
def isMulOf(muls: Int*)(n: Int): Boolean =
  muls.exists(x => n % x == 0)

assert( isMulOf(3)(3))
assert( isMulOf(3)(9))
assert(!isMulOf(3)(10))

lazy val isMulOf3or5: Int => Boolean = isMulOf(3, 5)

(1 until 10).filter(isMulOf3or5).sum

(1 until 1000).filter(isMulOf3or5).sum
