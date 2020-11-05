#include <string>
#include <iostream>
#include <fstream>
#include <variant>
#include <cassert>
#include <vector>

class csv
{
public:
    int number_of_Columns;
    int number_of_Rows;
    std::string filename;

    int get_number_of_Columns(std::string line)
    {
        int count = 0;

        for (int i = 0; i < line.size(); i++)
            if (line[i] == ',')
                count++;

        return count++;
    }

    bool is_number(const std::string &s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }

    std::variant<float, std::string> Line_to_Row(std::string s)

    {
        std::variant<float, std::string> result;

        {
            std::string delimiter = ",";

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos)
            {
                token = s.substr(0, pos);
                std::cout << token << std::endl;
                // result.push_back(is_number(token) ? (float)token : token);

                s.erase(0, pos + delimiter.length());
            }
            std::cout << s << std::endl;
            // result.push_back(6.66);
            return result;
        }

        return result;
    }

    csv(std::string filename)
    {
        this->filename = filename;

        // Printing the csv filename
        std::cout
            << "The filename is : " << this->filename << std::endl;

        // Reading the CSV file using std::ifstream
        std::ifstream datafile(this->filename);

        // Reading the title line(First line) of CSV file
        std::string title_line, line;
        getline(datafile, title_line);
        // std ::cout << "First line is : " << title_line << std::endl;

        // Setting number of Columns
        this->number_of_Columns = get_number_of_Columns(title_line);
        // std ::cout << "Number of columns eare : " << this->number_of_Columns << std::endl;

        std::vector<std::variant<float, std::string>> DATA;
        while (getline(datafile, line))
        {

            // std::cout << title_line << std::endl;
            DATA.push_back(Line_to_Row(line));
        }
    }
};