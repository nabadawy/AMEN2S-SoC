// file: mux_3x2.v
// author: @mariamhmousa

`timescale 1ns/1ns

module mux_3x2(input [1:0] S, input [31:0] A, input [31:0] B, input [31:0] C, output reg [31:0] D);

  always@(*) begin
    case(S)
      2'b01: D <= A;//stage 1
      2'b10: D <= B;//stage 2
      2'b11: D <= C;//stage 3
      default: D <= 0;
    endcase
  end

endmodule