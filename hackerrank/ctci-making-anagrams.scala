
import scala.math._

object Solution {

    def main(args: Array[String]) {
        val sc = new java.util.Scanner (System.in);
        var a = sc.next();
        var b = sc.next();

        var cnt = Array.fill('z'+1){0}

        a.foreach( cnt(_) += 1 );
        b.foreach( cnt(_) -= 1 );

        var sum = 0
        cnt.map( abs(_) ).foreach( sum += _ )

        println(sum);
    }
}

