package main

import "fmt"

type Shape interface {
   area() float32
}

type rectangle struct {
    length float32
	breadth float32
}

func(r *rectangle) area() float32 {
 
    return r.length * r.breadth
}

type triangle struct {
    base float32
	height float32
}

func (t *triangle) area() float32 {
  
   return 0.5 * t.base * t.height
 }


func getArea(s Shape ) float32 {
    return s.area()
}

func main() {
  r := rectangle{2,3}
  t := triangle{3,4}
 
  a := getArea(&r)
  fmt.Printf("rect area =%f\n", a)
 
  b:= getArea(&t)
  fmt.Printf("triangle area =%f\n", b)
  
}



