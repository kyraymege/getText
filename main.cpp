#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>
#include <fstream>

using namespace std;
using namespace cv;

void getText(string imagePath)
{
    string outText;
    cv::Mat image;
    image = cv::imread(imagePath, cv::IMREAD_COLOR);

    tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
    api->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);
    api->SetPageSegMode(tesseract::PSM_AUTO);
    api->SetImage(image.data, image.cols, image.rows, 3, image.step);
    outText = string(api->GetUTF8Text());
    // Write a file

    ofstream MyFile(imagePath + ".txt");

    MyFile << outText;
    MyFile.close();

    cout << outText;
    api->End();
    // cv::destroyAllWindows();
    // cv::imshow(imagePath, image);
    // cv::waitKey(0);
    // cv::destroyWindow(imagePath);
}

int main()
{
    string imageLocation;
    cout << "Please write image location." << endl;
    cin >> imageLocation;
    getText(imageLocation);
}