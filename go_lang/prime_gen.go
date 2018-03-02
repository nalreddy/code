package main

import "fmt"

func is_prime(p int) bool {
   flag := 1
   for i:= 3; i <=p/2; i++ {
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
 
func seq() func()int {
  i := 3
  gen := func() int {
     i = i + 1
	 for ; ; i++ {
	    if is_prime(i) {
		    return i
		}
	 }
	 return i
  }
  return gen
}


func main() {
     iseq := seq()
	 for i :=0; i < 15; i++ {
	   fmt.Println(iseq())
	 } 
}