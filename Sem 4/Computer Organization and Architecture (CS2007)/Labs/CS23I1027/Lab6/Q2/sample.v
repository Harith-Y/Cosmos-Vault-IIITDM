module mux4to1 (
    input [7:0] data_in,    // 8-bit input vector (four 2-bit inputs)
    input [1:0] select,      // 2-bit select input
    output reg [1:0] output_y   // 2-bit output
);

    always @(*) begin
        case(select)
            2'b00: output_y = data_in[1:0];  // Select first 2-bit input (data_in[1:0])
            2'b01: output_y = data_in[3:2];  // Select second 2-bit input (data_in[3:2])
            2'b10: output_y = data_in[5:4];  // Select third 2-bit input (data_in[5:4])
            2'b11: output_y = data_in[7:6];  // Select fourth 2-bit input (data_in[7:6])
            default: output_y = 2'b00;       // Default value
        endcase
    end

endmodule

