package main

import "fmt"
import "regexp"
import "strconv"

  
func main() {

      s := "hi hello 12 ok 34  #%^ 21 done"
	  
	
	  
	  fmt.Println("enter soem pattern of string")
	  
	  var pat string
	  fmt.Scan(&pat)
	  
	  cpat,_ := regexp.Compile(pat)
	  
	  result := cpat.FindAllString(s, -1)
	  sum := 0
	  
	  for i:= 0; i < len(result); i++ {
	       

		 x,_ := strconv.Atoi(result[i])
		 sum += x
	  }
	  fmt.Println(result)
	  fmt.Println("sum", sum)
	  
	//  ["1234", "56789"]
	  
	  
}