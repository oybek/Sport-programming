import math._
import scala.util._

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/

def readInt = 3

(0 to 3).toList
(0 until 3).toList

// game loop
while(true) {
  val n = 8
  val hs = (0 until n).map(_ -> readInt).toList
  println(hs.maxBy(_._2)._1)
}
