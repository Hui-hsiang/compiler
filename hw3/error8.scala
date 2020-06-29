//Array argument error
object error8 {
  val n = 10
  var sum :int = 0
  var index: int = 0 
  var integer: int = 0
  var a : int [10]
  def main() {
    sum = 0
    index = 0
    while (index <= n) {
      sum = sum + index
      a["hello"] = sum
      index = index + 1
    	}
	}
}