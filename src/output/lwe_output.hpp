#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>
#include "../layer/mod.hpp"

#define loop while(true)

typedef struct<T>{
public:
    T*        buff;
    size_t    len;

    uint32_t get_max_large();
    
}LweArray;

typedef struct{
public:
    uint16_t    x;
    uint16_t    y;

    uint32_t get_sum()
    
}LweResolution;

typedef std::chrono::milliseconds msec;
typedef std::chrono::high_resolution_clock::time_point hTimeStamp;

class Frame{
private:
    uint8_t*          buff;
    LayerRidMethod  method;
public:
    Frame(LweArray<Layer> arr);
    Frame(LweArray<Layer> arr, LweResolution force_resolution);

    int displey(ostream stream);
}


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
