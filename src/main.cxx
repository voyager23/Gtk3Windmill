/*
 * main.cxx
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

int main(int argc, char **argv)
{
	std::vector<Point> points;
	
	// init the data
	set_static_points(points);
	
	// for each point
	//		construct a vector of edges. (Edges);
	//		add vector to unordered_map using 'from' as key and vector as value
	
	for(auto from = points.begin(); from != points.end(); ++from) {
		Edges *ev = new Edges;
		for(auto to = points.begin(); to != points.end(); ++to) {
			if(to == from) continue;
			
			
		}
	}
			
	
	return 0;
}

