package main

import (
	"fmt"
	"sort"
)


func main() {
	var n int
	fmt.Scanf("%d", &n)

	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &a[i])
	}
	sort.Sort(sort.Reverse(sort.IntSlice(a)))

	alice, bob := 0, 0
	for i, t := range a {
		if i % 2 == 0 {
			alice += t
		} else {
			bob += t
		}
	}

	fmt.Println(alice - bob)
}
