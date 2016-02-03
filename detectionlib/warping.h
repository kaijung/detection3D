/**************************************************************************************************
 **************************************************************************************************
 
     BSD 3-Clause License (https://www.tldrlegal.com/l/bsd3)
     
     Copyright (c) 2015 Andrés Solís Montero <http://www.solism.ca>, All rights reserved.
     
     
     Redistribution and use in source and binary forms, with or without modification,
     are permitted provided that the following conditions are met:
     
     1. Redistributions of source code must retain the above copyright notice,
        this list of conditions and the following disclaimer.
     2. Redistributions in binary form must reproduce the above copyright notice,
        this list of conditions and the following disclaimer in the documentation
        and/or other materials provided with the distribution.
     3. Neither the name of the copyright holder nor the names of its contributors
        may be used to endorse or promote products derived from this software
        without specific prior written permission.
     
     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
     AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
     IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
     ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
     LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
     DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
     THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
     OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
     OF THE POSSIBILITY OF SUCH DAMAGE.
 
 **************************************************************************************************
 **************************************************************************************************/

#ifndef __detection3D__warping__
#define __detection3D__warping__

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv; 

class Warping
{
public:
    static double rad2Deg(double rad);
    static double deg2Rad(double deg);
    
    static void   warpMatrix(Size sz,
                             double yaw,
                             double pitch,
                             double roll,
                             double scale,
                             double fovy,
                             Mat &M,
                             vector<Point2f>* corners);
    
    static void warpImage(const Mat &src,
                          double yaw,
                          double pitch,
                          double roll,
                          double scale,
                          double fovy,
                          Mat &dst,
                          Mat &M,
                          vector<Point2f> &corners);
    
    void projectKeypoints(const vector<KeyPoint> &original, const MatExpr M, vector<Point> &transformedPoints);
    static Mat  keyPoint2Mat(const vector<KeyPoint>& keypoints);
    static vector<Point> mat2Points(const Mat& stub);
};

#endif /* defined(__detection3D__warping__) */