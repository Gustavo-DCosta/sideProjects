package main

import (
	"fmt"
	"regexp"
	"unicode"
)

func main() {
	var password string
	fmt.Print("Enter a password to check: ")
	fmt.Scanln(&password)

	if isValidPassword(password) {
		fmt.Println("Password is valid.")
	} else {
		fmt.Println("Password is invalid.")
	}
}

func isValidPassword(password string) bool {
	if len(password) < 8 {
		fmt.Println("Password must be at least 8 characters long.")
		return false
	}

	if !hasUppercase(password) {
		fmt.Println("Password must contain at least one uppercase letter.")
		return false
	}

	if !hasLowercase(password) {
		fmt.Println("Password must contain at least one lowercase letter.")
		return false
	}

	if !hasDigit(password) {
		fmt.Println("Password must contain at least one digit.")
		return false
	}

	if !hasSpecialChar(password) {
		fmt.Println("Password must contain at least one special character.")
		return false
	}

	return true
}

func hasUppercase(s string) bool {
	for _, c := range s {
		if unicode.IsUpper(c) {
			return true
		}
	}
	return false
}

func hasLowercase(s string) bool {
	for _, c := range s {
		if unicode.IsLower(c) {
			return true
		}
	}
	return false
}

func hasDigit(s string) bool {
	for _, c := range s {
		if unicode.IsDigit(c) {
			return true
		}
	}
	return false
}

func hasSpecialChar(s string) bool {
	// Define a regex for special characters
	re := regexp.MustCompile(`[!@#$%^&*(),.?":{}|<>]`)
	return re.MatchString(s)
}
