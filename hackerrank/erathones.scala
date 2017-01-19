
object Solution {
	def genErathones(n: Int): List[Int] = {
    var primes = 2 to n
    primes.toList
	}

	def main(args: Array[String]) {
    genErathones(10).foreach( println )
	}
}

