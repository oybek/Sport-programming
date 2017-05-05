
object Solution
{
    def main( args: Array[ String ] )
    {
      val sc = new java.util.Scanner( System.in )
      val s = sc.next()

      var inc = 0
      var cur = 'a'
      var l = List.empty[Int]
      s.foreach{ c => c match {
        case `cur` => inc = inc +1
        case _ => cur = c; l = l :+ inc; inc = 0
      }}

      println( l )
    }
}
