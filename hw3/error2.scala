 //Double c + Boolean d type error
object error2 {
	val a:boolean = true
	def main() {
		var c:float = 3.14
		var d:boolean = true
		c = c * d
		println(c)
	}
}