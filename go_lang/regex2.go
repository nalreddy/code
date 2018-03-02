package main

import "fmt"
import "regexp"
//import "strconv"

  
func main() {

      s := "1 hi I II 0 +232 -434 PYTHON 2 54 45  Wo98rld $% w+3467hh x7787y g-78788j  433 simple  344 JAVA 255 Craz A time -1  fff ggg  Max"
	  	  
	  fmt.Println("enter some pattern of string")
	  
	  var pat string
	  fmt.Scan(&pat)
	  
	  cpat,_ := regexp.Compile(pat)
	  
	  
	  result := cpat.FindAllString(s, -1)
	  
	  fmt.Println(result)
	//[A-Z]\w*[a-z]\b 3rd problem
	//\w*[aeiou]\w*\b 4th problem
	// `\b[A-Z]+\b`  5th
	
	//\b[-+]?\d+\b 6th

    //	\d{1,3}
	   
}