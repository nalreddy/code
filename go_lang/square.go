package main

import "fmt"

func main() {
        var r,c ,x int
        var r1, r2, c1, c2  int
	m := [][] int {}
  
	 fmt.Print("enter the number row\n")
	 fmt.Scan(&r)
	 fmt.Printf("enter data\n")
	for i:= 0; i< r;i++ {
		temp := [] int {}
		for j:= 0; j < r; j++ {
			fmt.Scan (&x)
			temp = append(temp, x)
		}
		m = append(m, temp)
	}
	for i:= 0; i< r;i++ {
		for j:= 0; j < r; j++ {
			fmt.Printf("%d", m[i][j])
		}
		fmt.Println()
	}

        for  {
          fmt.Printf(" 1 for swap rows\n")
          fmt.Printf(" 2 for swap cols\n")
          fmt.Printf(" 3 for swap exit \n")

	  fmt.Scan(&x)
	   if( x == -1) {
	       break
	   }
	  switch x {

          case 1 :
                fmt.Print("enter the numbers row\n")
	         fmt.Scan(&r1)
	         fmt.Scan(&r2)
                 for i:=0 ; i < c; i++ {
		      x = m[r1][i]
		      m[r1][i] = m[r2][i]
		      m[r2][i] = x
		 }
	   case 2 :
   		fmt.Print("enter the number col numbers\n")
		 fmt.Scan(&c1)
	 	fmt.Scan(&c2)
		for i:=0 ;i < r; i++ {
		     x = m[i][c1]
		     m[i][c1]=m[i][c2]
		     m[i][c2] = x
		}
		
       }
       }
	for i:= 0; i< r;i++ {
	      for j:= 0; j< r;j++ {
		      fmt.Printf(" %d", m[i][j])
	      }
	      fmt.Println()
      }
 }
