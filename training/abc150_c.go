package main

import (
	"fmt"
	"strconv"
	"sort"
)

var pattern []string

func f(s string, p string) {
	if len(s) == 0 {
		pattern = append(pattern, p)
		return
	}
	for i := 0; i < len(s); i++ {
		f(s[:i] + s[i+1:], p + string(s[i]))
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	p, q := "", ""
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		p += strconv.Itoa(x)
	}
	for i := 0; i < n; i++ {
		var x int
		fmt.Scanf("%d", &x)
		q += strconv.Itoa(x)
	}

	s := ""
	for i := 1; i <= n; i++ {
		s += strconv.Itoa(i)
	}

	f(s, "")
	sort.Strings(pattern)

	pi, qi := 0, 0
	for i, pat := range pattern {
		if pat == p {
			pi = i
		}
		if pat == q {
			qi = i
		}
	}

	if pi < qi {
		fmt.Println(qi - pi)
	} else {
		fmt.Println(pi - qi)
	}
}
