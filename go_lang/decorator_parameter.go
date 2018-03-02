package main

import "fmt"


func adder(a,b int) int {
  return a+b
}


func addn(f func(int,int) int, n int ) func(int, int ) int {

       decor := func(a,b int) int {
	          return f(a,b) + n
	   }
	   return decor
}


func main() {
   s:= addn(adder, 20)(2,3)
   
   fmt.Println(s)
}