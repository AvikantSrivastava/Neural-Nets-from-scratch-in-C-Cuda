#include <string>
#include <iostream>
#include <fstream>

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

    csv(std::string filename)
    {
        this->filename = filename;

        // Printing the csv filename
        std::cout
            << "The filename is : " << this->filename << std::endl;

        // Reading the CSV file using std::ifstream
        std::ifstream datafile(this->filename);

        // Reading the title line(First line) of CSV file
        std::string title_line;
        getline(datafile, title_line);
        // std ::cout << "First line is : " << title_line << std::endl;

        // Setting number of Columns
        this->number_of_Columns = get_number_of_Columns(title_line);
        // std ::cout << "Number of columns eare : " << this->number_of_Columns << std::endl;
    }
};