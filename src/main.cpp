#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>
#include "output/lwe_output.hpp"
#include "output/tui/lwe_tui.hpp"

#define TUI_CLEAR "\033[2J\033[1;1H"
#define loop while(true)
#define FPS 30

typedef std::chrono::milliseconds msec;
typedef  struct{
    int x;
    int y;
} resolution;


int main() {
    std::cout << "Hello, World!" << std::endl;
    resolution res = { 10, 10};

    auto start_time_mark = std::chrono::high_resolution_clock::now();
    auto end_time_mark = std::chrono::high_resolution_clock::now();
    msec frame_rate_gap{1000 / FPS};
    msec duration;
    int rend_count = 0;
    int frame_count = 0;
    int displeylabel_fps = 0;
    auto start_fps = std::chrono::high_resolution_clock::now();
    auto fdfwe = std::chrono::high_res
        
    loop {
        if (frame_rate_gap > duration)
            std::this_thread::sleep_for(frame_rate_gap - duration);
        if (std::chrono::duration_cast<msec>(end_time_mark - start_fps) >= (msec)1000){
            displeylabel_fps = frame_count;
            frame_count = 0;
            start_fps = end_time_mark;
            rend_count++;
        }

        std::cout << TUI_CLEAR;

        start_time_mark = std::chrono::high_resolution_clock::now();
        for(int i = 0; i <= res.x; i++){
            switch (i) {
                case 0:
                    printf("%d###############%d\n", frame_count, displeylabel_fps);
                    break;
                case 3:
                    switch (rend_count) {
                        case 0:
                            printf("########__########\n");
                            printf("##################\n");
                            printf("##################\n");
                            break;
                        case 1:
                            printf("########__########\n");
                            printf("##########|#######\n");
                            printf("##################\n");
                            break;
                        case 2:
                            printf("########__########\n");
                            printf("##########|#######\n");
                            printf("########__########\n");
                            break;
                        case 3:
                            printf("########__########\n");
                            printf("#######|##|#######\n");
                            printf("########__########\n");
                            break;
                        case 4:
                        default:
                            rend_count = 0;
                            printf("##################\n");
                            printf("##################\n");
                            printf("##################\n");

                    }
                break;
                case 4: case 5:
                    break;
                default:
                    printf("##################\n");

            }
        }


        frame_count++;

        end_time_mark = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<msec>(end_time_mark - start_time_mark);
    }

    return 0;
}
