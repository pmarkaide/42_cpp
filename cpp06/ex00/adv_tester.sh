#!/bin/bash

# Colors for output formatting
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test counter
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to print section header
print_header() {
    echo -e "\n${BLUE}======================================${NC}"
    echo -e "${BLUE}  $1${NC}"
    echo -e "${BLUE}======================================${NC}\n"
}

# Function to compare output with expected result
test_conversion() {
    local input="$1"
    local expected_char="$2"
    local expected_int="$3"
    local expected_float="$4"
    local expected_double="$5"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    echo -e "${YELLOW}Testing input: '$input'${NC}"
    
    # Run program and capture output
    output=$(./convert "$input")
    
    # Extract actual values using grep and awk
    actual_char=$(echo "$output" | grep "char:" | awk '{$1=""; print substr($0,2)}')
    actual_int=$(echo "$output" | grep "int:" | awk '{$1=""; print substr($0,2)}')
    actual_float=$(echo "$output" | grep "float:" | awk '{$1=""; print substr($0,2)}')
    actual_double=$(echo "$output" | grep "double:" | awk '{$1=""; print substr($0,2)}')
    
    # Check results
    test_passed=true
    
    # Compare char
    if [[ "$actual_char" != "$expected_char" ]]; then
        echo -e "${RED}✗ char: Expected '$expected_char', got '$actual_char'${NC}"
        test_passed=false
    else
        echo -e "${GREEN}✓ char: $expected_char${NC}"
    fi
    
    # Compare int
    if [[ "$actual_int" != "$expected_int" ]]; then
        echo -e "${RED}✗ int: Expected '$expected_int', got '$actual_int'${NC}"
        test_passed=false
    else
        echo -e "${GREEN}✓ int: $expected_int${NC}"
    fi
    
    # Compare float
    if [[ "$actual_float" != "$expected_float" ]]; then
        echo -e "${RED}✗ float: Expected '$expected_float', got '$actual_float'${NC}"
        test_passed=false
    else
        echo -e "${GREEN}✓ float: $expected_float${NC}"
    fi
    
    # Compare double
    if [[ "$actual_double" != "$expected_double" ]]; then
        echo -e "${RED}✗ double: Expected '$expected_double', got '$actual_double'${NC}"
        test_passed=false
    else
        echo -e "${GREEN}✓ double: $expected_double${NC}"
    fi
    
    if $test_passed; then
        PASSED_TESTS=$((PASSED_TESTS + 1))
        echo -e "${GREEN}Test passed!${NC}"
    else
        echo -e "${RED}Test failed!${NC}"
    fi
    
    echo -e "${BLUE}----------------------------------------${NC}\n"
}

# Check if the program has been compiled
if [ ! -f "./convert" ]; then
    echo -e "${RED}Error: 'convert' executable not found!${NC}"
    echo -e "${YELLOW}Attempting to compile...${NC}"
    make
    
    if [ ! -f "./convert" ]; then
        echo -e "${RED}Compilation failed. Please compile the program first.${NC}"
        exit 1
    fi
fi

# Basic types
print_header "BASIC TYPES"
test_conversion "42" "*" "42" "42.0f" "42.0"
test_conversion "0" "Non displayable" "0" "0.0f" "0.0"
test_conversion "-42" "impossible" "-42" "-42.0f" "-42.0"
test_conversion "4.2" "Non displayable" "4" "4.2f" "4.2"
test_conversion "-4.2" "impossible" "-4" "-4.2f" "-4.2"
test_conversion "4.2f" "Non displayable" "4" "4.2f" "4.2"
test_conversion "-4.2f" "impossible" "-4" "-4.2f" "-4.2"
test_conversion "a" "a" "97" "97.0f" "97.0"

# Special values
print_header "SPECIAL VALUES"
test_conversion "nan" "impossible" "impossible" "nanf" "nan"
test_conversion "nanf" "impossible" "impossible" "nanf" "nan"
test_conversion "+inf" "impossible" "impossible" "inff" "inf"
test_conversion "-inf" "impossible" "impossible" "-inff" "-inf"
test_conversion "inff" "impossible" "impossible" "inff" "inf"
test_conversion "-inff" "impossible" "impossible" "-inff" "-inf"

# Edge cases
print_header "EDGE CASES"
test_conversion "2147483647" "impossible" "2147483647" "2147483647.0f" "2147483647.0"
test_conversion "-2147483648" "impossible" "-2147483648" "-2147483648.0f" "-2147483648.0"
test_conversion "2147483648" "impossible" "impossible" "2147483648.0f" "2147483648.0"
test_conversion "0.0" "Non displayable" "0" "0.0f" "0.0"
test_conversion ".42" "Non displayable" "0" "0.42f" "0.42"
test_conversion "42." "*" "42" "42.0f" "42.0"
# Invalid formats should result in impossible conversions for all types
test_conversion "4.2.0" "impossible" "impossible" "impossible" "impossible"
test_conversion "" "impossible" "impossible" "impossible" "impossible"
test_conversion " " "Non displayable" "32" "32.0f" "32.0"
test_conversion "hello" "impossible" "impossible" "impossible" "impossible"

# Print summary
echo -e "\n${BLUE}======================================${NC}"
echo -e "${BLUE}  SUMMARY${NC}"
echo -e "${BLUE}======================================${NC}"
echo -e "Tests run: $TOTAL_TESTS"
echo -e "Tests passed: $PASSED_TESTS"

if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed: $((TOTAL_TESTS - PASSED_TESTS)) failures${NC}"
    exit 1
fi
