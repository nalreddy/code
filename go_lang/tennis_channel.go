package main

import "fmt"
import "time"

func player(name string, table chan Ball) {
  for  {
    b := <- table
	b.hits++
	time.Sleep(time.Second)
	fmt.Println(name, "hits ----",b.hits)
	table <- b
	
  }
}

type Ball struct {
  hits int
}

func main() {

  ball := Ball{0}
  
  table := make(chan Ball)
  
  go player("first", table)
  go player("second", table)
  
  table <- ball
  time.Sleep(10 * time.Second)
 // <-table
 // ball = <-table
 // fmt.Println("game over final hits  %d ",ball.hits)
  
}