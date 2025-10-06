module elevator_controller_tb;
    reg clk;
    reg reset;
    reg [3:0] req_floor;
    wire [1:0] current_floor;
    wire moving_up;
    wire moving_down;
    wire door_open;

    elevator_controller dut (
        .clk(clk),
        .reset(reset),
        .req_floor(req_floor),
        .current_floor(current_floor),
        .moving_up(moving_up),
        .moving_down(moving_down),
        .door_open(door_open)
    );
    
    initial begin
        clk = 0;
        forever #5 clk = ~clk;
    end
    
    initial begin
        reset = 1;
        req_floor = 4'b0000; #10;
        reset = 0; #10;
        
        req_floor = 4'b0100; 
        #10 req_floor = 4'b0000; #100;
        
        req_floor = 4'b0001; 
        #10 req_floor = 4'b0000; #100;
        
        req_floor = 4'b1000; 
        #10 req_floor = 4'b0000; #150;
        
        req_floor = 4'b0010; 
        #10 req_floor = 4'b0000; #100;
        
        req_floor = 4'b1001; 
        #10 req_floor = 4'b0000;
        
        #300;
        
        $finish;
    end
    
    initial begin
        $monitor("Time=%0t | PrevFloor=%0d | Up=%b | Down=%b | Door=%b | Req=%b", $time, current_floor, moving_up, moving_down, door_open, req_floor);
        // Floor is current_floor+1, Hence replaced Floor with PrevFloor, which is current_floor. (Monitor cannot take addition)
    end
endmodule

    