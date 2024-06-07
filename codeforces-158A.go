// https://codeforces.com/problemset/problem/158/A
// A. Next Round

package main

import "fmt"

func main() {
	var n, k int
	fmt.Scan(&n, &k)

	var scores = make([]int, n)

	for i := 0; i < n; i++ {
		fmt.Scan(&scores[i])
	}

	var baseScore = scores[k-1]
	var count int

	for i := 0; i < len(scores); i++ {
		if scores[i] > 0 && scores[i] >= baseScore {
			count += 1
		}
	}

	fmt.Println(count)
}

