module chi (
  input [191:0] in_st,
  output [63:0] out_st     
);
  wire [63:0] bc[0:1];

  assign bc[0] = in_st[127:64];
  assign bc[1] = in_st[191:128];

  assign out_st = in_st[63:0] ^ (~bc[0] & bc[1]);

endmodule
