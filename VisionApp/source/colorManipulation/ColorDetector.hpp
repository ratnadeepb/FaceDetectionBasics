/*------------------------------------------------------------------------------------------*\
This file contains material supporting chapter 3 of the book:
OpenCV3 Computer Vision Application Programming Cookbook
Third Edition
by Robert Laganiere, Packt Publishing, 2016.
This program is free software; permission is hereby granted to use, copy, modify,
and distribute this source code, or portions thereof, for any purpose, without fee,
subject to the restriction that the copyright notice may not be removed
or altered from any source or altered source distribution.
The software is released on an as-is basis and without any warranties of any kind.
In particular, the software is not guaranteed to be fault-tolerant or free from failure.
The author disclaims all warranties with regard to this software, any use,
and any consequent failure, is purely the responsibility of the user.
Copyright (C) 2016 Robert Laganiere, www.laganiere.name
\*------------------------------------------------------------------------------------------*/

#ifndef COLORDETECTOR_HPP
#define COLORDETECTOR_HPP

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>

class ColorDetector {
private:
    int maxDist;                                                                // Minumum acceptable distance
    cv::Vec3b target;                                                           // Target color
    cv::    Mat converted;                                                          // Converted image
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
    
    void setUseLab(int useLab){
        if(useLab){
            this->useLab = true;
        }
    }
    
    void setUseLab(bool useLab){
        this->useLab = useLab;
    }

};

#endif /* COLORDETECTOR_HPP */

