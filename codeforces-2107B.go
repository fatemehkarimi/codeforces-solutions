// https://codeforces.com/contest/2107/problem/B

package main

import (
	"fmt"
	"slices"
)

func main() {
	var t int64
	fmt.Scan(&t)

	for range t {
		var n int
		var k int64
		fmt.Scan(&n, &k)

		boxes := make([]int64, n)
		for i := range n {
			fmt.Scan(&boxes[i])
		}

		slices.Sort(boxes)

		sumTotal := int64(0)
		for _, b := range boxes {
			sumTotal += b
		}

		biggest := boxes[n-1]
		smallest := boxes[0]

		if biggest-smallest <= k {
			if sumTotal%2 == 0 {
				fmt.Println("Jerry")
			} else {
				fmt.Println("Tom")
			}
		} else {
			nextMax := max(boxes[n-1]-1, boxes[n-2])
			if nextMax-smallest > k {
				fmt.Println("Jerry")
			} else {
				if (sumTotal-1)%2 == 0 {
					fmt.Println("Tom")
				} else {
					fmt.Println("Jerry")
				}
			}
		}
	}
}

