#include "demo.h"
#include <stdio.h>
#include <algorithm>
#include <iostream>

int main(){

    printf("Integers...");
    auto vectors_i  = enumerator<int>(3,64);
    printf("done! %d vectors.\n", vectors_i.size());

    printf("Unsigned...");
    auto vectors_ui = enumerator<unsigned int>(3,64);
    printf("done! %d vectors.\n", vectors_ui.size());
}
