package main

import "fmt"

func Msl() {
	var a = map[string]int{"": 1}
	fmt.Printf("a\t%v\n", a)
}

func StrRunes() {

	fmt.Println("")
	str := "Gustavo"
	runes := []rune(str)
	fmt.Println(runes[5])        // output: 71
	fmt.Printf("%c\n", runes[5]) // output: G

	str1 := "🐶"
	fmt.Println(len(str1))              // output: 4 ← because 🐶 is 4 bytes!
	fmt.Println([]rune(str1))           // output: [128054]
	fmt.Printf("%c\n", []rune(str1)[0]) // output: 🐶

}

func main() {
	Msl()
	StrRunes()
	var i int8

	// Array (fixed size)
	var nums [7]int = [7]int{1, 2, 3, 4, 5, 7, 8}
	nums[2] = 4
	//nums[4] = 5
	fmt.Println("Array:", nums)
	fmt.Println("Lenght: ", len(nums))

	for i = 0; i < 7; i++ {
		fmt.Println(nums)
	}

	// Slice (dynamic)
	var mySlice = []int{}
	fmt.Println("This is a slice: ", mySlice)
	fmt.Println("The is their capacity: ", cap(mySlice))

	letters := []string{"a", "b", "c"}
	letters = append(letters, "d")
	fmt.Println("Slice:", letters)

	// Modify a slice
	letters[1] = "z"
	fmt.Println("Modified slice:", letters)
}
