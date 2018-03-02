package main 

import "fmt"
import "os"
import "strconv"

//go run sum.go 2 3 


func main() {

n := len(os.Args)
if n != 3 {
   fmt.Println("please provide 3 arguments\n")
   os.Exit(1)
}

x,_ := strconv.Atoi(os.Args[1])
y,_ := strconv.Atoi(os.Args[2])

fmt.Printf("sum  %d", x +y)

}