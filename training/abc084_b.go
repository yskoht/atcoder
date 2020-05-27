package main

import (
	"fmt"
	"unicode"
)

func main() {
	var a, b int
	fmt.Scanf("%d %d", &a, &b)

	var s string
	fmt.Scanf("%s", &s)

	flag := true
	i := 0
	for ; i < a; i++ {
		if unicode.IsDigit(rune(s[i])) == false {
			flag = false
			break
		}
	}
	if s[i] != '-' {
		flag = false
	}
	i += 1
	for ; i < a + b + 1; i++ {
		if unicode.IsDigit(rune(s[i])) == false {
			flag = false
			break
		}
	}

	if flag {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
