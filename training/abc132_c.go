package main

import (
	"fmt"
	"sort"
	"errors"
)

func f(d []int, k int) (int, int) {
	arc, abc := 0, 0
	for _, t := range d {
		if t >= k {
			arc += 1
		} else {
			abc += 1
		}
	}
	return arc, abc
}

func lower_bound(d []int) (int, error) {
	a, b := 0, 100001

	for a + 1 < b {
		t := (a + b) / 2
		arc, abc := f(d, t)
		if arc > abc {
			a = t
		} else {
			b = t
		}
	}
	arc, abc := f(d, b)
	if arc != abc {
		return 0, errors.New("")
	} else {
		return b, nil
	}
}

func upper_bound(d []int) (int, error) {
	a, b := 0, 100001

	for a + 1 < b {
		t := (a + b) / 2
		arc, abc := f(d, t)
		if arc >= abc {
			a = t
		} else {
			b = t
		}
	}
	arc, abc := f(d, a)
	if arc != abc {
		return 0, errors.New("")
	} else {
		return a, nil
	}
}

func main() {
	var n int
	fmt.Scanf("%d", &n)

	d := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &d[i])
	}
	sort.Ints(d)

	lower, err1 := lower_bound(d)
	upper, err2 := upper_bound(d)

	if err1 != nil || err2 != nil {
		fmt.Println(0)
	} else {
		fmt.Println(upper - lower + 1)
	}
}
