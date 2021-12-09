module rhopi (
  input [63:0] in_st,
    input rotc,
  output [63:0] out_st
);

  wire [63:0] shift1;
wire [63:0] shift2;
    

assign shift1=in_st << rotc;
assign shift2 = in_st>>(64-rotc);

assign out_st = shift1 | shift2;

endmodule
