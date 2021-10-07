#include "network.h"

int main(){

    Network my_neural_net;
    dense l1(5,10);
    dense l2(10,15);
    dense l3(15,2);

    my_neural_net.add_layer(&l1);
    my_neural_net.add_layer(&l2);
    my_neural_net.add_layer(&l3);
    
    return 0;
}