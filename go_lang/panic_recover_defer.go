package main

import "fmt"


func g(n int) {

    if(n > 3) {
	  fmt.Println("panicking")
	  panic(fmt.Sprintln("value beyond limit .........%v",n))
	  return
	}
	
	defer fmt.Println("defer in g",n)
	fmt.Println("Printing in g ",n)
	g(n+1)
}


func f() {

   defer func() {
      if r:= recover(); r != nil {
	  
	    fmt.Println("panic happened in g an recovered in f:",r)
	  
	  }
   
   }()

     fmt.Println("calling g")
	 g(0)    // controll will not come after this if its panics in g skips below statement
	 fmt.Println("returned nornally from g")
}



func main() {
    f()
    fmt.Println("returned nornally from f")
}