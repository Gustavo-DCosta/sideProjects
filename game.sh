#!/bin/bash

# Simple Text Adventure Game
echo "This is what a person can do when she's bored"
# Function to display the introduction
function intro() {
    echo "Welcome to the Adventure Game!"
    echo "You find yourself in a dark forest."
    echo "Your goal is to find the hidden treasure."
    echo "Good luck!"
    echo ""
}

# Function to display the main menu
function main_menu() {
    echo "Main Menu"
    echo "1. Start Adventure"
    echo "2. Exit"
    read -p "Choose an option: " choice
    case $choice in
        1) start_adventure ;;
        2) exit_game ;;
        *) echo "Invalid option. Please try again." ; main_menu ;;
    esac
}

# Function to start the adventure
function start_adventure() {
    echo "You are standing at a crossroad."
    echo "Do you want to go left or right?"
    read -p "Type 'left' or 'right': " direction
    case $direction in
        left) left_path ;;
        right) right_path ;;
        *) echo "Invalid choice. Please try again." ; start_adventure ;;
    esac
}

# Function for the left path
function left_path() {
    echo "You encounter a wild beast!"
    echo "Do you want to fight or run?"
    read -p "Type 'fight' or 'run': " action
    case $action in
        fight) echo "You bravely fight the beast and win!"; treasure ;;
        run) echo "You run away safely."; start_adventure ;;
        *) echo "Invalid choice. Please try again." ; left_path ;;
    esac
}

# Function for the right path
function right_path() {
    echo "You find a peaceful village."
    echo "Do you want to rest or continue your journey?"
    read -p "Type 'rest' or 'continue': " action
    case $action in
        rest) echo "You rest and regain your strength."; start_adventure ;;
        continue) treasure ;;
        *) echo "Invalid choice. Please try again." ; right_path ;;
    esac
}

# Function to find the treasure
function treasure() {
    echo "Congratulations! You have found the hidden treasure!"
    echo "You are now rich beyond your wildest dreams!"
    echo "Do you want to play again? (yes/no)"
    read -p "Type 'yes' or 'no': " play_again
    case $play_again in
        yes) main_menu ;;
        no) exit_game ;;
        *) echo "Invalid choice. Please try again." ; treasure ;;
    esac
}

# Function to exit the game
function exit_game() {
    echo "Thank you for playing! Goodbye!"
    exit 0
}

# Start the game
intro
main_menu
