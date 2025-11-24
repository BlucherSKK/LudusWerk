#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

#define loop while(true)


typedef std::chrono::milliseconds msec;
typedef std::chrono::high_resolution_clock::time_point hTimeStamp;



class FPSctrl {
	register hTimeStamp last_frame_timestamp;
	hTimeStamp last_fps_check_timestamp;
	register hTimeStamp end_timestamp;
	msec fps_gap;
	uint16_t cur_fps;
	uint16_t frame_count;
public:

	FPSctrl(
		uint16_t FPS
	) : 
		last_frame_timestamp(std::chrono::high_resolution_clock::now()),
		last_fps_check_timestamp(std::chrono::high_resolution_clock::now()),
		end_timestamp(std::chrono::high_resolution_clock::now()),
		fps_gap((msec)(1000 / FPS)),
		cur_fps(FPS),
		frame_count(0) 
	{}

	//this methods return bool, because inside there body have a condition, 
	//and if this condition is true hten function return true, and if this condition
	//is false function return false.
	bool update_frame_rate();
	bool render_delay();
    bool set_start_render_timestamp();
    bool set_end_render_timestamp();
    uint16_t get_fps();
};
