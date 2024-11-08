#include <iostream>
#include "Image.h"

int main() {
    auto image1 = Image(10);
    image1.Load();
    image1.Invert();
    image1.Print();

    auto image2 = new Image(5);
    image2->Load();
    std::cout << image2->Dimension() << std::endl;
    image2->Print();
    image2->Crop(10);
    std::cout << image2->Dimension() << std::endl;
    image2->Print();
    image2->Crop(3);
    std::cout << image2->Dimension() << std::endl;
    image2->Print();

    delete image2;

    return 0;
}
