//
//  main.cpp
//  parallel_code_optimized
//
//  Created by Ashrakat  on 05/03/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define q7_t     int8_t
#define q15_t     int16_t
#define q31_t     int32_t
#define q63_t     int64_t

#define MAX(A, B) ((A) > (B) ? (A) : (B))
#define MIN(A, B) ((A) < (B) ? (A) : (B))

#define NNOM_TRUNCATE
#ifndef NNOM_TRUNCATE
    #define NN_ROUND(out_shift) ((0x1 << out_shift) >> 1 )
#else
    #define NN_ROUND(out_shift) 0
#endif

#ifndef __SSAT
static inline int __SSAT(int32_t value, int32_t bit) {
    cout << "value = "<< value << endl;
         
    int32_t min = -(1<<(bit-1));
    int32_t max = (1<<(bit-1)) - 1;
    cout << "min = " <<min <<endl;
    cout << "max = " <<max << endl;
    if (value < min)
        return min;
    else if (value > max)
        return max;
    else
        return value;
}
#endif

int mac (int sum, int a, int b,  int valid)
{
    int out;
    if (valid == 1)
    {
       // out = sum + (((a & 0xFF000000)>>24) * ((b & 0xFF000000)>>24));
        //cout << ((a & 0xFF000000)>>24) << " * " << ((b & 0xFF000000)>>24) << endl;
        
        
        int8_t a1,b1;
        a1 = (a & 0x000000FF) ;
        b1 = (b & 0x000000FF);


        out = sum + a1 * b1;

 
        cout << signed (a1 )<< " * " << signed(b1) << endl;

    }
    else if ( valid == 2)
    {
        /*
        out = sum + (((a & 0xFF000000)>>24) * ((b & 0xFF000000)>>24));
        out += (((a & 0x00FF0000)>>16) * ((b & 0x00FF0000)>>16));
        cout << ((a & 0xFF000000)>>24) << " * " << ((b & 0xFF000000)>>24) << endl;
        cout  << ((a & 0x00FF0000)>>16) << " * " <<((b & 0x00FF0000)>>16) << endl;
        */
        
        int8_t a1,a2,b1,b2;
        a2 = ((a & 0x0000FF00)>>8);
        b2 = ((b & 0x0000FF00)>>8);
        a1 = (a & 0x000000FF) ;
        b1 = (b & 0x000000FF);
        //cout << "sum before = " << sum << endl;
        out = sum + a1 * b1;
        out += a2 * b2;
       
        
        cout << signed (a1 )<< " * " << signed(b1) << endl;
        cout << signed (a2) << " * " << signed ( b2) << endl;
       // cout << "sum after = "  << out << endl;
        
    }
    else if ( valid == 3)
    {
        /*
        out = sum + (((a & 0xFF000000)>>24) * ((b & 0xFF000000)>>24));
        out += (((a & 0x00FF0000)>>16) * ((b & 0x00FF0000)>>16));
        out += (((a & 0x0000FF00)>>8) * ((b & 0x0000FF00)>>8));
        cout << ((a & 0xFF000000)>>24) << " * " << ((b & 0xFF000000)>>24) << endl;
        cout  << ((a & 0x00FF0000)>>16) << " * " <<((b & 0x00FF0000)>>16) << endl;
        cout  << ((a & 0x0000FF00)>>8) << " * " <<((b & 0x0000FF00)>>8) << endl;
     */
        int8_t a1,a2,a3,b1,b2,b3;
        a3 = ((a & 0x00FF0000)>>16);
        b3 = ((b & 0x00FF0000)>>16);
        a2 = ((a & 0x0000FF00)>>8);
        b2 = ((b & 0x0000FF00)>>8);
        a1 = (a & 0x000000FF) ;
        b1 = (b & 0x000000FF);
        out = sum + a1 * b1;
        out += a2 * b2;
        out += a3 * b3;
        cout << signed (a1 )<< " * " << signed(b1) << endl;;
        cout << signed (a2) << " * " << signed ( b2) << endl;;
        cout << signed (a3) << " * " <<signed ( b3) << endl;
        
    }
    else if ( valid == 4)
    {
        int8_t a1,a2,a3,a4,b1,b2,b3,b4;
        a4 = ((a & 0xFF000000)>>24);
        b4 = ((b & 0xFF000000)>>24);
        a3 = ((a & 0x00FF0000)>>16);
        b3 = ((b & 0x00FF0000)>>16);
        a2 = ((a & 0x0000FF00)>>8);
        b2 = ((b & 0x0000FF00)>>8);
        a1 = (a & 0x000000FF) ;
        b1 = (b & 0x000000FF);
        out = sum + a1 * b1;
        out += a2 * b2;
        out += a3 * b3;
        out += a4 * b4;
        cout << signed (a1 )<< " * " << signed(b1) << endl;;
        cout << signed (a2) << " * " << signed ( b2) << endl;;
        cout << signed (a3) << " * " <<signed ( b3) << endl;
        cout << signed (a4) << " * " << signed (b4) << endl;
        /*out = sum + (((a & 0xFF000000)>>24) * ((b & 0xFF000000)>>24));
        out += (((a & 0x00FF0000)>>16) * ((b & 0x00FF0000)>>16));
        out += (((a & 0x0000FF00)>>8) * ((b & 0x0000FF00)>>8));
        out = ((a & 0x000000FF) * (b & 0x000000FF));
        cout << signed ((a & 0xFF000000)>>24) << " * " << signed((b & 0xFF000000)>>24) << endl;
        cout  << signed ((a & 0x00FF0000)>>16) << " * " << signed ((b & 0x00FF0000)>>16) << endl;
        cout  << signed ((a & 0x0000FF00)>>8) << " * " << signed ((b & 0x0000FF00)>>8) << endl;
        cout << signed (a & 0x000000FF) << " * " << signed(b & 0x000000FF) << endl;
     */
        
    }
    else
    {
        cout << " valid = " << valid<<endl;
    }
    
    
    return out;
}
void parallel_four_mac (int A, int B, int C, int D, int E, uint8_t valid, int *conv_out, int* conv_out2, int* conv_out3, int* conv_out4 )
{
    conv_out[0] = mac( conv_out[0], A, B, valid);
    cout << " conv_out = " << conv_out[0] << endl;
    conv_out2[0] = mac(conv_out2[0], A, C, valid);
    cout << " conv_out2 = " << conv_out2[0] << endl;
    conv_out3[0] = mac(conv_out3[0], A, D, valid);
    cout << " conv_out3 = " << conv_out3[0] << endl;
    conv_out4[0] = mac(conv_out4[0], A, E, valid);
    cout << " conv_out4 = " << conv_out4[0] << endl;
}


