module mux4to1 (
    input [3:0] data_in,    // 4-bit input vector (renamed from 'a')
    input [1:0] select,      // 2-bit select input (renamed from 'sel')
    output reg output_y          // Output (renamed from 'y')
);

    always @(*) begin
        case(select)
            2'b00: output_y = data_in[0];  // Select first input (data_in[0])
            2'b01: output_y = data_in[1];  // Select second input (data_in[1])
            2'b10: output_y = data_in[2];  // Select third input (data_in[2])
            2'b11: output_y = data_in[3];  // Select fourth input (data_in[3])
            default: output_y = 1'b0;      // Default value
        endcase
    end

endmodule
