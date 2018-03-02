package main

import (
         "fmt"
		 "math" 
		 "errors"
	    )

func Sqrt(n float64) (float64,error) {

    if n < 0 {
	    return 0, errors.New("Math: negative number passed to Sqrt")
	}
	
	return math.Sqrt(n), nil

}


func main() {
  result , err := Sqrt(10)
  
  var a int
  if err != nil {
     fmt.Println("error =",err)
  } else {
      fmt.Println("result = ",result)
  }
    
}