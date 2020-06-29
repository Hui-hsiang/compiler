/*
 * Example with Functions
 * 
 * 
 * def ifelseTest(){
		if (true){ print "if" }
		else if (false) {
			print "else if 1 "
			if(false){
				print ("else if if ")
			}
			else{
				print "else if else"
			}
			
			}
		else if (true) {print "elseIf2"}
		else {print "else"}
		println ("Hello World")

		var a = 6
		for (a <- 1 to 10){
			print(a)
		}


	}
 */

object example { 
	var i = 0
	def main(){
		var a = 6
		for (i <- 1 to 4){
			print ("n = ")
			println i
			for (a <- 5 to 15){
				println(a)
			}
		}
	}
}