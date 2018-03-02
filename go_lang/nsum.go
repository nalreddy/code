package main

import "fmt"

func main() {
    var r,c ,x int
	m := [][] int {}
	result := [][] int {}
   
	 for  {
          
	 fmt.Print("enter the number row\n")
	 fmt.Scan(&r)
	 fmt.Print("enter the number col number\n")
	 fmt.Scan(&c)
	 fmt.Print(" enter data \n")
	for i:= 0; i< r;i++ {
		temp := [] int {}
		for j:= 0; j < c; j++ {
			fmt.Scan (&x)
			temp = append(temp, x)
		}
		m = append(m, temp)
	}
	for i:= 0; i< r;i++ {
		for j:= 0; j < c; j++ {
			result[i][j] =  result[i][j] + m[i][j]
		}
		fmt.Println()
	}
	fmt.Print("enter -1 to exit\n")
	fmt.Scan(&x)
	if (x == -1) {
	    break;
         }
        }
	for i:= 0; i< r;i++ {
		for j:= 0; j < c; j++ {
			fmt.Printf("%d", result[i][j])
		}
		fmt.Println()
	}
 }
