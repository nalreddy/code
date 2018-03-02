package main

import "fmt"


func add(x,y int, c chan int) {
   s := x + y 

   c<-s
}

func main() {
 a := 2
 b := 3
 
 c := make(chan int) 
 
 go add(a,b,c)
 r := <-c
  fmt.Println("sum =",r)
 }