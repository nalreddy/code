package main

import "fmt"


func add(a []int, c chan int) {
   
   s := 0
   for _,x := range a {
    
      s = s + x
   }

   c<-s
}

func main() {
 
 data := [] int {1,2,3,4,5,6,7,8,9,10}
 
 n := len(data)
 
 c1 := make(chan int) 
 c2 := make(chan int)
 
 go add(data[:n/2],c1)
 go add(data[n/2:],c2)
 
 
 r1 := <-c1
 r2 := <-c2
 
 fmt.Println("r1 = ",r1)
 fmt.Println("r2 = ",r2)
 
 }