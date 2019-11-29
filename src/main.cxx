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
#define NDEBUG 
#include <cassert>

int main(int argc, char **argv)
{
	Points points;
	VectorPointEdge vect_point_edges;	// vector of std::pair<Point, Edges>
	VectorPointEdge::iterator pivot_select;
	
	Edges::iterator target_select;
	
	Trajectory trajectory;
	double current_rotation;
	int trajectory_index = 0;
	Point test_point = {176,28};	//debug value
	Point pivot, target;
	int unique_points;
	
	// init the data
	// set_static_points(points);
	construct_data_set(points, N, XY);
	
	// construct a vector of PairPointEdge
	for(auto from = points.begin(); from != points.end(); ++from) {
		Edges *ev = new Edges;
		for(auto to = points.begin(); to != points.end(); ++to) {
			if(to == from) continue;
			// construct a new edge
			Edge *e = new Edge;
			e->from = *from;
			e->to = *to;
			e->gradient = (to->y - from->y) / (to->x - from->x);
			e->radians = atan(e->gradient);
			if (e->radians < 0.0) e->radians += M_PI;
			e->used = 0;

			// add to edge vector ev
			(*ev).push_back(*e);
		}
		// sort the vector on ascending radian values
		std::sort((*ev).begin(), (*ev).end(), compare_radians);
		// add edge vector to main vector using from as key and edge vector as value
		PointEdges pair = std::make_pair(*from,ev);
		vect_point_edges.push_back(pair);
	}
	
	// Debug printout
	prt_pair_vector(&vect_point_edges, true);
	// ----- --------
	
	// Using each entry in vect_point_edges as starting point

	
	for(auto start = vect_point_edges.begin(); start != vect_point_edges.end(); ++start) { // Trajectories loop
		
		pivot = (*start).first;
		
//----------------------------------------------------------------------
		// clear all 'used' values to false
		for(auto x = vect_point_edges.begin(); x != vect_point_edges.end(); ++x) {
			Edges *ev = x->second;
			for(auto y = ev->begin(); y != ev->end(); ++y) {
				y->used = 0;
			}
		}
//----------------------------------------------------------------------
			
		trajectory.clear();
		current_rotation = 0.0;		
		std::cout << "===========================\n\n";
		
		while(1) {
			// find pivot
			for(pivot_select = vect_point_edges.begin(); pivot_select != vect_point_edges.end(); ++pivot_select) 
				if(compare_points( (*pivot_select).first, pivot) == 1) break;
			if(pivot_select == vect_point_edges.end()) {
				std::cout << "Error: Initial pivot not found.";
				NL;
				exit(1);
			}
			// test the last value of radians in the edges vector
			target_select = (((*pivot_select).second)->end()) - 1;
			// reset current_rotation if necessary
			if(current_rotation >= (*target_select).radians) current_rotation = 0.0;
			
			target_select = ((*pivot_select).second)->begin();
			while(current_rotation > (*target_select).radians) ++target_select;
			
			if((*target_select).used != 0) {
				break; // breakout while loop
			}
			
			pivot = (*target_select).from;
			target = (*target_select).to;
			(*target_select).used = 99;
			// add these values to trajectories
			trajectory.push_back(std::make_pair(pivot,target));
			current_rotation = (*target_select).radians + 0.00001;
			pivot = target;
		}
		
		// print the trajectory vector<pair>
		for(auto x = trajectory.begin(); x != trajectory.end(); ++x) {
			prt_point(&((*x).first), false);
			prt_point(&((*x).second), true);
			NL;
		}
	
	std::cout << "Trajectory " << ++trajectory_index << " has " << trajectory.size() << " entries, using data set of " << N << " points.";
	NL;
	NL;

	} // Trajectories loop

	// Animate/Display each trajectory
	
	// Cleanup code - OS should free memory used by the process

	return 0;
}

