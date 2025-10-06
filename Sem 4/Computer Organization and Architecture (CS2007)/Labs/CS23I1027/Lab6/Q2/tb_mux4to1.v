module tb_mux4to1;

    reg [7:0] data_in_reg;     // 8-bit input register (for four 2-bit inputs)
    reg [1:0] select_reg;      // 2-bit select input
    wire [1:0] output_y_wire;  // 2-bit output wire


    mux4to1 uut (
        .data_in(data_in_reg),    // Map 'data_in' to 'data_in_reg'
        .select(select_reg),       // Map 'select' to 'select_reg'
        .output_y(output_y_wire)   // Map 'output_y' to 'output_y_wire'
    );

    // Test stimulus
    initial begin
        $dumpfile("mux4to1.vcd");
        $dumpvars(0, tb_mux4to1);
        
        data_in_reg = 8'b10100011;   // Set inputs as four 2-bit values: 10, 00, 11, 01
        select_reg = 2'b00;          // Initially select the first 2-bit input
        #10;                         // Wait for 10 time units

        select_reg = 2'b01;          // Select the second 2-bit input
        #10;                         // Wait for 10 time units

        select_reg = 2'b10;          // Select the third 2-bit input
        #10;                         // Wait for 10 time units

        select_reg = 2'b11;          // Select the fourth 2-bit input
        #10;                         // Wait for 10 time units

        $finish;                     // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | data_in = %b | select = %b | output_y = %b", $time, data_in_reg, select_reg, output_y_wire);
    end

endmodule

