package main

//import "fmt"
import "bufio"
import "os"
func main() {

   
fin,err := os.Open("temp.txt")
   if err != nil {
      panic(err)
   }

defer fin.Close()


fout,xrr := os.Create("temp1.txt")

if xrr != nil {
    panic(xrr)
}

defer fout.Close()


scanner := bufio.NewScanner(fin)

for scanner.Scan() {

    line := scanner.Text()
	
	fout.Write([]byte(line +"\n"))
}
}