package main

import "strings"
import "fmt"
import "bufio"
import  "os"

func main() {
	 fmt.Printf("enter string:")
	 scanner := bufio.NewScanner(os.Stdin)
	 scanner.Scan()
	 line := scanner.Text()
	 fmt.Println(line)
         var result [] string         
         words := strings.Split(line, " ")
         var t byte
	 for i := 0; i < len(words) ;  i++ {
		 b :=  []byte(words[i])
		   fmt.Println("word %s len =%d byte arrya %d \n",words[i], len(words[i]), len(b))
		  t = b[len(b) - 1]  
                  b[len(b) - 1 ] =  b[0]
		  b[0] = t
		  s2 := string(b)
		  fmt.Println(s2)
		  result = append(result, s2)
         }
	 fmt.Println(result)
 }
