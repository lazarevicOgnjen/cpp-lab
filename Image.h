#ifndef IMAGE_H
#define IMAGE_H


class Image {
private:
    short **data;
    char *location;
    int size;
public:
    Image();

    Image(int size);

    ~Image();

    int Dimension() const {
        return size;
    }

    void Invert();

    void Load();

    void Print();

    bool Crop(int newSize);
};


#endif
