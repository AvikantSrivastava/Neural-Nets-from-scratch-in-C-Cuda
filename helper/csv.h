#include <string>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <algorithm>

class csv
{
private:
    int number_of_Columns;
    int number_of_Rows = 0;
    std::string filename;
    std::vector<std::string> labels;

    int encoder(std::string label)
    {
        int encoded_value;

        if (labels.empty())
        {
            labels.push_back(label);
            return 1;
        }

        std::vector<std::string>::iterator position = std::find(labels.begin(), labels.end(), label);

        if (position == labels.end())
        {
            labels.push_back(label);
            return encoder(label);
        }
        encoded_value = (position - labels.begin());
        return encoded_value + 1;
    }

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

    std::pair<float, std::vector<float>> Line_to_Row(std::string s)

    {
        std::pair<int, std::vector<float>> result;
        std::vector<float> column_values;

        {
            std::string delimiter = ",";

            size_t pos = 0;
            std::string token;
            while ((pos = s.find(delimiter)) != std::string::npos)
            {
                token = s.substr(0, pos);
                // std::cout << token << std::endl;
                column_values.push_back(std::stof(token));

                s.erase(0, pos + delimiter.length());
            }
            // std::cout << "Encoded is : " << encoder(s) << std::endl;

            result.first = encoder(s);
            result.second = column_values;

            return result;
        }

        return result;
    }

public:
    std::vector<std::pair<float, std::vector<float>>> DATA;

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

        while (getline(datafile, line))
        {
            this->DATA.push_back(Line_to_Row(line));
            this->number_of_Rows++;
        }
    }

    void get_details()
    {

        std::cout << "Number of Cols are " << this->number_of_Columns << std::endl;
        std::cout << "Number of Rows are " << this->number_of_Rows << std::endl;

        std::cout << "LABEL"
                  << "\t"
                  << "Values" << std::endl;
        for (auto it = this->DATA.begin(); it != this->DATA.end(); ++it)
        {
            auto row = *it;
            auto label = row.first;
            auto values = row.second;
            std::cout << label << "\t";

            for (auto col = values.begin(); col != values.end(); ++col)
            {
                std::cout << *col << "\t";
            }

            std::cout << std::endl;
        }
    }
};