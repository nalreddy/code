package main

import "testing"

//go test -v addition_test.go
// file name should end with test
//func name should Test
func Sum(x,y int) int {

   return x + y
}

func TestSum(t *testing.T) 
    result := Sum(2, 3)
	if result != 5 {
	
	  
	}
	
}


