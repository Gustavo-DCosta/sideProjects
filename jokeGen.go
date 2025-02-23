package main

import (
	"encoding/json"
	"fmt"
	"io"
	"net/http"

	"github.com/fatih/color"
)

type Joke struct {
	Setup     string `json:"setup"`
	Punchline string `json:"punchline"`
}

func main() {
	color.Blue("Starting the joke generator...")
	// API URL for a random joke
	url := "https://official-joke-api.appspot.com/random_joke"

	// Make the HTTP GET request
	resp, err := http.Get(url)
	if err != nil {
		fmt.Println("Error:", err)
		return
	}
	defer resp.Body.Close() // Always close the response body

	// Read the response body
	body, err := io.ReadAll(resp.Body)
	if err != nil {
		fmt.Println("Error reading response:", err)
		return
	}

	// Unmarshal JSON into the struct
	var joke Joke
	err = json.Unmarshal(body, &joke)
	if err != nil {
		fmt.Println("Error decoding JSON:", err)
		return
	}

	// Print the joke
	fmt.Println(`
	`)
	color.Yellow(joke.Setup)
	color.Green(joke.Punchline)
}
