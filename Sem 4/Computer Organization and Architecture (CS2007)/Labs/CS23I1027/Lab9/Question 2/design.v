module left_shift (
    input [15:0] data_in,
    input [3:0] shift_amt,
    output reg [15:0] data_out
);

    integer i;
    always @(*) begin
        data_out = data_in;
        for (i = 0; i < shift_amt; i = i + 1)
            data_out = data_out << 1;
    end
endmodule