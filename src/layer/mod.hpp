#include <stdio.h>
#include "../output/lwe_output.hpp"


enum LayerRidMethod{
    RGB16,
    CHARS,
}

class Layer {
private:
    LayerRidMethod  method;
public:
    uint8_t*          buff;
    LweResolution      res;

    Layer(size_t x, size_t y, char symbol);

    
}
