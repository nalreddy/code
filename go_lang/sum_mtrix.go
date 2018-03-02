package main

import "fmt"

func main() {
        var r,c ,x int
	m1 := [][] int {}
	m2 := [][] int {}
  
 fmt.Print("enter the number row for m1 \n")
 fmt.Scan(&r)
 fmt.Print("enter the number col number m1\n")
 fmt.Scan(&c)
 fmt.Printf("enter data for m1 \n")

	for i:= 0; i< r;i++ {
		temp := [] int {}
		for j:= 0; j < c; j++ {
			fmt.Scan (&x)
			temp = append(temp, x)
		}
		m1 = append(m1, temp)
	}
	for i:= 0; i< r;i++ {
		for j:= 0; j < c; j++ {
			fmt.Printf("%d", m1[i][j])
		}
		fmt.Println()
	}

	 fmt.Print("enter the number row m2 \n")
	 fmt.Scan(&r)
	 fmt.Print("enter the number col number m2 \n")
	 fmt.Scan(&c)
 fmt.Printf("enter data for m2 \n")
	for i:= 0; i< r;i++ {
		temp := [] int {}
		for j:= 0; j < c; j++ {
			fmt.Scan (&x)
			temp = append(temp, x)
		}
		m2 = append(m2, temp)
	}
	for i:= 0; i< r;i++ {
		for j:= 0; j < c; j++ {
			fmt.Printf("%d", m2[i][j])
		}
		fmt.Println()
        }

	for i:= 0; i< r;i++ {
		for j:= 0; j < c; j++ {
			fmt.Printf("%d", m1[i][j] + m2[i][j])
		}
		fmt.Println()
	     
        }

}
