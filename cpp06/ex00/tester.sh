#!/bin/bash

# Colors for output formatting
GREEN='\033[0;32m'
BLUE='\033[0;34m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Function to print section header
print_header() {
    echo -e "\n${BLUE}======================================${NC}"
    echo -e "${BLUE}  $1${NC}"
    echo -e "${BLUE}======================================${NC}\n"
}

# Function to run test with a specific input
run_test() {
    echo -e "${YELLOW}Testing input: '$1'${NC}"
    ./convert "$1"
    echo -e "${GREEN}----------------------------------------${NC}\n"
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
run_test "42"        # Integer
run_test "0"         # Zero
run_test "-42"       # Negative integer
run_test "4.2"       # Double
run_test "-4.2"      # Negative double
run_test "4.2f"      # Float
run_test "-4.2f"     # Negative float
run_test "a"         # Character

# Special values
print_header "SPECIAL VALUES"
run_test "nan"       # Not a number
run_test "nanf"      # Not a number (float)
run_test "+inf"      # Positive infinity
run_test "-inf"      # Negative infinity
run_test "inff"      # Positive infinity (float)
run_test "-inff"     # Negative infinity (float)

# Edge cases
print_header "EDGE CASES"
run_test "2147483647"    # Max int
run_test "-2147483648"   # Min int
run_test "2147483648"    # Overflow int
run_test "0.0"           # Zero with decimal
run_test ".42"           # Decimal without leading zero
run_test "42."           # Decimal without trailing zero
run_test "4.2.0"         # Invalid number format
run_test ""              # Empty string
run_test " "             # Space
run_test "hello"         # Invalid string

# Limits
print_header "LIMITS"
run_test "999999999999999999999999.0"  # Very large number
run_test "-999999999999999999999999.0" # Very large negative number
run_test "0.00000000000000000000001"   # Very small number
run_test "127"   # Max char
run_test "128"   # Beyond max char

# Special characters
print_header "SPECIAL CHARACTERS"
run_test "\t"    # Tab (may need escape handling)
run_test " "     # Space
run_test "!"     # Exclamation mark
run_test "@"     # At symbol
run_test "#"     # Hash

echo -e "\n${GREEN}All tests completed!${NC}"