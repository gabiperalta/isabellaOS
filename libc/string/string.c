#include <string.h>


void* memset(void * dest, unsigned char val, int count){
    void * aux = dest;
    for(int i=0; i<count; i++){
        *( unsigned char*)aux = val;
        aux = aux + sizeof(dest);
    }
    
    return dest;
}