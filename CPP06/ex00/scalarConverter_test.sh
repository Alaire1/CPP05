#!/bin/bash

# Function to run a test case
run_test() {
    echo "Test with input: $1"
    ./convert "$1"
    echo
}

# Test with no arguments
echo "Test with no arguments:"
./convert
echo

# Test with one argument
run_test "42"
run_test "-42"
run_test "0"
run_test "42.0"
run_test "-42.0"
run_test "0.0"
run_test "3.14"
run_test "-3.14"
run_test "1e10"
run_test "-1e10"
run_test "1.23e-4"
run_test "abc"
run_test "42abc"
run_test "abc42"
run_test "!@#$"
run_test "42!@#"
run_test "!@#42"
run_test ""
run_test "1e308"
run_test "-1e308"
run_test "1e-308"
run_test "-1e-308"
run_test "31"
run_test "32"
run_test "126"
run_test "127"
run_test "inf"
run_test "-inf"
run_test "nan"

# Test with two arguments
echo "Test with two arguments:"
./convert