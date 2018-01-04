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
 * File:   ColorDetector.hpp
 * Author: ratnadeepb
 *
 * Created on January 4, 2018, 6:19 AM
 */

#ifndef COLORDETECTOR_HPP
#define COLORDETECTOR_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class ColorDetector {
private:
    int maxDist;                                                                // Minumum acceptable distance
    cv::Vec3b target;                                                           // Target color
    cv::Mat converted;                                                          // Converted image
    bool useLab;
    
    cv::Mat result;                                                             // Binary map of image
    
public:
    // Default parameter initialisation
    ColorDetector() : maxDist(100), target(0, 0, 0), useLab(false) {}
    
    // Lab color space example constructor
    ColorDetector(bool useLab) : maxDist(100), target(0, 0, 0), useLab(useLab) {}
    
    // Full constructor
    ColorDetector(uchar blue, uchar green, uchar red, int maxDist=100,
    bool useLab=false)
    {
        setTargetColor(blue, green, red);
    }
    
    // Compute distance from target color
    int getDistanceToTargetColor(const cv::Vec3b& color) const {
		  return getColorDistance(color, target);
	  }
    
    // Calculate city-block distance between colors
    int getColorDistance(const cv::Vec3b& color1, const cv::Vec3b& color2) const
    {
        return abs(color1[0] - color2[0]) + 
                abs(color1[1] - color2[1]) + 
                abs(color1[2] - color2[2]);
        
        // Or:
	// return static_cast<int>(cv::norm<int,3>(cv::Vec3i(color[0]-color2[0],color[1]-color2[1],color[2]-color2[2])));
		  
	// Or:
	// cv::Vec3b dist;
	// cv::absdiff(color,color2,dist);
	// return cv::sum(dist)[0];
    }
    
    // Process the image, return 1 channel binary image
    cv::Mat process(const cv::Mat &image);
    
    cv::Mat operator()(const cv::Mat &image)
    {
        cv::Mat input;
        
        if(useLab){ // Lab conversion
            cv::cvtColor(image, input, CV_BGR2Lab);
        } else {
            input = image;
        }
        cv::Mat output;
        cv::absdiff(input, cv::Scalar(target), output);
        // Split channels into 3 images
        std::vector<cv::Mat> images;
        cv::split(output, images);
        // Add the channels together (saturation may occur)
        output = images[1] + images[2] + images[3];
        // Apply threshold
        cv::threshold(output,                                                   // input
                output,                                                         // output
                maxDist,                                                        // threshold (< 256)
                255,                                                            // max value
                cv::THRESH_BINARY_INV);                                         // thresholding type
        return output;
    }
    
    // Getters and Setters
    
    // set color distance threshold
    // Threshold must be positive or else set to 0
    void setColorDistanceThreshold(int distance)
    {
        if(distance < 0){
            distance = 0;
        }
        maxDist = distance;
    }
    
    // Get color distance threshold
    int getColorDistanceThreshold() const
    {
        return maxDist;
    }
    
    // Sets the color to be detected
    // In BGR space
    void setTargetColor(uchar blue, uchar green, uchar red)
    {
        // BGR order
        target = cv::Vec3b(blue, green, red);
        
        if(useLab){
            // Temp 1-pixel image
            cv::Mat tmp(1, 1, CV_8UC3);
            tmp.at<cv::Vec3b>(0, 0) = target;
            
            // Converting target to Lab color space
            cv::cvtColor(tmp, tmp, CV_BGR2Lab);
            
            target = tmp.at<cv::Vec3b>(0, 0);
        }
    }
    
    void setTargetColor(cv::Vec3b color)
    {
        // Set color
        target = color;
    }
    
    cv::Vec3b getTargetColor() const
    {
        return target;
    }

};

#endif /* COLORDETECTOR_HPP */

