#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cstdlib>
#include "BitcoinExchange.hpp"

// Test case structure
struct TestCase {
    std::string name;
    std::vector<std::string> inputLines;
    bool fileExists;
};

// Helper function to create a test file
void createTestFile(const std::string& filename, const std::vector<std::string>& lines) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const std::string& line : lines) {
            file << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Error: Could not create test file: " << filename << std::endl;
    }
}

// Helper function to create a sample database file
void createSampleDatabase() {
    std::vector<std::string> lines = {
        "date,exchange_rate",
        "2009-01-02,0",      // Bitcoin genesis block date
        "2010-07-17,0.05",   // First recorded bitcoin price
        "2011-02-09,1.0",    // Bitcoin reaches $1
        "2013-04-10,230.0",  // First major spike
        "2017-12-17,19666.0", // 2017 peak
        "2018-12-15,3200.0", // 2018 low
        "2020-03-13,4970.0", // Covid crash
        "2021-11-10,68789.0", // ATH
        "2022-12-01,17000.0", // 2022 price
        "2023-06-30,30500.0"  // Mid 2023 price
    };
    
    createTestFile("test_data.csv", lines);
}

// Run a single test case and capture output
void runTest(const TestCase& test, BitcoinExchange& exchange) {
    std::cout << "\n=== Test: " << test.name << " ===" << std::endl;
    
    std::string filename = "test_" + test.name + ".txt";
    
    // Create test file if it should exist
    if (test.fileExists) {
        createTestFile(filename, test.inputLines);
        exchange.processInputFile(filename);
    } else {
        // Test with non-existent file
        exchange.processInputFile("nonexistent_file.txt");
    }
}

// Run all tests
void runTests() {
    std::cout << "=== Running Bitcoin Exchange Tests ===" << std::endl;
    
    // Create a sample database for testing
    createSampleDatabase();
    
    // Initialize exchange with test database
    BitcoinExchange exchange("test_data.csv");
    
    // Define all test cases
    std::vector<TestCase> testCases = {
        // Test Case 1: Valid Input Cases
        {
            "valid_input",
            {
                "date | value",
                "2020-01-02 | 8",
                "2019-12-12 | 3.3",
                "2019-01-01 | 0",
                "2019-05-15 | 1000"
            },
            true
        },
        
        // Test Case 2: Invalid Date Format Cases
        {
            "invalid_date_format",
            {
                "date | value",
                "20-01-02 | 8",        // Year too short
                "201-01-02 | 8",       // Year too short
                "2020-1-02 | 8",       // Month not two digits
                "2020-01-2 | 8",       // Day not two digits
                "01-02-2020 | 8",      // Wrong date format (MM-DD-YYYY)
                "2020/01/02 | 8",      // Wrong separator
                "2020.01.02 | 8",      // Wrong separator
                "January 2, 2020 | 8"  // Text date format
            },
            true
        },
        
        // Test Case 3: Invalid Date Value Cases
        {
            "invalid_date_value",
            {
                "date | value",
                "2020-00-02 | 8",      // Month = 0
                "2020-13-02 | 8",      // Month > 12
                "2020-01-00 | 8",      // Day = 0
                "2020-01-32 | 8",      // Day > 31
                "2020-04-31 | 8",      // Invalid day for April (30 days)
                "2020-02-30 | 8",      // Invalid day for February
                "2019-02-29 | 8",      // Invalid February 29 on non-leap year
                "2020-02-29 | 8",      // Valid February 29 on leap year
                "9999-12-31 | 8",      // Far future date
                "1800-01-01 | 8"       // Very old date
            },
            true
        },
        
        // Test Case 4: Invalid Value Cases
        {
            "invalid_value",
            {
                "date | value",
                "2020-01-02 | -0.1",    // Negative value
                "2020-01-02 | -10",     // Negative value
                "2020-01-02 | 1001",    // Value > 1000
                "2020-01-02 | 1000.1",  // Value > 1000
                "2020-01-02 | text",    // Non-numeric value
                "2020-01-02 | 1,000",   // Comma separator
                "2020-01-02 | 1.2.3",   // Multiple decimal points
                "2020-01-02 | "         // Missing value
            },
            true
        },
        
        // Test Case 5: Invalid Format Cases
        {
            "invalid_format",
            {
                "date | value",
                "date | value | extra", // Extra field
                "date  value",          // Missing separator
                "date - value",         // Wrong separator
                "date* value",          // Wrong separator
                "date|value",           // Missing spaces around separator
                "|value",               // Missing date
                "date|",                // Missing value
                "|",                    // Empty line
                ""                      // Empty line
            },
            true
        },
        
        // Test Case 6: Edge Cases for Date Lookup
        {
            "date_lookup_edge",
            {
                "date | value",
                "1900-01-01 | 5",       // Date before any in database
                "2100-01-01 | 5",       // Date after any in database
                "2009-01-02 | 5",       // Exact first date in DB
                "2023-06-30 | 5"        // Exact last date in DB
            },
            true
        },
        
        // Test Case 7: File I/O Cases - Empty file
        {
            "empty_file",
            { },
            true
        },
        
        // Test Case 8: File I/O Cases - Only header
        {
            "only_header",
            { "date | value" },
            true
        },
        
        // Test Case 9: File I/O Cases - Non-existent file
        {
            "nonexistent_file",
            { },
            false
        }
    };
    
    // Run all test cases
    for (const TestCase& test : testCases) {
        runTest(test, exchange);
    }
    
    std::cout << "\n=== Tests Complete ===" << std::endl;
}

int main() {
    runTests();
    return 0;
}
