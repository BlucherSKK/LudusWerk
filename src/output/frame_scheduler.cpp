#include <chrono>
#include <cstdio>
#include <thread>
#include "lwe_output.hpp"

bool FPSctrl::update_frame_rate(){
    if((msec)1000 <= std::chrono::duration_cast<msec>(end_timestamp - last_fps_check_timestamp)){
        cur_fps = frame_count;
        frame_count = 0;
        last_fps_check_timestamp = end_timestamp;
        return true;
    }
    return false;
}

bool FPSctrl::render_delay(){
    if(std::chrono::duration_cast<msec>(end_timestamp - last_frame_timestamp) < fps_gap){
        std::this_thread::sleep_for(fps_gap - std::chrono::duration_cast<msec>(end_timestamp - last_frame_timestamp));
        return true;
    }
    return false;
}

bool FPSctrl::set_start_render_timestamp(){
    if(last_frame_timestamp = std::chrono::high_resolution_clock::new()) return true;
    return false;
}

bool FPSctrl::set_end_render_timestamp(){
    if(end_timestamp = std::chrono::high_resolution_clock::new()) return true;
    return false;
}

uint16_t FPSctrl::get_fps(){
    
    return cur_fps;
}
