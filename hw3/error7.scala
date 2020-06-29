//function don't return but assign to variable error
object error7 {
  val a = 5
  var c: int = 0

  def add(a: int, b: int) 
  {
    a = a + b
    return
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
