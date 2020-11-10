#include "helper/csv.h"
// #include

int main()
{
    // std::string filename =
    csv file("Datasets/iris.csv");
    // std::cout << "Number of Cols are " << file.number_of_Columns;
    // std::cout << "Number of Rows are " << file.number_of_Rows;


    // Printing the CSV DATA

    std::cout << "LABEL" << "\t" << "Values" << std::endl;
    for(auto it = file.DATA.begin(); it != file.DATA.end(); ++it)
    {   
        auto row = *it;
        auto label = row.first;
        auto values = row.second;
        std::cout << label << "\t";

        for(auto col = values.begin(); col != values.end(); ++col)
        {
            std::cout << *col << "\t";
        }

        std::cout << std::endl;


    }



    return 0;
}
