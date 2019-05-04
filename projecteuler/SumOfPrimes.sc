
import Stream._

val primes = 2L #:: sieve(3L)

def sieve(n: Long) : Stream[Long] =
  if (primes.takeWhile(p => p*p <= n).exists(n % _ == 0)) sieve(n + 2)
  else n #:: sieve(n + 2)

primes.takeWhile(_ < 2000000).sum
