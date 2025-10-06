module counter (
    input clk,           // Clock input
    input reset,         // Reset input
    output [3:0] count   // 4-bit count output
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

    assign count = count_reg; // Assign the current count
endmodule

