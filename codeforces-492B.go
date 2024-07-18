// https://codeforces.com/problemset/problem/492/B
// B. Vanya and Lanterns

package main

import (
	"fmt"
	"math"
)

func main() {
	var n, l int
	fmt.Scan(&n, &l)

	lanterns := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&lanterns[i])
	}

	insertionSort(lanterns)

	maxDistance := 0.0
	for i := 1; i < len(lanterns); i++ {
		distance := float64(lanterns[i]-lanterns[i-1]) / 2
		maxDistance = math.Max(float64(maxDistance), distance)
	}

	maxDistance = math.Max(maxDistance, float64(lanterns[0]))
	maxDistance = math.Max(maxDistance, float64(l-lanterns[n-1]))

	fmt.Println(maxDistance)
}

func insertionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		for j := i + 1; j < len(arr); j++ {
			if arr[i] > arr[j] {
				tmp := arr[j]
				arr[j] = arr[i]
				arr[i] = tmp
			}
		}
	}
}

