
import scala.math

def isPrime(n: Int) = n > 1 && !(2 until n).exists(d => n % d == 0)

assert( isPrime(3))
assert( isPrime(2))
assert( isPrime(5))
assert(!isPrime(10))

val n = 600851475143L

def primeDivs(n: Long): List[Long] = {

  def _primeDivs(n: Long, d: Int): List[Long] = {
    if (isPrime(d) && n % d == 0) {
      d :: _primeDivs(n/d, d)
    }
    else if (d*d >= n) {
      if (n > 1)
        List(n)
      else
        List()
    } else {
      _primeDivs(n, d+1)
    }
  }

  _primeDivs(n, 2)
}

primeDivs(10)
primeDivs(100)
primeDivs(101)
primeDivs(n)

val xx = Some(3)
val yy = None

for {x <- xx
     y <- yy} yield x -> y
