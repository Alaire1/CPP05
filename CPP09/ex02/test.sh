#!bin/bash

RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
RESET='\033[0m'
BLUE='\033[34m'
EXECUTABLE="./PMergeMe"

run_test() {
    echo -e "${YELLOW}Testing with: $@${RESET}"
    if ! $EXECUTABLE "$@"; then
        echo -e "${RED}Error: $EXECUTABLE failed to execute${RESET}"
    fi
    echo
}

echo -e "${BLUE}Test with no arguments:${RESET}"
run_test

echo -e "${BLUE}Test with one argument:${RESET}"
run_test "3"
run_test "4"

echo -e "${BLUE}Test with two arguments:${RESET}"
run_test "6" "4"
run_test "4" "3"

echo -e "${BLUE}Test with three arguments:${RESET}"
run_test "6" "4" "3"
run_test "4" "3" "2"
run_test "3" "2" "1"

echo -e "${BLUE}Test with more arguments:${RESET}"
run_test "6" "5" "4" "3" "2" "1"
run_test "4" "9" "0" "8" "7" "7" "1" "2"
run_test "9" "1" "9" "8" "47" "2" "3" "88" "21" "4"
#run_test `shuf -i 1-100000 -n 3000 | tr "\n" " "`

echo "Test with invalid arguments:"
run_test "a"
run_test "a" "b" "i" "u"
run_test "-1" "2" "3" "-4" "5" "6" "7" "8" "9" "10" "-34"
run_test "*" "2" "3"

echo "Test with already sorted values:"
run_test "1" "2" "3" "4" "5" "6" "7" "8" "9" "10"