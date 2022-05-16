// file: cmp.v
// author: @sarahali

module cmp (input [31:0]a, input[31:0]b,output cmprslt);
wire a_lt_b, a_eq_b;
assign a_lt_b = (a < b);
assign a_eq_b = (a == b);
assign cmprslt =  a_lt_b | a_eq_b;
endmodule