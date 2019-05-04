
def factorize(x: Long): List[Long] = {
  def foo(x: Long, a: Long = 2, list: List[Long] = Nil): List[Long] = a*a > x match {
    case false if x % a == 0 => foo(x / a, a    , a :: list)
    case false               => foo(x    , a + 1, list)
    case true                => x :: list
  }
  foo(x)
}

def factorize2(x: Long): Map[Long, Int] = {
  factorize(x).groupBy(identity).map{ case (k, v) => k -> v.length }
}

def divNum(n: Long): Long =
  if (n == 1) 1
  else factorize2(n).map(_._2 + 1).product

assert(divNum(1) == 1)
assert(divNum(3) == 2)
assert(divNum(28) == 6)
assert(divNum(21) == 4)
assert(divNum(10) == 4)
assert(divNum(15) == 4)
assert(divNum(6) == 4)

(1 to 1000)
  .map(x => x*(x+1L)/2)
  .map(divNum)

val naturals = Stream.from(1)
val triangulars = naturals.map(x => x*(x+1)/2)

triangulars.find(x => divNum(x) > 5)
triangulars.find(x => divNum(x) > 50)
triangulars.find(x => divNum(x) > 500)
