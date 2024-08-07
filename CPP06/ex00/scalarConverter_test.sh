#!/bin/bash

# Test with no arguments
echo "Test with no arguments:"
./convert
echo

# Test with one argument
echo "Test with one argument:"
./convert "42"
echo

# Test with two arguments
echo "Test with two arguments:"
./convert "42" "extra_arg"
echo

# Test with a floating-point number
echo "Test with a floating-point number:"
./convert "42.42"
echo

# Test with a string
echo "Test with a string:"
./convert "hello"
echo

# Test with a special character
echo "Test with a special character:"
./convert "@"
echo