//Write a full Go snippet that:
//- Creates a slice of 5 names
//- Iterates over them
//- Creates a map that counts how many letters are in each name
//- Prints the map like:
//   `{"Alice": 5, "Bob": 3, "Chad": 4, ...}`

package main

import (
	"fmt"
)

func main() {
	var i int8
	names := []string{"Alan", "Tiago", "Andreia", "Gustavo", "Mathew"}

	for i = 0; i < 5; i++ {
		fmt.Println(names)
		var lettersCount = map[string]int{}
		lettersCount["Alan"] = len(names[0])
		lettersCount["Tiago"] = len(names[1])
		lettersCount["Andreia"] = len(names[2])
		lettersCount["Gustavo"] = len(names[3])
		lettersCount["Mathew"] = len(names[4])
	}

	/* ----------------------------Correction-------------------------------------------------
	names := []string{"Alan", "Tiago", "Andreia", "Gustavo", "Mathew"}

	// Create the map that will store the name as key and its length as value
	lettersCount := map[string]int{}

	// Iterate over each name and calculate the length
	for _, name := range names {
		lettersCount[name] = len(name)
	}

	// Print the map
	fmt.Println(lettersCount)
	*/

}
