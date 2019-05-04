
def sumDiff(n: Int): Int = {
  val t = (1 to n).sum
  t*t - (1 to n).map(x => x * x).sum
}

sumDiff(10)
sumDiff(100)
