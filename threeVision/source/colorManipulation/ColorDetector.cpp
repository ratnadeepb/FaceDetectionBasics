/*
 * MIT License
 * 
 * Copyright (c) 2017 Ratnadeep Bhattacharya
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the Software), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/* 
 * File:   ColorDetector.cpp
 * Author: ratnadeepb
 * 
 * Created on January 4, 2018, 6:19 AM
 */

#include "ColorDetector.hpp"
#include <vector>

cv::Mat ColorDetector::process(const cv::Mat& image)
{
    // re-allocate binary map if neccessary
    // same size as input image but 1 channel
    result.create(image.size(), CV_8U);
    
    // Converting to lab color space
    if(useLab){
        cv::cvtColor(image, converted, CV_BGR2Lab);
    }
    
    // Get the iterators
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();
    
    // Get iterators of the converted image
    if(useLab){
        it = converted.begin<cv::Vec3b>();
        itend = converted.end<cv::Vec3b>();
    }
    
    // for each pixel
    for(; it != itend; ++it, ++itout){
        // process each pixel
        // Compute distance from target color
        if(getDistanceToTargetColor(*it) < maxDist){
            *itout = 255;
        } else {
            *itout = 0;
        }
    }
    return result;
}











