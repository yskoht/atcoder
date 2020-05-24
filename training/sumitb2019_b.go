package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)

	rate := 1.08

	res := float64(n) / 1.08
	t1 := int(res)
	if int(float64(t1) * rate) == n {
		fmt.Println(t1)
	} else if int(float64(t1 + 1) * 1.08) == n {
		fmt.Println(t1 + 1)
	} else {
		fmt.Println(":(")
	}
}
