package main

import "fmt"


func main(){
   mp := map[string] string{}
   
   mp["one"] = "1"
   k,v := mp["one"]
   if v == true {
      fmt.Printf("exists")
   }
}



