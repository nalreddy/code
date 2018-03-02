package main

import "fmt"



func square(c1 <-chan int, c2 chan<- int) {
    n := <-c1
	c2 <- n * n

}

func main() {

  c1 := make(chan int)
  c2 := make(chan int)

  go square(c1,c2)

  c1<-10

  fmt.Println("result",<-c2)
}
 