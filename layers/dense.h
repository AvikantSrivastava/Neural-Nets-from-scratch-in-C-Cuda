#include <iostream>

class dense
{
public:
    int input_size;
    int output_size;

    float *weights = NULL;
    float *bias = NULL;

    void set_weights(int input_size, int output_size)
    {
        weights = new float[output_size * input_size];

        for (int n = 0; n < output_size; n++)
            for (int m = 0; m < input_size; m++)
            {
                this->weights[n * input_size + m] = rand() / float(1) * 24.f + 1.f;
            }
    }

    void set_bias(int input_size, int output_size)
    {
        this->bias = new float[output_size];

        for (int n = 0; n < output_size; n++)
            bias[n] = rand() / float(1) * 24.f + 1.f;
    }

    dense(int input_size, int output_size)
    {
        this->input_size = input_size;
        this->output_size = output_size;

        set_weights(input_size, output_size);
    }
};