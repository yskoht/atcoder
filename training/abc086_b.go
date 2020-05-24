package main

import (
	"fmt"
	"strconv"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	s := strconv.Itoa(a) + strconv.Itoa(b)
	n, _ := strconv.Atoi(s)

	f := true
	for i := 1; i < 10000; i++ {
		if i * i == n {
			fmt.Println("Yes")
			f = false
			break
		}
	}

	if f {
		fmt.Println("No")
	}
}
