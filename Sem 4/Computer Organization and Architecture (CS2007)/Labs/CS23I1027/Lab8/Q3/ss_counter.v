module ss_counter (
    input clk,                // Clock input
    input reset,              // Reset input
    output [3:0] count,       // 4-bit count output
    output reg [6:0] segments // 7-segment display output (changed to reg)
);

    reg [3:0] count_reg; // Register to hold the current count

    // Counter logic
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            count_reg <= 4'b0000;  // Reset the counter to 0
        end else if (count_reg == 4'b1001) begin
            count_reg <= 4'b0000;  // Reset the counter to 0 when it reaches 9
        end else begin
            count_reg <= count_reg + 1; // Increment the counter otherwise
        end
    end

    assign count = count_reg; // Keep track of the current count

    // 7-segment display logic using case statements
    always @(*) begin
        case (count_reg)
            4'b0000: segments = 7'b1111110; // Display '0'
            4'b0001: segments = 7'b0110000; // Display '1'
            4'b0010: segments = 7'b1101101; // Display '2'
            4'b0011: segments = 7'b1111001; // Display '3'
            4'b0100: segments = 7'b0110011; // Display '4'
            4'b0101: segments = 7'b1011011; // Display '5'
            4'b0110: segments = 7'b1011111; // Display '6'
            4'b0111: segments = 7'b1110000; // Display '7'
            4'b1000: segments = 7'b1111111; // Display '8'
            4'b1001: segments = 7'b1111011; // Display '9'
            default: segments = 7'b0000000; // Blank display
        endcase
    end

endmodule

