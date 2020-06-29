/* fib.scala
 *
 * This test program computes the Nth Fibonacci number
 */

object fib
{
  // variables
  var n: int = 9
  var Fn: int = 1
  var FNminus1: int = 1
  var temp: int

  def main () {
    // compute the nth Fibonacci number
    while (n > 2) {
      temp = Fn
      Fn = Fn + FNminus1
      FNminus1 = temp
      n = n - 1
    }
    
    // print result
    print ("Result of computation: ")
    println (n)
    println (Fn)
  }
}
