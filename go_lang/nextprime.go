package main
import "fmt"

func main() {
        var p int
	var c int
	var flag int

	flag = 1

	for {
	  fmt.Printf("enter 1  find next  prime\n")
          fmt.Printf("enter 2 exit \n")
	  fmt.Scan(&c)

	 switch c {

	 case 1:
	        fmt.Print("enter number \n")
		fmt.Scan(&p)
 
		 for  j := p+1; ; j++ {
                 for i := 2; i<=j/2; i++ {
                    if (j % i) == 0 {
                        flag = 0
                        break; 
  		   }
		}
                if flag == 1 {
		    fmt.Print("number %d is prime\n", j)
                     break;
	        }
		 flag = 1
	 }
	 case 2:
		 return
	  }
        }


}
