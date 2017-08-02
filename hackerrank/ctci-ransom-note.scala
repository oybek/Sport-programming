
object Solution {

    def main(args: Array[String]) {
        val sc = new java.util.Scanner (System.in);
        var m = sc.nextInt();
        var n = sc.nextInt();
        var magazine = new Array[String](m);
        for(magazine_i <- 0 to m-1) {
           magazine(magazine_i) = sc.next();
        }
        var ransom = new Array[String](n);
        for(ransom_i <- 0 to n-1) {
           ransom(ransom_i) = sc.next();
        }
    }
}
