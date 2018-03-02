package main

import "fmt"
//import "bufio"
import "os"
import "strconv"

func main() {


n,_ := strconv.Atoi(os.Args[1])
     
	 
  
fin,err := os.Open("temp.txt")
   if err != nil {
      panic(err)
   }

 p,_ := fin.Seek(0,2)
 x,_:= fin.Seek(0,0)
 
 fmt.Println("%d",x)
defer fin.Close()



b := make([]byte,1)
var j int64

for i:= 0; i < n; i++ {
 
fout,xrr := os.Create("temp" + strconv.Itoa(i) + ".txt")

if xrr != nil {
    panic(xrr)
}

defer fout.Close()



for j= 0; j < p/4; j++ {
    n,_ := fin.Read(b) 
    if n == 0 {
	   break 
	}
	fout.Write(b)
}

}

}