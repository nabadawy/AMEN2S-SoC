`timescale 1ns / 1ps
module mux_2x1(input S, A, B, output reg c);
always @(*) begin
if (S)
    c = B;
    else
    c = A;
end

endmodule
