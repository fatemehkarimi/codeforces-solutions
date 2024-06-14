// https://codeforces.com/problemset/problem/263/A
// A. Beautiful Matrix

package main

import (
	"fmt"
	"math"
)

func main() {
	x := make([][]int, 5)
	var one_x, one_y int
	for i := 0; i < 5; i++ {
		row := make([]int, 5)
		for j := 0; j < 5; j++ {
			fmt.Scan(&row[j])

			if row[j] == 1 {
				one_x = i
				one_y = j
			}
		}
		x[i] = row
	}
	fmt.Println(math.Abs(float64(2-one_x)) + math.Abs(float64(2-one_y)))
}

