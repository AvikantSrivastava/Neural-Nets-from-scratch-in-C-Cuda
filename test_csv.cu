#include "helper/csv.h"

int main()
{
    csv file("Datasets/iris.csv");
    
    file.get_details();

    return 0;
}
