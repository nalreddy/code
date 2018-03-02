package main

import "fmt"
import "regexp"
  
func main() {

      s := "hi hello 1234 ok 56789 done"
	  
	
	  
	  fmt.Println("enter soem pattern of string")
	  
	  var pat string
	  fmt.Scan(&pat)
	  
	  cpat,_ := regexp.Compile(pat)
	  
	  result := cpat.FindAllString(s, -1)
	  
	  //	n := len(result)
	  fmt.Println(result)
	  
	//  ["1234", "56789"]
	  
	  
	  }