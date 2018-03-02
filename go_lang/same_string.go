package main

import "strings"
import "fmt"
import "bufio"
import  "os"

func main() {
	 fmt.Printf("enter first string:")
	 scanner := bufio.NewScanner(os.Stdin)
	 scanner.Scan()
	 s1 := scanner.Text()
	 fmt.Println(s1)
	 fmt.Printf("enter second string:")
	 scanner.Scan()
	 s2 := scanner.Text()
	 fmt.Println(s2)
	 if (strings.Compare(s1, s2) == 0) {
	     fmt.Printf("same")
	     return
	  }
	  for i := 0; i< len(s1); i++ {
	       if(s1[i] != s2[i]) {
	           fmt.Println("s1 = %s s2 =%s diff at %d\n", s1,s2,i)
	       }
	  }
 }
