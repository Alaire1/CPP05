
#!/bin/bash

# Function to run a test case
run_test() {
    echo "Test with input: $1"
    if ! ./scalar "$1"; then
        echo "Error: ./scalar failed to execute."
    fi
    echo
}

# Test with no arguments
echo "Test with no arguments:"
if ! ./scalar; then
    echo "Error: ./scalar failed to execute."
fi
echo

# Test with one argument
echo "subject test:"
run_test "42.0f"
run_test "0"
run_test "nan"

echo "char test:"
run_test "a"
run_test "b"
run_test "c"
run_test "A"
run_test "B"
run_test "C"
run_test "%"
echo "----------------------------------"
echo "int test:"
run_test "42"
run_test "-42"
run_test "0"
run_test "31"
run_test "126"
run_test "127"
run_test "4545"
echo "----------------------------------"
echo "float test:"
run_test "42.0f"
run_test "-42.0f"
run_test "67.687687676f"
run_test "0.0f"
run_test "-3.14f"
run_test "345f"
run_test "234.8ff"
run_test "234.f"
run_test "1e10f"
run_test "-inff"
run_test "inff"
run_test "nanf"
echo "----------------------------------"
echo "double test:"
run_test "42.0"
run_test "-42.0"
run_test "0.0"
run_test "3.14"
run_test "-3.14"
run_test "1e10"
run_test "123.434"
run_test "inf"
run_test "-inf"
run_test "nan"
echo "----------------------------------"
echo "other test:"
run_test "3...56"
run_test ".7474.4"
run_test ".74744"
run_test "abc"
run_test "42abc"
run_test "!@#$"
run_test "42!@#"
run_test ""
run_test " "
echo "----------------------------------"
# Test with two arguments
echo "Test with two arguments:"
if ! ./scalar "arg1" "arg2"; then
    echo "Error: ./scalar failed to execute."
fi
echo