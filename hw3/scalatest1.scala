object Hello {
  // constants and variables
  val a = 5
  var c : int
  var e : float = 66.78

  def add(t: float, k: float) : float
  {
    return t + k
  }
  // main statements
  def main ()
  {
    e = add(e, 10.7)
    println (e)
    print(c)
  }
}

