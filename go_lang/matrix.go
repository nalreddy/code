package main

import "fmt"

func main() {
        var r,c ,x int
	m := [][] int {}
  
	 fmt.Print("enter the number row\n")
	 fmt.Scan(&r)
	 fmt.Print("enter the number col number\n")
	 fmt.Scan(&c)
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
			fmt.Printf("%d", m[i][j])
		}
		fmt.Println()
	}
 }


