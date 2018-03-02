package main

import "fmt"
import "os"
import "bufio"

func main() {
    
	
	  n := len(os.Args)
      if n < 3 {
       
         fmt.Println("enter more thatn 2 arguments\n")
		 os.Exit(1)
      }	  
	  fmt.Println("%d",n)
	  
	  fout,xrr := os.Create(os.Args[n-1])
       if xrr != nil {
        panic(xrr)
       }
	  
	  for i := 1; i < n-1 ; i++ {
	    
		fin,err := os.Open(os.Args[i])
        if err != nil {
           panic(err)
         }

        defer fin.Close()

		scanner := bufio.NewScanner(fin)

        for scanner.Scan() {

         line := scanner.Text()
	
	    fout.Write([]byte(line +"\n"))
        }
		fout.Write([]byte("\n"))
	   // fmt.Printf("%s\n",os.Args[i])
	  
	  }



//x,_ := strconv.Atoi(os.Args[1])


}