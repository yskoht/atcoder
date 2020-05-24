package main

import (
	"fmt"
)

func min(a, b int) (int) {
	if a < b {
		return a
	}
	return b
}

func main() {
	var n, k int
	fmt.Scanf("%d", &n)
	fmt.Scanf("%d", &k)

	sum := 0
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		sum += min(x, k - x) * 2
	}

	fmt.Println(sum)
}
