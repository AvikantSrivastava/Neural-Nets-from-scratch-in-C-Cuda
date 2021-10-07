#include<iostream>
#include<vector>
#include <stdexcept>
#include "layers/dense.h"

class Network
{
    private:
        int n_layers;
        std::vector<dense*> network;

        


    public:
        Network() {
                n_layers = 0;
            }

        int number_of_layers(){
            return n_layers;
        }

        void add_layer(dense* dense_layer){
            if(network.empty()){
                network.push_back(dense_layer);
                return;
            }

            if(network.back()->output_size != dense_layer->input_size){
                throw std::invalid_argument("invalid layer size");
                return;
            }

            network.push_back(dense_layer);
        }
};