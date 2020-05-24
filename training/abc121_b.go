package main

import (
	"fmt"
)

func main() {
	var n, m, c int
	fmt.Scanf("%d %d %d", &n, &m, &c)

	b := make([]int, m)
	for i := 0; i < m; i++ {
		fmt.Scanf("%d", &b[i])
	}

	cnt := 0
	for i := 0; i < n; i++ {
		s := 0
		for j := 0; j < m; j++ {
			var a int
			fmt.Scanf("%d", &a)
			s += a * b[j]
		}
		if s + c > 0 {
			cnt += 1
		}
	}
	fmt.Println(cnt)
}