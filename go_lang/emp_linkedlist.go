package main


import "fmt"
import "os"
import "log"
import "encoding/binary"
import "bytes"


/*

type name struct {
   Fname string
   Lname string 
}


//selft referential structure

create linked list of persons

services

firstname:lastname,age,email,mobile
fetch from file  create linked list


type person struct {
    Name name
	Age int
	email string
	mobile string
	next *person
}
*/

type employee struct {
   name string
   id int
}


func readNextBytes(file *os.File, number int) []byte {
	bytes := make([]byte, number)

	_, err := file.Read(bytes)
	if err != nil {
		//log.Fatal(err)
		fmt.Print("err")
	}
     fmt.Println(bytes)
	return bytes
}
func Create() {

   fin,err := os.OpenFile("employee.txt", os.O_CREATE | os.O_RDWR, 0666)
   
   
   if err != nil {
       log.Fatal(err)
   }
   
   
   defer fin.Close()
   fmt.Println("employee file open success fully")
   /*
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
  */
   e := employee {"reddy", 29}
  
   var b bytes.Buffer
   
   fmt.Fprintln(&b, e.name, e.id)
	
   fin.Write(b.Bytes())
    e = employee {"joshit", 2}
	fmt.Fprintln(&b, e.name, e.id)
  
  fin.Write(b.Bytes())
   data := readNextBytes(fin, 6) 
    e1 := employee {}
	buffer := bytes.NewBuffer(data)
	_ = binary.Read(buffer, binary.LittleEndian, &e1)
    fmt.Println("employee",e1)
	
	
 
}

func main() {


  Create()
/*
  fmt.Println("Menu")
  fmt.Println("1. Create")
  fmt.Println("2. dispay")
  fmt.Println("3. insert ")
  fmt.Println("4 delete")
  fmt.Println("5 length")
  fmt.Println("6 undo ")
  fmt.Println("7.save ")
  fmt.Println("8 exit")
  fmt.Println("enter your choice:")
  
*/
}