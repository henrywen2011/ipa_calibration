/*!
 *****************************************************************
 * \file
 *
 * \note
 * Copyright (c) 2015 \n
 * Fraunhofer Institute for Manufacturing Engineering
 * and Automation (IPA) \n\n
 *
 *****************************************************************
 *
* \note
* Repository name: ipa_calibration
* \note
* ROS package name: relative_localization
 *
 * \author
 * Author: Richard Bormann
 * \author
 * Supervised by:
 *
 * \date Date of creation: 10.08.2016
 *
 * \brief
 *
 *
 *****************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer. \n
 * - Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution. \n
 * - Neither the name of the Fraunhofer Institute for Manufacturing
 * Engineering and Automation (IPA) nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission. \n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

#ifndef RELATIVE_LOCALIZATION_UTILITIES_H
#define RELATIVE_LOCALIZATION_UTILITIES_H

#include <iostream>
#include <vector>

#include <opencv2/opencv.hpp>
#include <tf/transform_listener.h>


namespace RelativeLocalizationUtilities
{

// success_propability = probability for drawing two inliers at once
// inlier_ratio = the ratio of line inliers in the point set
bool fitLine(const std::vector<cv::Point2d>& points, cv::Vec4d& line, const double inlier_ratio, const double success_probability, const double max_inlier_distance, bool draw_from_both_halves_of_point_set);

double distanceToLine(const double npx, const double npy, const double n0x, const double n0y, const double pointx, const double pointy);

cv::Mat makeTransform(const cv::Mat& R, const cv::Mat& t);

// computes the transform from target_frame to source_frame (i.e. transform arrow is pointing from target_frame to source_frame)
bool getTransform(const tf::TransformListener& transform_listener, const std::string& target_frame, const std::string& source_frame, cv::Mat& T);

bool getTransformAdv(const tf::TransformListener& transform_listener, const std::string& target_frame, const std::string& source_frame, const std::string& fixed_frame, cv::Mat& T, const ros::Time &target_time = ros::Time(0.f), const ros::Time &source_time = ros::Time(0.f));

}


#endif	// RELATIVE_LOCALIZATION_UTILITIES_H
