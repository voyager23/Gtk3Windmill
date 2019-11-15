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
	PairVector vect_pair_point_edge;	// vector of std::pair<Point, Edges>
	
	
	// init the data
	set_static_points(points);
	
	// for each point
	//		construct a vector of edges. (Edges);
	//		add vector to unordered_map using 'from' as key and vector as value
	
	for(auto from = points.begin(); from != points.end(); ++from) {
		Edges *ev = new Edges;
		for(auto to = points.begin(); to != points.end(); ++to) {
			if(to == from) continue;
			// construct a new edge
			Edge e;
			e.from = *from;
			e.to = *to;
			e.gradient = 0.0;
			e.radians = 0.0;
			e.used = false;
			// add to edge vector ev
			(*ev).push_back(e);
		}
		// add edge vector to map using from as key and edge vector as value
		PairPointEdge pair = std::make_pair(*from,*ev);
		vect_pair_point_edge.push_back(pair);
	}
	
	prt_pair_vector(&vect_pair_point_edge, true);
	
	return 0;
}

