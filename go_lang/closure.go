package main

import "fmt"

func seq() func()int {
  i := 0
  gen := func() int {
     i = i + 1
	 return i
  }
  return gen
}


func main() {
     iseq := seq()
	 for i :=0; i < 10; i++ {
	   fmt.Println(iseq())
	 } 
}