void local_convolve_HWC_q7_nonsquare(const q7_t *Im_in,                // input image
    const uint16_t dim_im_in_x,                                        // input image dimention x
    const uint16_t dim_im_in_y,                                        // input image dimention y
    const uint16_t ch_im_in,                                           // number of input image channels
    const q7_t *wt,                                                    // kernel weights
    const uint16_t ch_im_out,                                          // number of filters, i.e., output image channels
    const uint16_t dim_kernel_x,                                       // filter kernel size x
    const uint16_t dim_kernel_y,                                       // filter kernel size y
    const uint16_t padding_x,                                          // padding sizes x
    const uint16_t padding_y,                                          // padding sizes y
    const uint16_t stride_x,                                           // stride x
    const uint16_t stride_y,                                           // stride y
    const uint16_t dilation_x,                                         // dilation x
    const uint16_t dilation_y,                                         // dilation y
    const q7_t *bias,                                                  // bias
   // const nnom_qformat_param_t *bias_shift,                                        // bias shifts
    //const nnom_qformat_param_t *out_shift,                                         // output shift
   // const nnom_qtype_t q_type,                                         // per channel or per tensor
    q7_t *Im_out,                                                      // output image
    const uint16_t dim_im_out_x,                                       // output image dimension x
    const uint16_t dim_im_out_y,                                       // output image dimension y
    q15_t *bufferA,                                                    //buffer space for input
    q7_t *bufferB                                                      //buffer space for output
)
{
    int i, j, k, l, m, n;
    int conv_out, conv_out2, conv_out3, conv_out4;
    int in_row, in_col;
    int in_pix_loc, wt_loc;
    int shift_idx, shift_steps;
    shift_steps = 0;
   /* if(q_type == NNOM_QTYPE_PER_AXIS)
        shift_steps = 1;
    else
        shift_steps = 0;
*/
  for (i = 0; i < ch_im_out/4; i++)
    {
        cout << "I am inside first loop" << endl;
        for (j = 0; j < dim_im_out_y; j++)
        {
            int32_t base_idx_y = stride_y * j - padding_y;
            for (k = 0; k < dim_im_out_x; k++)
            {
                int32_t base_idx_x = stride_x * k - padding_x;
                int32_t ker_y_start = MAX(0, -(base_idx_y-(dilation_y-1))/dilation_y);
                int32_t ker_x_start = MAX(0, -(base_idx_x-(dilation_x-1))/dilation_x);
                int32_t ker_y_end = MIN(dim_kernel_y, (dim_im_in_y - base_idx_y + (dilation_y-1))/dilation_y);
                int32_t ker_x_end = MIN(dim_kernel_x, (dim_im_in_x - base_idx_x + (dilation_x-1))/dilation_x);
                conv_out = bias[4*i];
                conv_out2 = bias [4*i +1];
                conv_out3 = bias [4*i +2];
                conv_out4 =  bias [4*i +3];

                
                for (m = ker_y_start; m < ker_y_end; m++)
                {
                    in_row = stride_y * j + m * dilation_y - padding_y;
                    in_col = stride_x * k + ker_x_start   - padding_x;
                    //cout << "ker x_start = " << ker_x_start << endl;
                    //cout << "ker x_end = " << ker_x_end << endl;
                    int max = ((ker_x_end-ker_x_start ) * ch_im_in);
                    in_pix_loc =  (in_row * dim_im_in_x + in_col) * ch_im_in ;
                    wt_loc = 4*i * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                    int w2_index = (4*i +1) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                    int w3_index = (4*i +2) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                    int w4_index = (4*i +3) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                    
                    
                    int A = *(int *)(Im_in + in_pix_loc );
                    int B = *(int *) (wt + wt_loc);
                    int C = *(int *) (wt + w2_index);
                    int D = *(int *) (wt + w3_index);
                    int E = *(int *) (wt + w4_index);
                    //cout << "conv_out = " << conv_out << endl;
                   // conv_out = mac( conv_out, A, B, 4);
                    parallel_four_mac (A, B, C, D, E, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                    for (int x = 1; x <  max/4 ; x++)
                    {


                        // pre-calculate the pixel location and weight location to improve the performance.


                        in_pix_loc =  in_pix_loc + 4;
                        wt_loc = wt_loc + 4;
                        w2_index = w2_index + 4;
                        w3_index = w3_index + 4;
                        w4_index = w4_index + 4;
                        
                       // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                        
                        //conv_out += Im_in[in_pix_loc] * wt[wt_loc];
                        
                        int A = *(int *)(Im_in + in_pix_loc );
                        int B = *(int *) (wt + wt_loc);
                        int C = *(int *) (wt + w2_index);
                        int D = *(int *) (wt + w3_index);
                        int E = *(int *) (wt + w4_index);
                        //cout << "conv_out = " << conv_out << endl;
                       // conv_out = mac( conv_out, A, B, 4);
                        
                        parallel_four_mac (A, B, C, D, E, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                       
                    }
                    int r = max & 0x03;
                    if ( r > 0)
                    {
                        //cout << "r = " << r << endl;
                        in_pix_loc =  in_pix_loc + 4;
                         wt_loc = wt_loc + 4;
                        w2_index = w2_index + 4;
                        w3_index = w3_index + 4;
                        w4_index = w4_index + 4;
                    
                        // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                         
                        int A = *(int *)(Im_in + in_pix_loc );
                        int B = *(int *) (wt + wt_loc);
                        int C = *(int *) (wt + w2_index);
                        int D = *(int *) (wt + w3_index);
                        int E = *(int *) (wt + w4_index);
                      //  cout << "conv_out = " << conv_out << endl;
                        //conv_out = mac( conv_out, A, B, r);
                        //cout << "conv_out = " << conv_out << endl;
                        parallel_four_mac (A, B, C, D, E, r, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                    }
                
                   
                }

                Im_out[4*i + (j * dim_im_out_x + k) * ch_im_out] = conv_out;
                Im_out[(4*i+1) + (j * dim_im_out_x + k) * ch_im_out] = conv_out2;
                Im_out[(4*i+2) + (j * dim_im_out_x + k) * ch_im_out] = conv_out3;
                Im_out[(4*i+3) + (j * dim_im_out_x + k) * ch_im_out] = conv_out4;

               // cout << "Im_out [ " <<(4*i) + (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out << endl;
               // cout << "Im_out [ " <<(4*i + 1) + (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out2 << endl;
                //cout << "Im_out [ " <<(4*i + 2) + (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out3 << endl;
                //cout << "Im_out [ " <<(4*i + 3) + (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out4 << endl;




            }
        }
    }
  
    int r = ch_im_out & 0x03;
    if ( r > 0)
    {
        cout << "OOPPPS" << endl;
        if ( r == 1)
        {
            for (j = 0; j < dim_im_out_y; j++)
            {
                int32_t base_idx_y = stride_y * j - padding_y;
                for (k = 0; k < dim_im_out_x; k++)
                {
                    int32_t base_idx_x = stride_x * k - padding_x;
                    int32_t ker_y_start = MAX(0, -(base_idx_y-(dilation_y-1))/dilation_y);
                    int32_t ker_x_start = MAX(0, -(base_idx_x-(dilation_x-1))/dilation_x);
                    int32_t ker_y_end = MIN(dim_kernel_y, (dim_im_in_y - base_idx_y + (dilation_y-1))/dilation_y);
                    int32_t ker_x_end = MIN(dim_kernel_x, (dim_im_in_x - base_idx_x + (dilation_x-1))/dilation_x);
                    conv_out = bias[ch_im_out -1];
                    conv_out2 = 0;
                    conv_out3 = 0;
                    conv_out4 = 0;

                    
                    for (m = ker_y_start; m < ker_y_end; m++)
                    {
                        in_row = stride_y * j + m * dilation_y - padding_y;
                        in_col = stride_x * k + ker_x_start   - padding_x;
                        //cout << "ker x_start = " << ker_x_start << endl;
                        //cout << "ker x_end = " << ker_x_end << endl;
                        int max = ((ker_x_end-ker_x_start ) * ch_im_in);
                        in_pix_loc =  (in_row * dim_im_in_x + in_col) * ch_im_in ;
                        wt_loc = (ch_im_out-1)* ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                       // int w2_index = (4*i +1) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                       // int w3_index = (4*i +2) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                       // int w4_index = (4*i +3) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        
                        
                        int A = *(int *)(Im_in + in_pix_loc );
                        int B = *(int *) (wt + wt_loc);
                        //int C = *(int *) (wt + w2_index);
                        //int D = *(int *) (wt + w3_index);
                        //int E = *(int *) (wt + w4_index);
                        //cout << "conv_out = " << conv_out << endl;
                       // conv_out = mac( conv_out, A, B, 4);
                        parallel_four_mac (A, B,0, 0, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        for (int x = 1; x <  max/4 ; x++)
                        {


                            // pre-calculate the pixel location and weight location to improve the performance.


                            in_pix_loc =  in_pix_loc + 4;
                            wt_loc = wt_loc + 4;
                       
                           // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                            
                            //conv_out += Im_in[in_pix_loc] * wt[wt_loc];
                            
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                           // int C = *(int *) (wt + w2_index);
                           // int D = *(int *) (wt + w3_index);
                            //int E = *(int *) (wt + w4_index);
                            //cout << "conv_out = " << conv_out << endl;
                           // conv_out = mac( conv_out, A, B, 4);
                            
                            parallel_four_mac (A, B, 0, 0, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                           
                        }
                        int v = max & 0x03;
                        if ( v > 0)
                        {
                            //cout << "r = " << r << endl;
                            in_pix_loc =  in_pix_loc + 4;
                             wt_loc = wt_loc + 4;
                        
                            // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                             
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                            
                          //  cout << "conv_out = " << conv_out << endl;
                            //conv_out = mac( conv_out, A, B, r);
                            //cout << "conv_out = " << conv_out << endl;
                            parallel_four_mac (A, B, 0, 0, 0, v, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        }
                    
                       
                    }

                    Im_out[(ch_im_out-1) + (j * dim_im_out_x + k) * ch_im_out] = conv_out;
                   // cout << "Im_out [ " << (ch_im_out-1) + (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out << endl;

                }
            }
        }
        else if ( r == 2)
        {
            cout << " r = 2" << endl;
            for (j = 0; j < dim_im_out_y; j++)
            {
                int32_t base_idx_y = stride_y * j - padding_y;
                for (k = 0; k < dim_im_out_x; k++)
                {
                    int32_t base_idx_x = stride_x * k - padding_x;
                    int32_t ker_y_start = MAX(0, -(base_idx_y-(dilation_y-1))/dilation_y);
                    int32_t ker_x_start = MAX(0, -(base_idx_x-(dilation_x-1))/dilation_x);
                    int32_t ker_y_end = MIN(dim_kernel_y, (dim_im_in_y - base_idx_y + (dilation_y-1))/dilation_y);
                    int32_t ker_x_end = MIN(dim_kernel_x, (dim_im_in_x - base_idx_x + (dilation_x-1))/dilation_x);
                    conv_out = bias[ch_im_out -2];
                    conv_out2 = bias[ch_im_out -1];
                    conv_out3 = 0;
                    conv_out4 = 0;

                    
                    for (m = ker_y_start; m < ker_y_end; m++)
                    {
                        in_row = stride_y * j + m * dilation_y - padding_y;
                        in_col = stride_x * k + ker_x_start   - padding_x;
                        //cout << "ker x_start = " << ker_x_start << endl;
                        //cout << "ker x_end = " << ker_x_end << endl;
                        int max = ((ker_x_end-ker_x_start ) * ch_im_in);
                        in_pix_loc =  (in_row * dim_im_in_x + in_col) * ch_im_in ;
                        wt_loc = (ch_im_out-2) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        int w2_index = (ch_im_out-1) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                       // int w3_index = (4*i +2) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        //int w4_index = (4*i +3) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        
                        
                        int A = *(int *)(Im_in + in_pix_loc );
                        int B = *(int *) (wt + wt_loc);
                        int C = *(int *) (wt + w2_index);
                        //int D = *(int *) (wt + w3_index);
                       // int E = *(int *) (wt + w4_index);
                        //cout << "conv_out = " << conv_out << endl;
                       // conv_out = mac( conv_out, A, B, 4);
                        parallel_four_mac (A, B, C, 0, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        for (int x = 1; x <  max/4 ; x++)
                        {


                            // pre-calculate the pixel location and weight location to improve the performance.


                            in_pix_loc =  in_pix_loc + 4;
                            wt_loc = wt_loc + 4;
                            w2_index = w2_index + 4;
                            //w3_index = w3_index + 4;
                            //w4_index = w4_index + 4;
                       
                           // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                            
                            //conv_out += Im_in[in_pix_loc] * wt[wt_loc];
                            
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                            int C = *(int *) (wt + w2_index);
                            //int D = *(int *) (wt + w3_index);
                            //int E = *(int *) (wt + w4_index);
                            //cout << "conv_out = " << conv_out << endl;
                           // conv_out = mac( conv_out, A, B, 4);
                            
                            parallel_four_mac (A, B, C, 0, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                           
                        }
                        int v = max & 0x03;
                        if ( v > 0)
                        {
                            //cout << "r = " << r << endl;
                            in_pix_loc =  in_pix_loc + 4;
                             wt_loc = wt_loc + 4;
                            w2_index = w2_index + 4;
                        
                            // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                             
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                            int C = *(int *) (wt + w2_index);
                            //int D = *(int *) (wt + w3_index);
                            //int E = *(int *) (wt + w4_index);
                          //  cout << "conv_out = " << conv_out << endl;
                            //conv_out = mac( conv_out, A, B, r);
                            //cout << "conv_out = " << conv_out << endl;
                            parallel_four_mac (A, B, C, 0, 0, v, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        }
                    
                       
                    }

                  
                    Im_out[(ch_im_out-2) + (j * dim_im_out_x + k) * ch_im_out] = conv_out;
                    Im_out[(ch_im_out-1) + (j * dim_im_out_x + k) * ch_im_out]= conv_out2;
                   // cout << "Im_out [ " << (ch_im_out-2)+ (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out << endl;
                    //cout << "Im_out [ " << (ch_im_out-1)+ (j * dim_im_out_x + k) * ch_im_out << "] = " << conv_out2<< endl;

                }
            }
        }
        else if (r == 3)
        {
            for (j = 0; j < dim_im_out_y; j++)
            {
                int32_t base_idx_y = stride_y * j - padding_y;
                for (k = 0; k < dim_im_out_x; k++)
                {
                    int32_t base_idx_x = stride_x * k - padding_x;
                    int32_t ker_y_start = MAX(0, -(base_idx_y-(dilation_y-1))/dilation_y);
                    int32_t ker_x_start = MAX(0, -(base_idx_x-(dilation_x-1))/dilation_x);
                    int32_t ker_y_end = MIN(dim_kernel_y, (dim_im_in_y - base_idx_y + (dilation_y-1))/dilation_y);
                    int32_t ker_x_end = MIN(dim_kernel_x, (dim_im_in_x - base_idx_x + (dilation_x-1))/dilation_x);
                    conv_out = bias[ch_im_out -3];
                    conv_out2 = bias[ch_im_out -2];
                    conv_out3 = bias[ch_im_out -1];
                    conv_out4 = 0;

                    
                    for (m = ker_y_start; m < ker_y_end; m++)
                    {
                        in_row = stride_y * j + m * dilation_y - padding_y;
                        in_col = stride_x * k + ker_x_start   - padding_x;
                        //cout << "ker x_start = " << ker_x_start << endl;
                        //cout << "ker x_end = " << ker_x_end << endl;
                        int max = ((ker_x_end-ker_x_start ) * ch_im_in);
                        in_pix_loc =  (in_row * dim_im_in_x + in_col) * ch_im_in ;
                        wt_loc =(ch_im_out-3)* ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        int w2_index = (ch_im_out-2) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        int w3_index = (ch_im_out-1) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                       // int w4_index = (4*i +3) * ch_im_in * dim_kernel_y * dim_kernel_x + (m * dim_kernel_x + ker_x_start) * ch_im_in;
                        
                        
                        int A = *(int *)(Im_in + in_pix_loc );
                        int B = *(int *) (wt + wt_loc);
                        int C = *(int *) (wt + w2_index);
                        int D = *(int *) (wt + w3_index);
                        //int E = *(int *) (wt + w4_index);
                        //cout << "conv_out = " << conv_out << endl;
                       // conv_out = mac( conv_out, A, B, 4);
                        parallel_four_mac (A, B, C, D, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        for (int x = 1; x <  max/4 ; x++)
                        {


                            // pre-calculate the pixel location and weight location to improve the performance.


                            in_pix_loc =  in_pix_loc + 4;
                            wt_loc = wt_loc + 4;
                            w2_index = w2_index + 4;
                            w3_index = w3_index + 4;
                            //w4_index = w4_index + 4;
                       
                           // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                            
                            //conv_out += Im_in[in_pix_loc] * wt[wt_loc];
                            
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                            int C = *(int *) (wt + w2_index);
                            int D = *(int *) (wt + w3_index);
                           // int E = *(int *) (wt + w4_index);
                            //cout << "conv_out = " << conv_out << endl;
                           // conv_out = mac( conv_out, A, B, 4);
                            
                            parallel_four_mac (A, B, C, D, 0, 4, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                           
                        }
                        int v = max & 0x03;
                        if ( v > 0)
                        {
                            //cout << "r = " << r << endl;
                            in_pix_loc =  in_pix_loc + 4;
                             wt_loc = wt_loc + 4;
                            w2_index = w2_index + 4;
                            w3_index = w3_index + 4;
                           // w4_index = w4_index + 4;
                        
                            // cout << "Im[ " << in_pix_loc << "] * wt[" << wt_loc << endl;
                             
                            int A = *(int *)(Im_in + in_pix_loc );
                            int B = *(int *) (wt + wt_loc);
                            int C = *(int *) (wt + w2_index);
                            int D = *(int *) (wt + w3_index);
                           // int E = *(int *) (wt + w4_index);
                          //  cout << "conv_out = " << conv_out << endl;
                            //conv_out = mac( conv_out, A, B, r);
                            //cout << "conv_out = " << conv_out << endl;
                            parallel_four_mac (A, B, C, D, 0, v, &conv_out, &conv_out2, &conv_out3, &conv_out4);
                        }
                    
                       
                    }

                    Im_out[(ch_im_out-3) + (j * dim_im_out_x + k) * ch_im_out] = conv_out;
                    Im_out[(ch_im_out-2) + (j * dim_im_out_x + k) * ch_im_out] = conv_out2;
                    Im_out[(ch_im_out-1) + (j * dim_im_out_x + k) * ch_im_out] = conv_out3;
                    //cout << " Im_out[ " << (ch_im_out-3) + (j * dim_im_out_x + k) * ch_im_out << "] = " << signed (conv_out) << endl;
                    //cout << " Im_out[ " << (ch_im_out-2) + (j * dim_im_out_x + k) * ch_im_out << "] = " << signed (conv_out2) << endl;
                    //cout << " Im_out[ " << (ch_im_out-1) + (j * dim_im_out_x + k) * ch_im_out << "] = " << signed (conv_out3) << endl;

                }
            }
        }
    }

}
int main()
{
    //printf("Hello World");
    const q7_t Im_in[75] = { 2,1,0,
                             1,0,0,
                             1,2,0,
                             2,2,2,
                             2,1,0,

                             1,2,1,
                             2,2,1,
                             2,1,2,
                             2,1,2,
                             1,0,1,

                             0,0,1,
                             2,2,1,
                             2,1,1,
                             1,0,2,
                             0,2,1,

                             1,0,1,
                             0,1,0,
                             1,2,1,
                             2,2,2,
                             0,2,0,

                             0,1,0,
                             1,1,2,
                             1,2,0,
                             0,2,2,
                             1,2,2
                           };


        
        
        
        /*
                         2,1,1,2,2,
                         1,2,2,2,1,
                         0,2,2,1,0,
                         1,0,1,2,0,
                         0,1,1,0,1,
        
                         1,0,2,2,1,
                         2,2,1,1,0,
                         0,2,1,0,2,
                         0,1,2,2,2,
                         1,1,2,2,2,
                         
                         0,0,0,2,0,
                         1,1,2,2,1,
                         1,1,1,2,1,
                         1,0,1,2,0,
                         0,2,0,2,2
    */
    const uint16_t dim_im_in_x = 5;
    const uint16_t dim_im_in_y = 5;
    const uint16_t ch_im_in = 3;
    const q7_t wt[108] = {
                          1,0,1,
                          0,0,-1,
                          -1,1,0,

                          0,0,-1,
                          0,-1,-1,
                          1,-1,-1,

                          1,1,1,
                          1,0,-1,
                          0,-1,-1,

                          0,-1,0,
                          0,-1,0,
                          1,-1,-1,

                          -1,0,-1,
                          -1,0,-1,
                          1,-1,1,

                          -1, -1, 0,
                          1, 1, -1,
                          -1, -1, 1,
        
                        1,0,1,
                        0,0,-1,
                        -1,1,0,

                        0,0,-1,
                        0,-1,-1,
                        1,-1,-1,

                        1,1,1,
                        1,0,-1,
                        0,-1,-1,

                        0,-1,0,
                        0,-1,0,
                        1,-1,-1,

                        -1,0,-1,
                        -1,0,-1,
                        1,-1,1,

                        -1, -1, 0,
                        1, 1, -1,
                        -1, -1, 1,
            
    };

        
     /*
        
        
                        1,0,-1,
                         0,0,1,
                         1,1,0,
                      
                      0,0,1,
                      0,-1,-1,
                      1,0,-1,
                      
                      1,-1,0,
                      -1,-1,-1,
                      1,-1,-1,
                      
                      0,0,1,
                      -1,-1,1,
                      -1,1,-1,
                      
                      -1,-1,-1,
                      0,0,-1,
                      -1,1,-1,
                      
                      0,0,-1,
                      -1,-1,1,
                      0,-1,1
     */
                      
     const uint16_t ch_im_out = 4;
    const uint16_t dim_kernel_x = 3;
    const uint16_t dim_kernel_y =3;
    const uint16_t padding_x =1;
    const uint16_t padding_y = 1;
    const uint16_t stride_x = 2;
    const uint16_t stride_y = 2;
    const q7_t bias[4] = {1,0,0,0};
    const uint16_t bias_shift = 0;
    const uint16_t out_shift =0;
   
    const uint16_t dim_im_out_x = 3;
    const uint16_t dim_im_out_y = 3;
    q7_t Im_out [ dim_im_out_x * dim_im_out_y *ch_im_out];
    q15_t *bufferA;
    q7_t *bufferB;

    const uint16_t dilation_x =1;
    const uint16_t dilation_y =1;



    local_convolve_HWC_q7_nonsquare(Im_in, dim_im_in_x, dim_im_in_y, ch_im_in, wt, ch_im_out, dim_kernel_x, dim_kernel_y, padding_x, padding_y, stride_x, stride_y, dilation_x, dilation_y, bias, Im_out, dim_im_out_y, dim_im_out_y, bufferA, bufferB);
    //int n = dim_im_out_x * dim_im_out_y *ch_im_out;
    int n = dim_im_out_x * dim_im_out_y *ch_im_out;
    for (int i =0; i < n ; i++)
    
    {
        cout << signed(Im_out [i])<<endl;
    }

    return 0;
}

