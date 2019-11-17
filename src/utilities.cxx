/*
 * utilities.cxx
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

void prt_point(Point *pp, bool nl) {
	// print contents of Point struct. Add NEWLINE if nl==true
	std::cout << "(" << pp->x << "," << pp->y << ")";
	(nl) ? std::cout << std::endl : std::cout << "\t"; 
}

void prt_edge(Edge *ep, bool nl) {
	// print contents of Edge structure. Add NEWINE if nl==true
	prt_point( &((*ep).from), false);
	prt_point( &((*ep).to), false);
	// gradient, radians, used
	std::cout << "\tGradient: " << (*ep).gradient << " ";
	std::cout << "Radians: " << (*ep).radians << " ";
	((*ep).used != 0) ? std::cout << "Used" : std::cout << "Not_Used";
	if (nl) {
		NL;
	} else {
		
	}
}

void prt_pair_vector(VectorPointEdge *ppv, bool nl) {
	std::cout << "PairVector contains:" << std::endl;
	for(auto x = (*ppv).begin(); x != (*ppv).end(); ++x) {
		prt_point(&((*x).first), true);
		Edges t = ((*x).second); //vector of Edge
		for(auto y = t.begin(); y != t.end(); ++y)
			prt_edge(&(*y), true);
		NL;
	}
	if(nl) NL;
}

void set_static_points(std::vector<Point>& points) {
	
	points.push_back(Point{240,450});	
	points.push_back(Point{176,28});
	points.push_back(Point{76,171});
	points.push_back(Point{479,248});
	points.push_back(Point{284,368});
		
}

int compare_radians(Edge& a,Edge& b) {
	return(a.radians < b.radians);
}

int compare_points(Point& a,Point& b) {
	// return 1 if point are equal else return zero;
	return ((a.x == b.x)&&(a.y == b.y));
}




