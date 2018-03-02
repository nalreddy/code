package main

import "fmt"
import "time"
import "math/rand"

func add(a []int, c chan int) {
   
   s := 0
   for _,x := range a {    
      s = s + x
	  time.Sleep(time.Second)
   }

   c<-s
}


func main() {
  n := 10
  data := [] int {}
  
   rand.Seed(time.Now().Unix())

  for i:=0 ; i <n ; i++ {
  
   
    x:= rand.Intn(1000)
	data = append(data,x)
  }
 c1 := make(chan int) 
 c2 := make(chan int)
 
 go add(data[:n/2],c1)
 go add(data[n/2:],c2)
 
 r:= 0
 for {
 select {
   case r1 := <- c1 :
             fmt.Println("r1",r1)
         r = r+1
    case r2 := <- c2 :
             fmt.Println("r2",r2)
			 
	     r = r+1
  
  }
  
   if r == 2 {
       break
   }
  
  }
  
  fmt.Println("done")
 }