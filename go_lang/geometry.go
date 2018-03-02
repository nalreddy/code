package main 

import  "fmt"
import   "strconv"
import  "math/rand"
//import  "time"
import "os"

type rect struct {
   len int
   width int  
}

func gen_rect(n int, c chan [] rect) {
     r := [] rect {}
	 
  //rand.Seed(time.Now().Unix())
  //time.Sleep(time.Second)
  for i:=0 ; i < n ; i++{
  
      x:= rand.Intn(5)
	  y := rand.Intn(5	)	
       temp := rect {x,y}	  
	  r = append(r, temp)
   }
  
   c <- r
}

func classify(rt [] rect, c chan  []rect) {

     s := [] rect {}
	 r := [] rect {}
	// temp := [2] rect { {4,4}, {6,6} }
	// l := len(temp)
	 
	 //t := temp[:l]
	 
	 for i:= 0; i< len(rt); i++ {
	 
	     if rt[i].len == rt[i].width {
		   s = append(s, rt[i])
		 } else {
		   r = append(r, rt[i])
		 }
	 
	 }
      //  s = append(s, t...)
		
     fmt.Println("sending square ",s)
	 fmt.Println("sending rectangels",r)
	
	 c<-s
	 c<-r
}

func find_dup(a [] int, final [] rect) {

  for i:=0 ; i < len(a); i++ {
         temp := a[i]
        for j := i + 1; j < len(a); j++ {
            
	  	    if temp == a[j] {
		  	   // dup++;
			  	fmt.Println("dup  final shape one   two ",temp, final[i].len,final[i].width, final[j].len, final[j].width)
				
			}
      }
	  
	  }
	  
}

func Area(rt [] rect, c chan  [] int) {

     a := [] int {}
	
	 
	 for i:= 0; i< len(rt); i++ {
		 a = append(a, rt[i].len * rt[i].width) 
	 }
    
	 c<-a
}

func main() {

    rt := [] rect {}
	a := [] int {}
	
	n,_ := strconv.Atoi(os.Args[1])
     
	 c := make(chan []rect)
	 
     go gen_rect(n, c)
     
	 rt  = <- c
	 
	 fmt.Println(rt) 
	 
	 go classify(rt, c)
	 
	 s := [] rect {}
	 s = <-c
	 r := [] rect {}
	 r = <- c
	 
	
	 fmt.Println("received square ",s)
	 fmt.Println(" received rectangels",r)
	 
	   new := make(chan []int)
	   
	   go Area(s, new)
	   
	    a = <- new
		
		go Area(r, new)
		t := <-new
		a = append(a, t...)
        		
        fmt.Println("area ",a)
		
	//	dup := 0
		
    final := [] rect {}
	
	 final = append(final , s...)
	 final = append(final, r...)
  
     find_dup(a,final)
   
   
	//fmt.Print
  
}