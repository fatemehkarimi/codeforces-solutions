// https://codeforces.com/problemset/problem/1/A
// A. Theatre Square

package main

import (
	"fmt"
	"math"
)

func main() {
	var (
		n float64
		m float64
		a float64
	)

	fmt.Scan(&n, &m, &a)
	fmt.Println(int64(math.Ceil(n/a) * math.Ceil(m/a)))
}

