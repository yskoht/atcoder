package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scanf("%d %d %d", &a, &b, &c)

	if a % 2 == 0 && a == b && b == c && c == a {
		fmt.Println(-1)
	} else {
		cnt := 0
		for {
			if a % 2 == 0 && b % 2 == 0 && c % 2 == 0 {
				a2 := a / 2
				b2 := b / 2
				c2 := c / 2

				a = b2 + c2
				b = a2 + c2
				c = a2 + b2

				cnt += 1
			} else {
				break
			}
		}
		fmt.Println(cnt)
	}
}
