package main

//import "strings"
import "fmt"
import "bufio"
import  "os"

func main() {
         c := 0
	 fmt.Printf("enter some strings:")
	 scanner := bufio.NewScanner(os.Stdin)
	 scanner.Scan()
	 line := scanner.Text()
	 fmt.Println(line)
	 fmt.Println(len(line))
	
	 for i := 0; i < len(line) ;  i++ {
	     if line[i] != ' ' {
                 c++;
	     } else if line[i] == ' ' {
		 if ( c %  2 ) == 0 {
			 fmt.Printf(" even len word  len = %d position = %d  i = %d n", c, i -c,i )
		 }
		 c = 0;
	     }
 }
