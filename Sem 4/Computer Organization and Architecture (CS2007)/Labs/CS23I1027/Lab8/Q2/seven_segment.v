module seven_segment (
    input [3:0] digit,    // 4-bit input to select a digit (0-9)
    output reg a,         // Segment a
    output reg b,         // Segment b
    output reg c,         // Segment c
    output reg d,         // Segment d
    output reg e,         // Segment e
    output reg f,         // Segment f
    output reg g          // Segment g
);

    // Logic to decode the input digit into the seven segment display
    always @ (digit) begin
        case (digit)
            4'b0000: begin // 0
                a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 0;
            end
            4'b0001: begin // 1
                a = 0; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
            end
            4'b0010: begin // 2
                a = 1; b = 1; c = 0; d = 1; e = 1; f = 0; g = 1;
            end
            4'b0011: begin // 3
                a = 1; b = 1; c = 1; d = 1; e = 0; f = 0; g = 1;
            end
            4'b0100: begin // 4
                a = 0; b = 1; c = 1; d = 0; e = 0; f = 1; g = 1;
            end
            4'b0101: begin // 5
                a = 1; b = 0; c = 1; d = 1; e = 0; f = 1; g = 1;
            end
            4'b0110: begin // 6
                a = 1; b = 0; c = 1; d = 1; e = 1; f = 1; g = 1;
            end
            4'b0111: begin // 7
                a = 1; b = 1; c = 1; d = 0; e = 0; f = 0; g = 0;
            end
            4'b1000: begin // 8
                a = 1; b = 1; c = 1; d = 1; e = 1; f = 1; g = 1;
            end
            4'b1001: begin // 9
                a = 1; b = 1; c = 1; d = 1; e = 0; f = 1; g = 1;
            end
            default: begin
                a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; g = 0; // Default to all off
            end
        endcase
    end

endmodule

