package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)

	res, cnt := 0, 0
	for _, c := range s {
		if c == 'A' || c == 'C' || c == 'G' || c == 'T' {
			cnt += 1
			if cnt > res {
				res = cnt
			}
		} else {
			cnt = 0
		}
	}

	fmt.Println(res)
}