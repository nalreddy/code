package main

import "fmt"


func adder(a,b int) int {
  return a+b
}


func add10(f func(int,int)int ) func(int, int ) int {

       decor := func(a,b int) int {
	          return f(a,b) + 10
	   }
	   return decor
}


func main() {

   s:= add10(adder)(2,3)   
   fmt.Println(s)
}