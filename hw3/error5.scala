//double else error test

object error5{
  val a = 5
  var c:int = 0
  def add(a:int,b:int):int {
    return  a + b
  }
  def main(){
    c = add(a,10)
    if (c > 10)
      print(-c)
    else print(c)
    else print(a)
    println("Procedure Done")
  }
}