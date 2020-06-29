//Bool expression

object Boolexp {
  //values
  val a = 5
  //variables
  var c: int = 0

  def add(a: int, b: int): int
  {
    return a + b
  }

  def main() {
    c = add(a, 10)
    if (c > 10 || a > 5) {
      println(-c)
    }
    else println(c)
    if (c > 10 && a > 5)
      println(-c)
    else {
      println(c)
    }
    println("Procedure Done")
  }
 }
