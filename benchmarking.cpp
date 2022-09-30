#include <iostream>
#include <stdlib.h>
#include "libs/buffer.hpp"

int main()
{
    buffer buf;
    data temp;
    long long values[6];
    for (unsigned long long i = 0; i < 20; i++)
    {
        if (rand() % 3 < 1)
        {
            for (long long j = 0; j < 6; j++)
                values[j] = rand() % 6;
            temp = data(values, i);
            std::cout << "Push:    " << buf.push(temp) << std::endl;
        }
        else
        {
            std::cout << "Pop:     " << buf.pop() << std::endl;
        }

        std::cout << "Size:    " << buf.size() << std::endl;
        std::cout << "Ptr:     " << buf.getFrontPtr() << ' ' << buf.getBackPtr() << std::endl;
        std::cout << "Current: " << buf.front().ia << ' ' << buf.front().ib << ' ' << buf.front().ic << std::endl;
        std::cout << "Voltage: " << buf.front().va << ' ' << buf.front().vb << ' ' << buf.front().vc << std::endl
                  << std::endl;
        system("read -p \"Pressione enter para sair\" saindo");
    }

    return 0;
}