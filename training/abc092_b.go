package main

import (
	"fmt"
)

func main() {
	var n, d, x int
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d %d", &d, &x)

	cnt := 0
	for i := 0; i < n; i++ {
		var a int
		fmt.Scanf("%d", &a)

		for c := 1; c <= d; c += a {
			cnt += 1
		}
	}

	fmt.Println(cnt + x)
}
