
import Stream._

val primes = 2 #:: sieve(3)

def sieve(n: Int) : Stream[Int] =
      if (primes.takeWhile(p => p*p <= n).exists(n % _ == 0)) sieve(n + 2)
      else n #:: sieve(n + 2)

def getPrimes(maxNum : Int) = primes.takeWhile(_ < maxNum)

sieve(1).take(10001).last