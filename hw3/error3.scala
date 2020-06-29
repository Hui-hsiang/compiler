 //Use local variables error
object error3 {
	def main() {
		var c:float = 3.14
		var d:float = 3.14
		c = c * d
		println(c)
		func1()
	}
	def func1 (){
		c = 7
		print(c)
	}
}
