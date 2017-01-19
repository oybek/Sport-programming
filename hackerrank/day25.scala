
object Solution {
	def isPrime(n: Int): Boolean = {
		if (n <= 1)
			false
		else
		if (n == 2)
			true
		else
			!(2 to (Math.sqrt(n).toInt)).exists(divisor => n % divisor == 0)
	}

	def main(args: Array[String]) {
		val stdin = io.Source.stdin.getLines().toList
		stdin.drop(1).foreach { s	=>
			if (isPrime(s.toInt))
				println("Prime")
			else
				println("Not prime")
		}
	}
}

