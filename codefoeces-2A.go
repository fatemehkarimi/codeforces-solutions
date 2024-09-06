// https://codeforces.com/problemset/problem/2/A
// A. Winner

package main

import "fmt"

func main() {
	type personScore struct {
		name  string
		score int
	}
	var n int
	people := map[string]int{}
	scores := []personScore{}

	fmt.Scan(&n)

	var name string
	var score int
	for range n {
		fmt.Scan(&name, &score)

		_, ok := people[name]
		if ok {
			people[name] += score
		} else {
			people[name] = score
		}

		scores = append(scores, personScore{
			name:  name,
			score: people[name],
		})
	}

	maxScore := 0
	peopleWithMaxScore := []string{}
	for name, score := range people {
		if score > maxScore {
			peopleWithMaxScore = []string{name}
			maxScore = score
		} else if score == maxScore {
			peopleWithMaxScore = append(peopleWithMaxScore, name)
		}
	}

	if len(peopleWithMaxScore) == 1 {
		fmt.Println(peopleWithMaxScore[0])
		return
	} else {
		for _, personScore := range scores {
			if personScore.score < maxScore {
				continue
			}
			if people[personScore.name] == maxScore {
				fmt.Println(personScore.name)
				return
			}
		}
	}
}

