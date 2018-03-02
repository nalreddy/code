package main

import "fmt"
import "time"


func sayhi(s string) {

  fmt.Println("go routine started ", s)
  
  for i := 0; i< 10; i++ {
     fmt.Println(s, "....value of i = ",i)
     time.Sleep(time.Second)	 
  }
}


func main() {

   go sayhi("one")
   go sayhi("two")
   for i:=0; i< 10; i++ {
   
      fmt.Println("main value of i = ",i)
	  time.Sleep(time.Second)
   
   }
}