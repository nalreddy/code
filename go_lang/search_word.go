package main

import "fmt"
import "os"
import "bufio"
import "strings"

func main() {
    
	
	  n := len(os.Args)
     // scanner := bufio.NewScanner(os.Stdin)
	  
	  mp := map[string] [] int {}
	  
	  //word->[2,3,6,7]
	  for i := 1; i < n ; i++ {
	    
		fin,err := os.Open(os.Args[i])
        if err != nil {
           panic(err)
         }

        defer fin.Close()

		scanner := bufio.NewScanner(fin)
        j := 0
        for scanner.Scan() {

         line := scanner.Text()
	     words := strings.Split(line, " ")
		 for  i:= 0; i < len(words); i++ {
                 v,k := mp[words[i]]
				 if k == true  {
                    v = append(v, j)
					mp[words[i]] = v
                 } else {
                     mp[words[i]] = [] int {j}
                 }				           		 
		 }
		 j++
	     
        }
		}
	    fmt.Println(mp)
}