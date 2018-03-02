package main

import ( 
        "fmt"
		"sync"
		"time"
		)
		
		
var account_state = 0  //make(map[int] int)

var mutex = &sync.Mutex{}

func depositor() {
    for j := 0; j < 1000; j++ {
	
	   mutex.Lock() 
	   account_state = account_state + 1
	   mutex.Unlock()
	   time.Sleep(time.Millisecond)
	}
}


func main() {
  for i := 0 ; i < 50; i++ {
       go depositor()
  }

  
  time.Sleep(time.Second * 5)
  fmt.Println("final balance = ", account_state)

}

