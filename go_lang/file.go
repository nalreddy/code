package main

//import "fmt"
import "os"
//import "bufio"

func main() {

   fin,err := os.Open("C:\\Users\\nvv\\Desktop\\Go\\temp.txt")
  // fin,err := os.Open("temp.txt")
if err != nil {
    panic(err)
}

defer fin.Close()


//fout,xrr := os.Create("C:\Users\nvv\Desktop\Go\temp1.txt")
fout,xrr := os.Create("temp1.txt")

if xrr != nil {
    panic(xrr)
}

defer fout.Close()

b := make([]byte,1)

for {
    n,_ := fin.Read(b) 
    if n == 0 {
	   break 
	}
	fout.Write(b)
}
}