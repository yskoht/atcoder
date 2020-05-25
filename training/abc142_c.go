package main

import (
	"fmt"
	"sort"
)

type Pair struct {
	Index int
	Value int
}

type Pairs []Pair

func (p Pairs) Len() int {
	return len(p)
}

func (p Pairs) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func (p Pairs) Less(i, j int) bool {
	return p[i].Value < p[j].Value
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	arr := make(Pairs, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &arr[i].Value)
		arr[i].Index = i + 1
	}

	sort.Sort(arr)

	for i, p := range arr {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(p.Index)
	}
	fmt.Println("")
}
