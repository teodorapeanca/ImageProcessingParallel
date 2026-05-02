#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <omp.h>   // IMPORTANT pentru OpenMP

struct Pixel
{
    int r;
    int g;
    int b;
};

int main()
{
    std::ifstream file("C:\\Users\\teodo\\source\\repos\\ImageProcessingParallel\\x64\\Debug\\input.ppm");

    if (!file)
    {
        std::cout << "Nu s-a putut deschide imaginea!\n";
        return 1;
    }

    std::string format;
    int width, height, maxColor;

    file >> format;
    file >> width >> height;
    file >> maxColor;

    std::vector<Pixel> pixels;
    Pixel p;

    for (int i = 0; i < width * height; i++)
    {
        file >> p.r >> p.g >> p.b;
        pixels.push_back(p);
    }

    file.close();

    std::vector<Pixel> grayPixels(width * height);

    // ⏱️ TIMP PARALel
    double start = omp_get_wtime();

    // 🔴 PARALLELIZARE
#pragma omp parallel for
    for (int i = 0; i < pixels.size(); i++)
    {
        int gray = (pixels[i].r + pixels[i].g + pixels[i].b) / 3;

        grayPixels[i].r = gray;
        grayPixels[i].g = gray;
        grayPixels[i].b = gray;
    }

    double end = omp_get_wtime();

    std::cout << "Timp executie paralel: " << (end - start) << " secunde" << std::endl;
    std::cout << "Numar thread-uri: " << omp_get_max_threads() << std::endl;

    std::ofstream outFile("C:\\Users\\teodo\\source\\repos\\ImageProcessingParallel\\x64\\Debug\\output_parallel.ppm");

    if (!outFile)
    {
        std::cout << "Nu s-a putut crea fisierul de iesire!\n";
        return 1;
    }

    outFile << "P3\n";
    outFile << width << " " << height << "\n";
    outFile << maxColor << "\n";

    for (int i = 0; i < grayPixels.size(); i++)
    {
        outFile << grayPixels[i].r << " "
            << grayPixels[i].g << " "
            << grayPixels[i].b << "\n";
    }

    outFile.close();

    std::cout << "Imaginea paralela a fost salvata in output_parallel.ppm" << std::endl;

    return 0;
}