package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scanf("%d", &n)

	var s string
	fmt.Scanf("%s", &s)

	res := 0
	x := 0
	for _, c := range s {
		if c == 'I' {
			x += 1
		}
		if c == 'D' {
			x -= 1
		}
		if res < x {
			res = x
		}
	}

	fmt.Println(res)
}
