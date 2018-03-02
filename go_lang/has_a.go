package main

import "fmt"


type person struct {
   fname string
   lname string
   email string

}




func (p * person) Fullname() string {

    return p.fname + " " + p.lname
}	


type employee struct {
   Person person
   eid int32
   salary float32

}
func (e *employee) Salary() float32 {

      return e.salary
}

func (e * employee) Fullname() string {

    return e.Person.Fullname()
}	



func main() {

   p := person{"narayan", "reddy"," satya@hpe.com"}
   
   fmt.Println("person",p)
   
    fmt.Println(p.Fullname())
	
    e := employee{p,4,4000}
    fmt.Println("full name ",e.Fullname())
   fmt.Println("employee",e)

}