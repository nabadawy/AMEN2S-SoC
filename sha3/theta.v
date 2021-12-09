//calculate bc outside and take it as input
module theta (
    input [63:0] in_st,
    input [127:0] bc,
    output [63:0] out_st
    
);

wire [63:0] shift1;
wire [63:0] shift2;
wire [63:0] ORout;
    

  assign shift1=bc[127:64] <<1;
  assign shift2 =bc[127:64]>>63;
  assign ORout= shift1 | shift2;
  assign out_st = in_st ^ bc[63:0] ^ ORout;

endmodule
