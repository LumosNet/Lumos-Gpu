#include "mse_layer_gpu.h"

void forward_mse_layer_gpu(Layer l, int num)
{
    float output_cpu[l.outputs*num];
    for (int i = 0; i < num; ++i){
        int offset_i = i*l.inputs;
        int offset_o = i*l.outputs;
        int offset_t = i*l.group;
        float *input = l.input+offset_i;
        float *output = l.output+offset_o;
        float *truth = l.truth+offset_t;
        matrix_subtract_gpu(truth, input, l.inputs, l.workspace);
        gemm_gpu(1, 0, l.input_h, l.input_w, l.input_h, l.input_w, 1, \
            l.workspace, l.workspace, output);
        multy_gpu(output, l.outputs, 1/(float)l.group, 1);
    }
    cudaMemcpy(output_cpu, l.output, l.outputs*num*sizeof(float), cudaMemcpyDeviceToHost);
    sum_cpu(output_cpu, l.outputs*num, l.loss);
    l.loss[0] /= num;
}

void backward_mse_layer_gpu(Layer l, float rate, int num, float *n_delta)
{
    for (int i = 0; i < num; ++i){
        int offset_i = i*l.inputs;
        int offset_t = i*l.group;
        float *input = l.input+offset_i;
        float *delta_l = l.delta+offset_i;
        float *truth = l.truth+offset_t;
        matrix_subtract_gpu(input, truth, l.inputs, delta_l);
        multy_gpu(delta_l, l.inputs, (float)2/l.group, 1);
    }
}
