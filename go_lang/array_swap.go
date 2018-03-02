package main

import "fmt"

func main() {
         var temp []  int
          var  x  int
	  fmt.Printf("enter some numbers -1 to exit :")
          
	 for i:=0; ; i++ {
	     fmt.Scan(&x)
             if(x == -1) { break }
	     temp = append(temp, x)
	 }
	 i :=  0
	 j:= len(temp) - 1
	 for  ;  i < j;  {
	       //if(len(temp) %  2) == 0 && ( i +1  ==  j) { break }
	       x =  temp[i]
	       temp[i] = temp[j]
	       temp[j] = x
	       j--
               i++
       }
	 fmt.Printf(" %d\n", temp)
 }
 
