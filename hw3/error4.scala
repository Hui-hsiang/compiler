 //function Argument error
object error4 {
	def func1 (i:int,j:int,k:int):int{
        return i*j-k
    }
    def main() {
		var c:float = 3.14
		var d:float = 3.14
		var e:string = "ok"
		var f:int
		c = c * d
		println(c)
		f = func1(c,d,e)
	}
}
