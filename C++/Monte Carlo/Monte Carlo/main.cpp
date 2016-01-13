//
//  main.cpp
//  Monte Carlo
//
//  Created by Carter Pape on 1/12/16.
//  Copyright © 2016 Carter Pape. All rights reserved.
//

#include <iostream>
#include <complex>
#include <random>

#define MANDELBROT_TEST_THRESHOLD 1000
#define POINT_COUNT 1000000
#define ACCEPTED_AREA 1.5065918849

using namespace std;

bool mandelbrotSetMemberQ(complex<long double> point) {
    int n = 0;
    complex<long double> original = point;
    while ((++n < MANDELBROT_TEST_THRESHOLD) && (abs(point) <= 2)) {
        point = point * point + original;
    }
    return n == MANDELBROT_TEST_THRESHOLD;
}

int main(int argc, const char * argv[]) {
    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<long double> dis(-2, 2);
    int in = 0;
    for (int n = 0; n < POINT_COUNT; n++) {
        complex<long double> point (dis(gen), dis(gen));
        if (mandelbrotSetMemberQ(point))
            in++;
    }
    double calculatedArea = 16.0 * (double) in / POINT_COUNT;
    cout << "I think it's              " << calculatedArea << '\n';
    cout << "Mathematicians think it's 1.50659" << '\n';
    cout << "Our answers differ by     " << abs(calculatedArea - ACCEPTED_AREA) * 100 / ACCEPTED_AREA << "%\n";
}
