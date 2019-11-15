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
	Points points;
	VectorPointEdge vect_point_edges;	// vector of std::pair<Point, Edges>
	VectorPointTrajectory vect_point_trajectories;
	double current_rotation;
	Point pivot;
	
	// init the data
	set_static_points(points);
	
	// construct a vector of PairPointEdge
	for(auto from = points.begin(); from != points.end(); ++from) {
		Edges *ev = new Edges;
		for(auto to = points.begin(); to != points.end(); ++to) {
			if(to == from) continue;
			// construct a new edge
			Edge e;
			e.from = *from;
			e.to = *to;
			e.gradient = (to->y - from->y) / (to->x - from->x);
			e.radians = atan(e.gradient);
			if (e.radians < 0.0) e.radians += M_PI;
			e.used = false;

			// add to edge vector ev
			(*ev).push_back(e);
		}
		// sort the vector on ascending radian values
		std::sort((*ev).begin(), (*ev).end(), compare_radians);
		// add edge vector to map using from as key and edge vector as value
		PointEdges pair = std::make_pair(*from,*ev);
		vect_point_edges.push_back(pair);
	}
	
	// Debug printout
	prt_pair_vector(&vect_point_edges, true);
	// ----- --------
	
	// Using each entry in vect_point_edges as starting point
	for(auto start = vect_point_edges.begin(); start != vect_point_edges.end(); ++start) { // Trajectories loop
		
		// clear all 'used' values to false
		for(auto x = vect_point_edges.begin(); x != vect_point_edges.end(); ++x) {
			Edges ev = (*x).second;
			for(auto y = ev.begin(); y != ev.end(); ++y) y->used = false;
		}
		
		// Establish a new trajectory for the starting point
		Trajectory *t = new Trajectory;	// vector of Edge
		// calculate the trajectory
		current_rotation = 0.0;
		pivot = (*start).first;
		
		// push trajectory to vect_point_trajectories
		
	} // Trajectories loop
	
	// Animate/Display each trajectory
	
	// Cleanup code - free memory
	
	return 0;
}

