#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{

    //Chargement et redimensionnement de l'image

    string image_path = "C:/Users/MELI MANU/Pictures/R.png";

    Mat image = imread(image_path, IMREAD_COLOR);

    if (image.empty())
    {
        cout << "Ne peut pas lire l'image: " << image_path << endl;
        return 1;
    }

    resize(image, image, { 500,500 }, 0, 0, cv::INTER_NEAREST);

    imshow("image complete", image);

    waitKey(0);


    //Decoupage de l'image

    Size taille = image.size();
    int nb_part_horizontal = 2;
    int nb_part_vertical = 2;
    vector<vector<Mat>> parts(nb_part_horizontal, vector<Mat>(nb_part_vertical));

    for (int i = 0; i < nb_part_horizontal; i++) {
        for (int j = 0; j < nb_part_vertical; j++) {
            Rect roi(i * taille.width / nb_part_horizontal, j * taille.height / nb_part_vertical, taille.width / nb_part_horizontal, taille.height / nb_part_vertical);
            parts[i][j] = image(roi);
        }
    }
    // Affichage des images à l'ecran
    for (int i = 0; i < nb_part_horizontal; i++) {
        for (int j = 0; j < nb_partvertical; j++) {
            string windowName = "part" + tostring(i + 1) + "" + to_string(j + 1);
            imshow(windowName, parts[i][j]);
        }
    }
    waitKey(0);
    destroyAllWindows();

    return 0;
}