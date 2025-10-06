module pattern_checker (
    input [7:0] in,
    output reg is_alt,
    output reg parity
);
    always@(*) begin
        is_alt = ((in == 8'b10101010) || (in == 8'b01010101));
        parity = ^in;
    end
endmodule