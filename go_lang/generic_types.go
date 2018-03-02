package main

import "fmt"
import  "reflect"

func main() {
  var g interface{}
  
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  
  g = "hello"
   
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  g = 10
   
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  n := g.(int)
  r := n + 20
  
  fmt.Println("r = ",r)
  
  g = 2.7
  
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  g = map[int] string {1: "one", 2: "two"}
  
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  g = func() { fmt.Println("hello world")}
  
  fmt.Println("type of g =",reflect.TypeOf(g),"value =",g)
  
  f := g.(func())
  
  f()
  
  switch v :=g.(type) {
  
   case int :
       fmt.Println("square of g =",v *v)
		
   case float64:
       fmt.Println("1/g=",1/v)
   case string :
	
	   h := len(v)/2
	   fmt.Println("swap halves =",v[h:] + v[:h])
	case func() :
       v()
  
    default : 
	   fmt.Println("none of the above ")
	  
  
  }
  
  
}