module controller (
    input clk,
    input sFarm, // Sensor input from farm road
    output[1:0] H,
    output[1:0] F
);

reg [1:0] state;
reg [3:0] wait_counter;
reg [3:0] green_counter;

parameter N = 4; // Highway wait time
parameter M = 5; // Max Green time for Farm road

// 00 -> Green
// 01 -> Yellow
// 10 -> Red

assign H[1] = state[1];
assign H[0] = !state[1] & state[0];
assign F[1] = !state[1];
assign F[0] = state[0] & state[1];

always @(posedge clk)
begin
    case(state)
        2'b00: // Highway Green
        begin
            if (sFarm == 1)
            begin
                wait_counter <= 1;
                state <= 2'b01;
            end
            else
                state <= 2'b00;
        end
        
        2'b01: // Highway Green Wait
        begin
            if (wait_counter == N)
                state <= 2'b10;
            else
                wait_counter <= wait_counter + 1;
        end
        
        2'b10: // Highway Yellow
        begin
            state <= 2'b11;
        end
        
        2'b11: // Farm Green
        begin
            if ((sFarm == 0) || (green_counter == M))
                state <= 2'b01;
            else
                green_counter <= green_counter + 1;
        end
    endcase
end

initial begin
    state = 2'b00;
    wait_counter = 0;
    green_counter = 0;
end

endmodule