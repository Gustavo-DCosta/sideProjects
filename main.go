package main

import (
	"fmt"
)

func main() {
	var choice int8
	to_doList := []string{}
	for {
		// Show menu again after each action
		fmt.Println(`Welcome to our APP, what would you like to do?
1. See your to-do list	
2. Add a to-do
3. Exit`)

		// Get the user's choice
		fmt.Scanln(&choice)

		// Switch based on choice
		switch choice {
		case 1:
			// Print the to-do list
			fmt.Println("Here are your to-do list items:")
			if len(to_doList) == 0 {
				fmt.Println("Your to-do list is empty!")
			} else {
				for i, task := range to_doList {
					fmt.Printf("%d. %s\n", i+1, task)
				}
			}
		case 2:
			// Add a new to-do
			var to_do string
			fmt.Println("Please add a to-do:")
			fmt.Scanln(&to_do)
			to_doList = append(to_doList, to_do)
			fmt.Println("To-do added!")
		case 3:
			// Exit the program
			fmt.Println("Goodbye!")
			return
		default:
			fmt.Println("Invalid choice, please try again.")
		}
	}
}
