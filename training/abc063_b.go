package main

import (
	"fmt"
)

func main() {
	var s string
	fmt.Scanf("%s", &s)

	f := true
	set := make(map[rune]bool)
	for _, c := range(s) {
		if set[c] {
			fmt.Println("no")
			f = false
			break
		}
		set[c] = true
	}
	if f {
		fmt.Println("yes")
	}
}
