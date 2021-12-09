module iota (
  input [63:0] in_st_0,
  input [63:0] rndc_r,
  output [63:0] out_st_0
);

assign out_st_0 = in_st_0 ^ rndc_r;


endmodule
