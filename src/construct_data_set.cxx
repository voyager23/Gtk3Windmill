/*
 * construct_data_set.cxx
 * 
 * Copyright 2019 Michael Tate <mike@pop-os>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include "../include/windmill.h"

int construct_data_set(Points& points, int n_points, int window_size) {
	
	std::cout << "Searching for valid data set of " << n_points << " points, window size " << window_size << " pixels." << std::endl;
	
	srand(time(NULL));	// Normal data set
	//srand(70453);			// Debug data set
	
	// generate N points
	for(auto pass = 0; pass < PASSCOUNT; ++pass) {
		int matches = 0;
		double Mab;
		double Mbc;
		double dy, dx;
		
		// This does not rely on a previous initialisation of the points vector
		for(auto c = 0; c < N; ++c) {
			Point p = {(double_t)(rand() % window_size), (double_t)(rand() % window_size)};
			points.push_back(p);
		}
		
		// generate a series of triples and check the gradients between the 3 points
		for(auto a = points.begin(); a != points.end() - 2; ++a) {
			for(auto b = a + 1; b != points.end() - 1; ++b) {
				// calculate the first gradient, (dy/dx)
				dy = a->y - b->y;
				dx = a->x - b->x;
				Mab = (dy / dx);
				for(auto c = b + 1; c != points.end(); ++c) {
					dy = b->y - c->y;
					dx = b->x - c->x;
					if(Mab == (dy / dx)) matches += 1;	
				}
			}
		}
		if(matches == 0) {
			std::cout << (pass+1) << " passes completed." << std::endl;
			std::cout << std::endl << "Valid data set found." << std::endl;
			return 1;
		}	
	} // for auto pass = 0...
	// return zero if no data set found
	return 0;	
}


