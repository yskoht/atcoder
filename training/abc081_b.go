package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	for cnt := 0; ; cnt += 1 {
		flag := true
		for i := 0; i < n; i++ {
			if a[i] % 2 != 0 {
				flag = false
				break
			}
		}
		if flag {
			for i := 0; i < n; i++ {
				a[i] /= 2
			}
		} else {
			fmt.Println(cnt)
			break
		}
	}
}
