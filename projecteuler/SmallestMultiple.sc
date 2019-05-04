
def factorize(x: Int): List[Int] = {
  def foo(x: Int, a: Int = 2, list: List[Int] = Nil): List[Int] = a*a > x match {
    case false if x % a == 0 => foo(x / a, a    , a :: list)
    case false               => foo(x    , a + 1, list)
    case true                => x :: list
  }
  foo(x)
}

def factorize2(x: Int): Map[Int, Int] = {
  factorize(x).groupBy(identity).map {case (k, v) => k -> v.length}
}

factorize2(20)

def pow(a: Int, b: Int): Int =
  if (b == 0) 1
  else pow(a, b-1)*a

(1 to 20).flatMap(factorize2)
  .groupBy(_._1)
  .values
  .map(_.maxBy(_._2))
  .map { case (k, v) => pow(k, v) }
  .product

assert((1 to 20).forall(x => 232792560%x == 0))