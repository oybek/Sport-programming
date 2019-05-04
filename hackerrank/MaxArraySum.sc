
import java.io._
import java.security._
import java.text._

import scala.collection.mutable

trait Memoizable {

  def memoized[K, V](f: K => V): K => V = new mutable.HashMap[K, V]() {
    override def apply(k: K): V = getOrElseUpdate(k, f(k))
  }
}

object Solution extends Memoizable {

  // Complete the maxSubsetSum function below.
  lazy val maxSubsetSum: List[Int] => Int = memoized {
    case Nil => 0
    case x::Nil => x
    case x::y::tail => Math.max(maxSubsetSum(y::tail), maxSubsetSum(tail) + x)
  }

  def maxSubsetSum(arr: Array[Int]): Int = {
  }

  def main(args: Array[String]) {
    val stdin = scala.io.StdIn

    val printWriter = new PrintWriter(sys.env("OUTPUT_PATH"))

    val n = stdin.readLine.trim.toInt

    val arr = stdin.readLine.split(" ").map(_.trim.toInt).toList
    val res = maxSubsetSum(arr)

    printWriter.println(res)

    printWriter.close()
  }

}

def test(sol: List[Int] => Int): Unit = {
  assert(sol(List()) == 0)
  assert(sol(List(1)) == 1)
  assert(sol(List(1, 2)) == 2)
  assert(sol(List(3, 7, 4, 6, 5)) == 13)
  assert(sol(1.to(1000).toList) == 13)
}

test(Solution.maxSubsetSum)
