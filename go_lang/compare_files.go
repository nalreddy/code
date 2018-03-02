package main

import "fmt"
//import "bufio"
import "os"
//import "strconv"

func main() {


  
fin1,err := os.Open(os.Args[1])
   if err != nil {
      panic(err)
   }

 
 defer fin1.Close()
 
 fin2,xrr := os.Open(os.Args[2])
   if xrr != nil {
      panic(xrr)
   }
   
defer fin2.Close()



b1 := make([]byte,1)

b2 := make([]byte,1)

//p1,_ := fin1.Seek(0,2)
//p2,_ :=fin2.Seek(0,2)
//if p1 != p2 

//diff size exit before comapre
//flag := 1


for  {
    n1,_ := fin1.Read(b1) 
   l1,_ := fin1.Seek(0,1)
  
   
    n2, _ := fin2.Read(b2)
	 l2,_ := fin2.Seek(0,1)
	fmt.Printf("files are same %s %d  %s %d\n ", os.Args[1], l1, os.Args[2], l2);
	if  (n1 == 0 ) && (n2 == 0) {
	    fmt.Println("files are same ");
	     return
	}
	if  (n1 == 0 ) || (n2 == 0) {
	    fmt.Println("files are not  same ");
		 fmt.Printf("files are not same %s %d  %s %d\n ", os.Args[1], l1, os.Args[2], l2);
	     return
	}
	if string(b1) != string(b2) {
	   fmt.Printf("files are not same %s %d  %s %d \n", os.Args[1], l1, os.Args[2], l2);
	   return
	}
    	
	
	
}


}