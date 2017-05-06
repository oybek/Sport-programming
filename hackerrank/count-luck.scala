
object Solution
{
    def main( args: Array[ String ] )
    {
      val sc = new java.util.Scanner( System.in )

      val n = sc.nextInt()
      val m = sc.nextInt()

      sc.nextLine()

      val forest = new Array[ String ]( n )
      for( i <- 0 to n-1 )
        forest( i ) = sc.nextLine()

      val matrix = foresst.map( _ match
      {
        case 'X' => -1
        case '.' => 0
        case '*' =>
        {
        }
        case 'M' =>
        {
        }
      })
    }
}
