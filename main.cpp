#include <iostream>
#include <string>
#include <cmath>

#define cimg_use_jpeg
#include <CImg.h>

using namespace cimg_library;
using std::string;
using std::stoi;

struct ImageScalingHandler {
    ImageScalingHandler() = default;
    ImageScalingHandler(const string& fi) : img_(fi.c_str()) {};

    void setImage(const string& fi);
    void resizeImage(int destWidth, int destHeight);

    CImg<float> img_;
};

void ImageScalingHandler::setImage(const string &fi) {
    img_.assign(fi.c_str());
}

void ImageScalingHandler::resizeImage(int destWidth, int destHeight) {
    long srcW = 0;
    long srcH = 0;

    CImg<unsigned>
    newImg(destWidth, destHeight, img_.depth(), img_.spectrum(), 0);

    long sourceWidth = static_cast<long>(img_.width());
    long sourceHeight = static_cast<long>(img_.height());

    for (int i = 0; i < destHeight; ++i) {
        srcH = lroundf(float{i} / destHeight * sourceHeight);
        srcH = std::min(srcH, sourceHeight - 1);
        for (int j = 0; j < destWidth; ++j) {
            srcW = lroundf(float{j} / destWidth * sourceWidth);
            srcW = std::min(srcW, sourceWidth - 1);

            newImg(j, i, 0) = img_(srcW, srcH, 0);
            newImg(j, i, 1) = img_(srcW, srcH, 1);
            newImg(j, i, 2) = img_(srcW, srcH, 2);
        }
    }

    img_.assign(newImg);
}

int main(int argc, char *argv[]) {

    if (argc != 4) {
        return 1;
    }

    ImageScalingHandler handler(argv[1]);
    handler.resizeImage(stoi(argv[2]), stoi(argv[3]));
    handler.img_.display();

    return 0;
}
