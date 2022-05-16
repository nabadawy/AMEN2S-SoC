`timescale 1ns / 1ps

module Register #(parameter n = 64)(
input clk,
input rst,
input load,
input [n-1:0] in,
output [n-1:0] Q
    );

genvar i;
wire [n-1:0] D;
generate
for(i = 0; i < n; i = i+1)begin: myblock
    mux_2x1 mux( load, Q[i], in[i],  D[i]);
    DFlipFlop FF( clk,  rst,  D[i],  Q[i]);
end
endgenerate

endmodule
