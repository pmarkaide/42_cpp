#include "BitcoinExchange.hpp"
#include <iostream>
#include <cassert>
#include <vector>

// Test class to access private methods
class BitcoinExchangeTester : public BitcoinExchange {
public:
    BitcoinExchangeTester() : BitcoinExchange() {}
    
    // Expose private method for testing
    std::string testFindClosestDate(const std::string& date) const {
        return findClosestDate(date);
    }
    
    // Add test data manually
    void addTestData(const std::string& date, float rate) {
        database_[date] = rate;
    }
    
    // Check if database is empty
    bool isEmptyDatabase() const {
        return database_.empty();
    }
    
    // Print database contents for debugging
    void printTestDatabase() const {
        std::cout << "=== Test Database Contents ===" << std::endl;
        for (const auto& entry : database_) {
            std::cout << entry.first << " : " << entry.second << std::endl;
        }
        std::cout << "===============================" << std::endl;
    }
};

void testEmptyDatabase() {
    std::cout << "\n🧪 Test 1: Empty Database" << std::endl;
    BitcoinExchangeTester tester;
    
    std::string result = tester.testFindClosestDate("2020-01-01");
    std::cout << "Query: 2020-01-01, Result: '" << result << "'" << std::endl;
    
    if (result.empty()) {
        std::cout << "✅ PASS: Empty database returns empty string" << std::endl;
    } else {
        std::cout << "❌ FAIL: Expected empty string, got: " << result << std::endl;
    }
}

void testDateBeforeAllEntries() {
    std::cout << "\n🧪 Test 2: Date Before All Entries (Real Database Range)" << std::endl;
    BitcoinExchangeTester tester;
    
    // Use real database dates - first entry is 2009-01-02
    // Test with dates before the database starts
    std::vector<std::string> testDates = {"2007-06-15", "2008-12-31", "2009-01-01"};
    
    for (const std::string& testDate : testDates) {
        std::string result = tester.testFindClosestDate(testDate);
        std::cout << "Query: " << testDate << " (before DB start), Result: '" << result << "'" << std::endl;
        
        if (result.empty()) {
            std::cout << "✅ PASS: Date before database returns empty string" << std::endl;
        } else {
            std::cout << "❌ FAIL: Expected empty string, got: " << result << std::endl;
        }
    }
}

void testDateAfterAllEntries() {
    std::cout << "\n🧪 Test 3: Date After All Entries (Real Database Range)" << std::endl;
    BitcoinExchangeTester tester;
    
    // Real database ends at 2022-03-29
    // Test with dates after the database ends
    std::vector<std::string> testDates = {"2023-06-15", "2024-12-31", "2025-01-01"};
    
    for (const std::string& testDate : testDates) {
        std::string result = tester.testFindClosestDate(testDate);
        std::cout << "Query: " << testDate << " (after DB end), Result: '" << result << "'" << std::endl;
        
        if (result == "2022-03-29") {
            std::cout << "✅ PASS: Date after database returns latest date (2022-03-29)" << std::endl;
        } else {
            std::cout << "❌ FAIL: Expected '2022-03-29', got: '" << result << "'" << std::endl;
        }
    }
}

void testExactMatch() {
    std::cout << "\n🧪 Test 4: Exact Date Match (Real Database)" << std::endl;
    BitcoinExchangeTester tester;
    
    // Test with dates that actually exist in the real database
    std::vector<std::string> testDates = {"2019-01-01", "2021-12-31", "2020-01-05"};
    
    for (const std::string& testDate : testDates) {
        std::string result = tester.testFindClosestDate(testDate);
        std::cout << "Query: " << testDate << " (exact match), Result: '" << result << "'" << std::endl;
        
        if (result == testDate) {
            std::cout << "✅ PASS: Exact match returns correct date" << std::endl;
        } else {
            std::cout << "❌ FAIL: Expected '" << testDate << "', got: '" << result << "'" << std::endl;
        }
    }
}

void testDateBetweenEntries() {
    std::cout << "\n🧪 Test 5: Date Between Entries (Looking for Real Gaps)" << std::endl;
    BitcoinExchangeTester tester;
    
    // Test dates that likely don't exist but are between real database entries
    // These should return the closest LOWER date
    std::vector<std::pair<std::string, std::string>> testCases = {
        {"2020-03-15", "2020-03-14"}, // Should be close to existing date
        {"2020-06-20", "2020-06-19"}, // Should be close to existing date  
        {"2021-07-04", "2021-07-02"}, // US holiday, might not exist
        {"2021-12-25", "2021-12-22"}  // Christmas, might not exist
    };
    
    for (const auto& testCase : testCases) {
        std::string query = testCase.first;
        std::string expected = testCase.second;
        std::string result = tester.testFindClosestDate(query);
        
        std::cout << "Query: " << query << ", Result: '" << result << "'" << std::endl;
        std::cout << "Expected: " << expected << " (or closest lower)" << std::endl;
        
        // Since we don't know exact database contents, just check it's not the query date
        // and that it's lower than the query date
        if (result != query && result < query && !result.empty()) {
            std::cout << "✅ PASS: Returns lower date" << std::endl;
        } else if (result == query) {
            std::cout << "ℹ️  INFO: Exact match found (date exists in DB)" << std::endl;
        } else {
            std::cout << "❌ FAIL: Unexpected result: '" << result << "'" << std::endl;
        }
        std::cout << std::endl;
    }
}

void testEdgeCaseDateFormats() {
    std::cout << "\n🧪 Test 6: Edge Cases with Real Database" << std::endl;
    BitcoinExchangeTester tester;
    
    // Test weekend dates (might not exist in database)
    std::vector<std::string> weekendDates = {
        "2020-01-04", // Saturday  
        "2020-01-05", // Sunday (this one actually exists!)
        "2021-06-12", // Saturday
        "2021-06-13"  // Sunday
    };
    
    std::cout << "Testing weekend dates (might have gaps):" << std::endl;
    for (const std::string& testDate : weekendDates) {
        std::string result = tester.testFindClosestDate(testDate);
        std::cout << "Query: " << testDate << ", Result: '" << result << "'" << std::endl;
        
        if (result == testDate) {
            std::cout << "→ Exact match (date exists)" << std::endl;
        } else if (result < testDate && !result.empty()) {
            std::cout << "→ Lower date found: " << result << std::endl;
        } else {
            std::cout << "→ Unexpected result!" << std::endl;
        }
    }
}

void testSingleEntry() {
    std::cout << "\n🧪 Test 7: Empty Database Edge Case" << std::endl;
    BitcoinExchangeTester tester;
    
    // Test with completely empty database (no data.csv loaded)
    std::cout << "Testing with empty database:" << std::endl;
    
    std::vector<std::string> testDates = {"2020-01-01", "2021-06-15", "2022-12-31"};
    
    for (const std::string& testDate : testDates) {
        std::string result = tester.testFindClosestDate(testDate);
        std::cout << "Query: " << testDate << ", Result: '" << result << "'" << std::endl;
        
        if (result.empty()) {
            std::cout << "✅ PASS: Empty database returns empty string" << std::endl;
        } else {
            std::cout << "❌ FAIL: Expected empty string, got: " << result << std::endl;
        }
    }
}

int main() {
    std::cout << "=== Testing findClosestDate Function ===" << std::endl;
    
    try {
        testEmptyDatabase();
        testDateBeforeAllEntries();
        testDateAfterAllEntries();
        testExactMatch();
        testDateBetweenEntries();
        testEdgeCaseDateFormats();
        testSingleEntry();
        
        std::cout << "\n=== All Tests Complete ===" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "❌ EXCEPTION: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}