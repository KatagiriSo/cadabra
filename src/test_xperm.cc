/* 

	Cadabra: a field-theory motivated computer algebra system.
	Copyright (C) 2001-2011  Kasper Peeters <kasper.peeters@aei.mpg.de>

   This program is free software: you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
*/

extern "C" {
#include "modules/xperm.h"
}

#include <iostream>

void	test1() 
	{
	// v_r A_{m n} v_s A_{n m}
	const char *indexnames[6]={"r", "s", "m", "m", "n", "n"};
	int perm[8]={1,4,2,6,3,5,7,8};  // name to slot
	int cperm[8];
	int dummies[4]={2,6,3,5};       // pairs of slots 
	int dummysetlabels[4]={1,1,1,1};
	int number_of_dummy_pairs=2;
	int generating_set[2*8]={1,3,2,4,5,6,8,7,
									 1,2,3,5,4,6,8,7};
	int free_indices[2]={1,4};
	int number_of_free_inds=2;

	canonical_perm(perm, 
						0,               // not a strong generating set yet
						0,               // no base
						0,               // no base length
						generating_set,
						2,                // 2 elements in the generating set
						8,                // total number of indices + 2 (for sign)
						free_indices,
						number_of_free_inds,
						dummies,
						number_of_dummy_pairs,
						dummysetlabels,
						1,               // use an ordered base (what does this mean?)
						1,               // symmetric metric
						cperm);
	
	if(cperm[6]==8)
		std::cout << "- ";
	for(unsigned int i=0; i<8; ++i) {
		std::cout << cperm[i] << " ";
		}
	std::cout << std::endl;
	if(cperm[6]==8)
		std::cout << "- ";
	if(cperm[0]!=0) {
		for(unsigned int i=1; i<=6; ++i) {
			for(unsigned int pos=0; pos<6; ++pos) {
				if(cperm[pos]==(int)i)
					std::cout << indexnames[pos] << " ";
				}
			}
		std::cout << std::endl;
		}
	}

void test2()
	{
	int gs[26*37]={
		2, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		3, 2, 1, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		4, 2, 3, 1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 3, 2, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 4, 3, 2, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 4, 3, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 6, 5, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 7, 6, 5, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 8, 6, 7, 5, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 7, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 8, 7, 6, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 8, 7, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 10, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 11, 10, 9, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 12, 10, 11, 9, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 12, 11, 10, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 11, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 13, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 15, 14, 13, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 16, 14, 15, 13, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 15, 14, 16, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 16, 15, 14, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 15, 17, 18, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 18, 17, 19, 20, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20, 19, 21, 22, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 19, 20, 17, 18, 21, 22, 23, 24, 25, 26, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 21, 23, 24, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 24, 23, 26, 25, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 23, 24, 21, 22, 25, 26, 
		5, 6, 7, 8, 1, 2, 3, 4, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		9, 10, 11, 12, 5, 6, 7, 8, 1, 2, 3, 4, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		13, 14, 15, 16, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3, 4, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		1, 2, 3, 4, 9, 10, 11, 12, 5, 6, 7, 8, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		1, 2, 3, 4, 13, 14, 15, 16, 9, 10, 11, 12, 5, 6, 7, 8, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		1, 2, 3, 4, 5, 6, 7, 8, 13, 14, 15, 16, 9, 10, 11, 12, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 
		1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 21, 22, 23, 24, 17, 18, 19, 20, 25, 26 
	};
	// These lead to a segfault:
	int perm[26]={1, 23, 5, 13, 8, 16, 11, 17, 9, 18, 12, 20, 10, 24, 2, 21, 6, 14, 3, 22, 7, 15, 4, 19, 25, 26};
	int dummies[24]={1, 23, 5, 13, 8, 16, 11, 17, 9, 18, 12, 20, 10, 24, 2, 21, 6, 14, 3, 22, 7, 15, 4, 19};
	int dummysetlabels[24]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

	// H_{m1 m2 m3 m4} H_{m5 m6 m7 m8} H_{m9 m10 m11 m12} H_{m5 m6 m7 m8} W_{m11 m9 m4 m12} W_{m2 m3 m1 m10}

	// For comparison, these work:
	// int perm[26]={1, 17, 6, 13, 14, 24, 7, 15, 3, 12, 10, 16, 18, 22, 5, 23, 19, 21, 2, 11, 4, 9, 8, 20, 25, 26};
	// int dummies[24]={1, 17, 6, 13, 14, 24, 7, 15, 3, 12, 10, 16, 18, 22, 5, 23, 19, 21, 2, 11, 4, 9, 8, 20};

	int free_indices[2];
	int cperm[26];
	canonical_perm(perm, 
						0,               
						0,               
						0,               
						gs,
						37,              
						26,              
						free_indices,
						0,
						dummies,
						12,
						dummysetlabels,
						1,               
						1,               
						cperm);
	}

int main(int argc, char **argv)
	{
//	test1();
	test2();
	}
