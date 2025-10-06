module tb;
    reg clk;
    reg sFarm_reg; // Signal from sensor at the farm road
    wire [1:0] H;  // Traffic signal at Highway
    wire [1:0] F;  // Traffic signal at Farm
    controller dut (
        .clk(clk),
        .sFarm(sFarm_reg),
        .H(H),
        .F(F)
    );
    
    // Clock Generation
    always #5 clk = ~clk;
    
    initial begin
        $dumpfile("dump.vcd");
        $dumpvars(0, tb);
        
        $monitor("Time = %0t | clk = %0d | sFarm = %0d | H = %b | F = %b", $time, clk, sFarm_reg, H, F);
        
        sFarm_reg = 0;
        #5 clk = 0;
        #15 sFarm_reg = 1;
        #20 sFarm_reg = 0;
        #15 sFarm_reg = 1;
        #10 sFarm_reg = 0;
        #35 $finish;
    end
endmodule