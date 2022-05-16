`timescale 1ns / 1ps
module shifter(
input [31:0] a,
input [4:0] shamt,
input type,
output reg [31:0] r
    );
    
    always @(*)
    case(type)
    1'b0: r = (a<<shamt); //SL
    1'b1: r = (a>>shamt); //SR
    endcase
endmodule
