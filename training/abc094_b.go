package main

import (
	"fmt"
)

func main() {
	var n, m, x int
	fmt.Scanf("%d %d %d", &n, &m, &x)

	left, right := 0, 0
	for i := 0; i < m; i++ {
		var a int
		fmt.Scanf("%d", &a)
		if a < x {
			left += 1
		} else {
			right += 1
		}
	}

	res := left
	if left > right {
		res = right
	}
	fmt.Println(res)
}
