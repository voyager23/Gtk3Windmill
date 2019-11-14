/*
 * windmill.h
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



#ifndef __WINDMILL_H__
	#define __WINDMILL_H__

	#include <cmath>
	#include <cstdio>
	#include <iostream>
	#include <iomanip>
	#include <cstdlib>
	#include <algorithm>
	#include <vector>
	#include <algorithm>
	#include <unordered_map>
	
	#include <gtk/gtk.h>
		
	const int N = 5;	// Number of points
	const int Nseg = N * (N-1) / 2;		// Number of pairs
	const int XY = 512;	// Square window size - X & Y
	const int PASSCOUNT = 128;

	typedef struct {
		double x,y;
	} Point;
	
	typedef struct {
		Point from;
		Point to;
		double gradient;
		double radians;
		bool used;
	} Edge;
	
	typedef std::vector<Edge> Edges;
	
	typedef std::unordered_map<Point, Edges> EdgeMap;
	
// Function declarations

	void set_static_points(std::vector<Point>&);

#endif

