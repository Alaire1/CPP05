#!/bin/bash

# Color codes
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
RESET='\033[0m'

RPN_EXECUTABLE="./RPN"

valid_test_cases=(
    "3 4 +"
    "5 1 2 + 4 * + 3 -"
    "2 3 1 * + 9 -"
    "4 2 / 3 +"
    "10 2 8 * + 3 -"
    "15 7 1 1 + - / 3 * 2 1 1 + + -"
    "1 2 + 3 4 + *"
    "1 2 3 * + 4 +"
    "1 2 3 4 + * +"
    "1 2 3 4 + + *"
)

invalid_test_cases=(
    "3 +"
    "3 4 5 +"
    "3 4 &"
    "4 0 /"
    "5999 1 + v 5"
    ""
    "3 4 + +"
    "3 4 5 + - *"
    "3 4 5 + + +"
    "3 4 5 + + + +"
    "3 4 5 + + + + +"
    "-a 3 +"
)

run_test_cases() {
    local test_cases=("$@")
    for test_case in "${test_cases[@]}"; do
        echo -e "Input: $test_case"
        result=$($RPN_EXECUTABLE "$test_case" 2>&1)
        if [[ $? -eq 0 ]]; then
            echo -e "Output: ${GREEN}$result${RESET}"
        else
            echo -e "Output: $result"
        fi
        echo "----------------------"
    done
}

echo -e "${YELLOW}Running valid test cases:${RESET}"
run_test_cases "${valid_test_cases[@]}"

echo -e "${YELLOW}Running invalid test cases:${RESET}"
run_test_cases "${invalid_test_cases[@]}"