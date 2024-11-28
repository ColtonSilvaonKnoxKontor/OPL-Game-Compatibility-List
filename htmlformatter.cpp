#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

// Function to trim leading and trailing spaces from a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(' ');
    size_t end = str.find_last_not_of(' ');
    if (start != std::string::npos && end != std::string::npos) {
        return str.substr(start, end - start + 1);
    }
    return "";
}

// Function to split a string by a delimiter (pipe '|' in this case)
std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(trim(token));  // Trim spaces after splitting
    }
    return tokens;
}

int main() {
    std::string inputLine;
    std::vector<std::string> rows;

    std::cout << "Markdown to HTML table converter for OPL Game Compatibility List\nColton Silva 2024\nAI generated program\n\nPlease enter the table data (or paste the entire data from README file), then press Enter:" << std::endl;
    std::cout << "(Press Enter on an empty line to finish input.)\n";

    // Read multiple lines of input until the user presses Enter (empty line)
    while (std::getline(std::cin, inputLine)) {
        if (inputLine.empty()) {
            break;  // End input when the user presses Enter on an empty line
        }
        rows.push_back(inputLine);  // Add the row to the rows vector
    }

    // Start HTML output for database-style table
    std::cout << "\nGenerated HTML Table (Database Style):\n";
    std::cout << "<table border='1' cellpadding='5' cellspacing='0'>\n";

    // Create the header row (assumes first input is the header)
    if (!rows.empty()) {
        auto headerColumns = split(rows[0], '|');
        std::cout << "<tr>\n";
        for (const auto& col : headerColumns) {
            if (!col.empty()) {
                std::cout << "<th>" << col << "</th>\n";
            }
        }
        std::cout << "</tr>\n";

        // Process each data row (from the second line onward)
        for (size_t i = 1; i < rows.size(); ++i) {
            auto columns = split(rows[i], '|');
            std::cout << "<tr>\n";
            for (const auto& col : columns) {
                if (!col.empty()) {
                    std::cout << "<td>" << col << "</td>\n";
                }
            }
            std::cout << "</tr>\n";
        }
    }

    // Close the HTML table
    std::cout << "</table>\n";

    return 0;
}
