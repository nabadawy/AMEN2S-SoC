`timescale 1ns/1ns

module Mux4(input [31:0]data,
          input s,
          output reg [7:0]out);
//input wire [31]data;
//input wire s;
//output reg [7]out;

always @ (data or s)
begin

case (s)
2'd0 : out <= data[7:0];
2'd1 : out <= data[15:8];
2'd2 : out <= data[23:16];
2'd3 : out <= data[31:24];
endcase

end

endmodule
