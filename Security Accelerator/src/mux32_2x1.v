// file: mux32_2x1.v
// author: @sarahali

`timescale 1ns / 1ps
module mux32_2x1(input S, input [31:0] A, input [31:0] B, output reg [31:0] c);
always @(*) begin
if (S)
    c = B;
    else
    c = A;
end

endmodule
