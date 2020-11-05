#include "helper/csv.h"

int main()
{
    // std::string filename =
    csv file("Datasets/iris.csv");
    std::cout << "Number of Cols are " << file.number_of_Columns;
    return 0;
}