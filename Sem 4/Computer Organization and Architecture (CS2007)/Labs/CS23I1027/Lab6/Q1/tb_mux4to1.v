module tb_mux4to1;

      reg [3:0] data_in_reg;          
     reg [1:0] select_reg;           
     wire output_y_wire;          
    


    mux4to1 uut (
        .data_in(data_in_reg),    // Map 'data_in' to 'data_in_reg'
        .select(select_reg),       // Map 'select' to 'select_reg'
        .output_y(output_y_wire)   // Map 'output_y' to 'output_y_wire'
    );

    // Test stimulus
    initial begin
        
        $dumpfile("and_gate.vcd");
        $dumpvars(0, tb_mux4to1);
        data_in_reg = 4'b1010;   // Set inputs to 1010
        select_reg = 2'b00;      // Initially select the first input
        #10;                     // Wait for 10 time units

        select_reg = 2'b01;      // Select the second input
        #10;                     // Wait for 10 time units

        select_reg = 2'b10;      // Select the third input
        #10;                     // Wait for 10 time units

        select_reg = 2'b11;      // Select the fourth input
        #10;                     // Wait for 10 time units

        $finish;                 // End the simulation
    end

    // Monitor the signals
    initial begin
        $monitor("Time = %0t | data_in = %b | select = %b | output_y = %b", $time, data_in_reg, select_reg, output_y_wire);
    end

endmodule
