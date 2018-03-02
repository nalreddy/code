package main
import "fmt"

func main() {
    flag := 1
	p := 9
   for i:= 3; i < p; i++ {
        if (p %i) == 0 {
		    flag = 0
            break;			
		}
   }
   
   if flag == 1 {
      fmt.Println("%d is primte\n",p) 
   } 
   
  
}
