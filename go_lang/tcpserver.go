package main

import "net"
import "fmt"
import "bufio"
import "strings"
import  "strconv"


func isprime(n int) bool {
   if n <2 {return false}
   
   i :=2 
   for i < n {
      if n %i == 0 { return false }
	  
	  i =i +1
	  
   
   }

     return true
}


func nextprime(n int ) int {
 for {
    n = n + 1
	
	if isprime(n) { return n}
	
 
 }

}


func handler(conn net.Conn) {
  for {
    
    message,_ := bufio.NewReader(conn).ReadString('\n')
	//fmt.Println("message ",message,len(message))
	message = strings.Trim(message, "\n")
    message = strings.Trim(message, "\r")
	//fmt.Println("message ",message,len(message))
	if message == "3" {
	 conn.Close()
	 fmt.Println("connect tion closed for : ",conn.RemoteAddr())
	 
	}
	
	L := strings.Split(message, ":")
	
	var newmessage string
	
	if L[0] == "1" {
	num,_ := strconv.Atoi(strings.Trim(L[1], "\n"))
	result := isprime(num)
	
	newmessage = strconv.FormatBool(result) + "\n"
	}
	
	if L[0] == "2" {
	num,_ := strconv.Atoi(strings.Trim(L[1], "\n"))
	result := nextprime(num)
	
	newmessage = strconv.Itoa(result) + "\n"
	}
	
	//sending repsonse back to client
	conn.Write([]byte(newmessage+"\n"))
	}
}




func main() {
    fmt.Print("server is up....")
	
	listener,_ := net.Listen("tcp", ":5433")
	for {
	   conn,_:= listener.Accept()
	   fmt.Println("\n connection established from : ",conn.RemoteAddr())
	   go handler(conn)
	
	}
	
}