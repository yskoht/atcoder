package main

import (
	"fmt"
)

func main() {
	var n, a, b int
	fmt.Scanf("%d %d %d", &n, &a, &b)

	var str string
	fmt.Scanf("%s", &str)

	cnt := 0
	bcnt := 0
	for i := 0; i < n; i++ {
		s := str[i]

		if s == 'c' || cnt >= a + b {
			fmt.Println("No")
		} else {
			if s == 'a' {
				if cnt < a + b {
					fmt.Println("Yes")
					cnt += 1
				} else {
					fmt.Println("No")
				}
			} else {
				if cnt < a + b && bcnt < b {
					fmt.Println("Yes")
					cnt += 1
					bcnt += 1
				} else {
					fmt.Println("No")
				}
			}
		}
	}
}