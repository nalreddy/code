package main

import "net"
import "fmt"
import "bufio"
import "strings"
import  "strconv"
import "os"


func main() {
    //connet to the server
	
	conn,err:= net.Dial("tcp", "127.0.0.1:5433")
	if err != nil {
	
	   fmt.Println("couldn't Dial check  your connection")
	   return
	}
	for {
	
	 fmt.Println("Menu")
	 fmt.Println("1. test prime")
	 fmt.Println("2  next prime")
	 fmt.Println("3 exit ")
	 	 
		
	 reader := bufio.NewReader(os.Stdin)
	
	 fmt.Print("enter your choice:")
	 ch,_ := reader.ReadString('\n')
	 
	 ch = strings.Trim(ch, "\n")
     ch = strings.Trim(ch, "\r")
	 
	 if ch == "3" {
	    fmt.Fprintf(conn, ch + "\n")
		conn.Close()
		fmt.Println("bye")
		break
	 }
	   if ch == "1" {
	  fmt.Println(" string ch",ch)
	  }
	  
	  ch1,_ := strconv.Atoi(ch)
	  fmt.Println("ch1",ch1)
	  
	  if ch1 < 1 || ch1 > 2 {
	  
	     fmt.Println("improper choice")
		 continue
	  }
	  ch = strconv.Itoa(ch1)
	  fmt.Print("enter data :")
	  data, _ := reader.ReadString('\n')
	  
	 
	 fmt.Println("data len ",data,len(data))
	  text := ch + ":" + data
	  fmt.Fprintf(conn,text)
	   
	   message,_ := bufio.NewReader(conn).ReadString('\n')
	   fmt.Print("Message from server:"+message)
	}

}