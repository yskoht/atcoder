package main

import (
	"fmt"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	sum, cnt := 1, 0
	for sum < b {
		sum = sum - 1 + a
		cnt += 1
	}
	fmt.Println(cnt)
}