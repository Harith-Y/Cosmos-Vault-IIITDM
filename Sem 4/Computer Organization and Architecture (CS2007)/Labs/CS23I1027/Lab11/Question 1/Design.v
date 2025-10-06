module elevator_controller (
    input wire clk,
    input wire reset,
    input wire [3:0] req_floor,
    output reg [1:0] current_floor,
    output reg moving_up,
    output reg moving_down,
    output reg door_open
);

    // FSM States
    localparam IDLE = 3'b000;
    localparam MOVING_UP = 3'b001;
    localparam MOVING_DOWN = 3'b010;
    localparam DOOR_OPENING = 3'b011;
    localparam DOOR_CLOSING = 3'b100;
    
    reg [2:0] state, next_state;
    reg [3:0] pending_requests;
    reg [3:0] door_timer;
    
    function [1:0] onehot_to_floor;
        input [3:0] onehot;
        begin
            case(onehot)
                4'b0001: onehot_to_floor = 2'b00; // 1st Floor
                4'b0010: onehot_to_floor = 2'b01; // 2nd Floor
                4'b0100: onehot_to_floor = 2'b10; // 3rd Floor
                4'b1000: onehot_to_floor = 2'b11; // 4rth Floor
                default: onehot_to_floor = 2'b00; //
            endcase
        end
    endfunction
    
    function requests_above;
        input [1:0] floor;
        input [3:0] requests;
        begin
            case(floor)
                2'b00: requests_above = |requests[3:1];
                2'b01: requests_above = |requests[3:2];
                2'b10: requests_above = requests[3];
                2'b11: requests_above = 1'b0;
            endcase
        end
    endfunction
    
    function requests_below;
        input [1:0] floor;
        input [3:0] requests;
        begin
            case(floor)
                2'b00: requests_below = 1'b0;
                2'b01: requests_below = requests[0];
                2'b10: requests_below = |requests[1:0];
                2'b11: requests_below = |requests[2:0];
            endcase
        end
    endfunction
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            pending_requests <= 4'b0000;
        end else begin
            pending_requests <= pending_requests | req_floor;
            
            if (state == DOOR_OPENING) begin
                case(current_floor)
                    2'b00: pending_requests[0] <= 1'b0;
                    2'b01: pending_requests[1] <= 1'b0;
                    2'b10: pending_requests[2] <= 1'b0;
                    2'b11: pending_requests[3] <= 1'b0;
                endcase
            end
        end
    end
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            door_timer <= 4'b0000;
        end else if (state == DOOR_OPENING || state == DOOR_CLOSING) begin
            door_timer <= door_timer + 1;
        end else begin
            door_timer <= 4'b0000;
        end
    end
        
    
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            state <= IDLE;
            current_floor <= 2'b00;
        end else begin
            state <= next_state;
      
            if (state == MOVING_UP && next_state == MOVING_UP) begin
                current_floor <= current_floor + 1;
            end else if (state == MOVING_DOWN && next_state == MOVING_DOWN) begin
                current_floor <= current_floor - 1;
            end
        end
    end
    
    always @(*) begin
        next_state = state;
        
        case(state)
            IDLE: begin
                if (pending_requests != 4'b0000) begin
                    case(current_floor)
                        2'b00: if (pending_requests[0]) next_state = DOOR_OPENING;
                               else if (requests_above(current_floor, pending_requests)) next_state = MOVING_UP;
                        2'b01: if (pending_requests[1]) next_state = DOOR_OPENING;
                               else if (requests_above(current_floor, pending_requests)) next_state = MOVING_UP;
                               else next_state = MOVING_DOWN;
                        2'b10: if (pending_requests[2]) next_state = DOOR_OPENING;
                               else if (requests_above(current_floor, pending_requests)) next_state = MOVING_UP;
                               else next_state = MOVING_DOWN; 
                        2'b11: if (pending_requests[3]) next_state = DOOR_OPENING;
                               else next_state = MOVING_DOWN; 
                    endcase
                end
            end
            
            MOVING_UP: begin
                case(current_floor)
                    2'b00: if (pending_requests[1]) next_state = DOOR_OPENING;
                    2'b01: if (pending_requests[2]) next_state = DOOR_OPENING;
                    2'b10: if (pending_requests[3]) next_state = DOOR_OPENING;
                    2'b11: next_state = DOOR_OPENING;
                endcase
            end
            
            MOVING_DOWN: begin
                if (door_timer <= 4'b1000) begin
                    next_state = DOOR_CLOSING;
                end
            end
            
            DOOR_CLOSING: begin
                if (door_timer >= 4'b1111) begin
                    if (pending_requests == 4'b0000) begin
                        next_state = IDLE;
                    end else begin
                        if (requests_above(current_floor, pending_requests)) begin
                            next_state = MOVING_UP;
                        end else if (requests_above(current_floor, pending_requests)) begin
                            next_state = MOVING_DOWN;
                        end else begin
                            next_state = IDLE;
                        end
                    end
                end
            end
        endcase
    end
    
    // Output
    always @(*) begin
        moving_up = 1'b0;
        moving_down = 1'b0;
        door_open = 1'b0;
        
        case(state)
            MOVING_UP: begin
                moving_up = 1'b1;
            end
            
            MOVING_DOWN: begin
                moving_down = 1'b1;
            end
            
            DOOR_OPENING, DOOR_CLOSING: begin
                door_open = 1'b1;
            end
        endcase
    end
endmodule
    