package main

import  "fmt"


type Node struct {
   data int 
   next *Node
}



func display(list *Node) {

 for list != nil {
   fmt.Print(list.data,"->")
   list = list.next
 }
 
  fmt.Println()
  
 
}

func createList(n int) *Node {

var list *Node 
var temp *Node
var p *Node

var m int 

for i:=0 ; i < n; i++ {
   fmt.Print("enter data:")
   fmt.Scan(&m)
   temp = new(Node)
   temp.data = m
   temp.next = nil
   
   if i == 0 {
      list = temp
	  p = temp
	  continue
   }
   p.next = temp
   p = p.next
}

return list
}


func main() {

  var list *Node
  list = createList(5)
  display(list)

}