// file: MULT.v
// author: @mariamhmousa

`timescale 1ns/1ns

module MULT(input [31:0] m1, input [31:0] m2, output [31:0] out);

assign out = m1*m2;

endmodule