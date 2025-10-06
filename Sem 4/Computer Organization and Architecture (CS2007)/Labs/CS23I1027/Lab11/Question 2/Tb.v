module room_light_controller_tb;
    reg clk;
    reg reset;
    reg [7:0] motion;
    wire [7:0] light;
    
    room_light_controller dut (
        .clk(clk),
        .reset(reset),
        .motion(motion),
        .light(light)
    );
    
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    
    initial begin
        $monitor("$Time=%0t | Motion=%b | Lights=%b | Active Lights=%0d", $time, motion, light, dut.active_lights_count);
    end
    
    initial begin
        reset = 1;
        motion = 8'b0; #10;
        reset = 0; #10;
        
        motion = 8'b00000111; #10;
        motion = 8'b00000000; #20;
        
        motion = 8'b00000010; #10;
        motion = 8'b00000000; #30;
        
        motion = 8'b01111000; #10;
        motion = 8'b00000000; #10;
        
        motion = 8'b10000001; #10;
        motion = 8'b00000000; #100;
        
        motion = 8'b00010000; #10;
        motion = 8'b00000000; #50;
        
        $finish;
    end
    
    initial begin
        forever begin
            #10;
            $display("Countdowns: %0d %0d %0d %0d %0d %0d %0d %0d", dut.countdown[0], dut.countdown[1], dut.countdown[2], dut.countdown[3], dut.countdown[4], dut.countdown[5], dut.countdown[6], dut.countdown[7]);
        end
    end
endmodule
        