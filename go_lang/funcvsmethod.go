package main


import "fmt"


type rect struct {
    l float32
	breadth float32
}



func area(r rect ) float32 {
    return r.l * r.breadth
}


func (r *rect) area() float32 {

   return r.l * r.breadth
}

func main() {
      r := rect{2,3}
	  
	  fmt.Println("area1 ",area(r))
	    fmt.Println("area2",r.area())

}