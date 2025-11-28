#include "lwe_output.hpp"
#include "../layer/mod.hpp"


size_t LweArray<Layer>::get_max_large(){
    for(int i = 0; i < len; i++){
        uint32_t weight = (Layer)buff[i].res.get_sum();
        
    }
}
