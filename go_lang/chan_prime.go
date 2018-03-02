package main 

import "fmt"
import "math/rand"
import "os"
import "strconv"

import "time"


func is_prime(p int) bool {
   flag := 1
   for i:= 2; i <=p/2; i++ {
        if (p %i  ) == 0 {
		    flag = 0
            break;			
		}
   }
   
   if flag == 1 {
     return true
   } 
   
   return false
}

func gen_prime(n int, c chan []int) {
  p := []int {} 
  //rand.Seed(time.Now().Unix())
  time.Sleep(time.Second)
  for i:=0 ; i < n ; {
  
      x:= rand.Intn(1000)
	  
	  if is_prime(x) {
	      p = append(p, x)
		  i++;
	  }
   }
   fmt.Println(p)
   c <- p
}



func main() {

  
    n,_ := strconv.Atoi(os.Args[1])
	
    c1 := make(chan []int)
	c2 := make(chan []int)
	c3 := make(chan []int)
	
	
	go gen_prime(n, c1)
	go gen_prime(n, c2)
	go gen_prime(n, c3)
	
	r := 0
	 result := []int {}
	for {
 
     select {
      case r1 := <-c1 :
              fmt.Println("first one done",r1)
			  result = append(result, r1...)
           r = r+1
      case r2 := <-c2 :
              fmt.Println("second done",r2)
			  result = append(result, r2...)
			 
	      r = r+1
      case r3 := <-c3 :
              fmt.Println("third done",r3)
			  result = append(result, r3...)
			 
	      r = r+1
     }
  
     if r == 3 {
         break
     }
  
  }
   dup := 0
   for i:=0 ; i < len(result); i++ {
         temp := result[i]
      for j := i + 1; j < len(result); j++ {
           
		    if temp == result[j] {
			    dup++;
				fmt.Println(temp)
			}
      }
   
    }
	fmt.Printf("dup %d\n", dup)
	fmt.Printf("dup %f", (dup/len(result)) * 100)

   fmt.Println(result)
   
  fmt.Println("done")


}
