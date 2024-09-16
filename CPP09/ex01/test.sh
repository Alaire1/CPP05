#!/bin/bash

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
)

run_test_cases() {
    local test_cases=("$@")
    for test_case in "${test_cases[@]}"; do
        echo "Input: $test_case"
        result=$($RPN_EXECUTABLE "$test_case" 2>&1)
        echo "Output: $result"
        echo "----------------------"
    done
}

echo "Running valid test cases..."
run_test_cases "${valid_test_cases[@]}"

echo "Running invalid test cases..."
run_test_cases "${invalid_test_cases[@]}"