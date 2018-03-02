package main

import "fmt"
import "regexp"
//import "strconv"

  
func main() {

      s := "hi I II Hello World $% simple Craz A124 time Max"
	  
	
	  
	  fmt.Println("enter some pattern of string")
	  
	  var pat string
	  fmt.Scan(&pat)
	  
	  cpat,_ := regexp.Compile(pat)
	  
	  result := cpat.FindAllString(s, -1)
	  
	  fmt.Println(result)
	//[A-Z]\w*
	   
}