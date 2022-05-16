// file: used_bits.v
// author: @mariamhmousa

`timescale 1ns/1ns

module used_bits(input [31:0] N, output reg [4:0] n);

always@(*)
begin
  if(N[31] == 1) n=32;
  else if(N[30] == 1) n=31;
  else if(N[29] == 1) n=30;
  else if(N[28] == 1) n=29;
  else if(N[27] == 1) n=28;
  else if(N[26] == 1) n=27;
  else if(N[25] == 1) n=26;
  else if(N[24] == 1) n=25;
  else if(N[23] == 1) n=24;
  else if(N[22] == 1) n=23;
  else if(N[21] == 1) n=22;
  else if(N[20] == 1) n=21;
  else if(N[19] == 1) n=20;
  else if(N[18] == 1) n=19;
  else if(N[17] == 1) n=18;
  else if(N[16] == 1) n=17;
  else if(N[15] == 1) n=16;
  else if(N[14] == 1) n=15;
  else if(N[13] == 1) n=14;
  else if(N[12] == 1) n=13;
  else if(N[11] == 1) n=12;
  else if(N[10] == 1) n=11;
  else if(N[9] == 1) n=10;
  else if(N[8] == 1) n=9;
  else if(N[7] == 1) n=8;
  else if(N[6] == 1) n=7;
  else if(N[5] == 1) n=6;
  else if(N[4] == 1) n=5;
  else if(N[3] == 1) n=4;
  else if(N[2] == 1) n=3;
  else if(N[1] == 1) n=2;
  else if(N[0] == 1) n=1;
end

endmodule