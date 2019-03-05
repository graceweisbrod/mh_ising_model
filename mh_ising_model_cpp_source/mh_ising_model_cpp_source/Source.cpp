#include <iostream>	
#include <cmath>
#include <fstream>
#include <random>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include <functional>
using namespace std;
//This program runs the M-H algorithm on the 2D Ising Model
//and computes mean energy for the lattice based on its
//spins.

//First, define some variables. Let us start with a 10x10 
//Ising model, and 10000 steps. This can be modified later.

const int x = 10;
const int y = 10; //number of x- and y- direction vertices/spins
int metropolisStep = 10000; //number of M-H random walk steps
int vertices = 100; //total number of vertices
int a; // x-spin
int b; //y-spin
int spin[x][y]; // total spin, indexed in x arrays of y integers
double energy; //energy lol
double energyDiff; //difference in energies between two states
double meanE; //mean energy, which we will be calculating!

//First, we need to randomly select an initial vertex.
//Our vertex will either be up or down, with energy values of 1 or -1,
//respectively. 
//Use <random> to help us! We want a generator with 32-bit precision.
//Should give us a fairly regular lattice structure...
//Let's just use Mersenne Twister for our purposes...I can go back and
//change it later if we decide we want a different generator.
void vertexselect() //Change this to void later!
{
	random_device value;
	mt19937 inl(value());
	uniform_real_distribution<double> val(0.0, 1.0);
	for (int a = 0; a < x; a++)
	{
		for (int b = 0; b < y; b++)
		{
			if (val(inl) < .5)
			{
				spin[a][b] = 1;
			}
			else
			{
				spin[a][b] = -1;
			}
		}

	}
	// fixed ratio of 1 : -1. Start with an array of all 1's; while loop randomly selecting vertices until correct proportions are reached
	//parameters: initial size, nxn; initial ratio of 1: -1; need to know j, b (only need j/b); 
	//choose vertex at random, select neighbor, flip or not flip; select next vertex
	//At intervals, output array of spins and print in greyscale .png
	//cout << "The initial vertex spin is:" << spin[a][b] << endl;
	
}
//Now, let's try and take some steps!
//We want to randomly select an initial spin, which will allow us to find its neighboring 
//vertices, according to the M-H algorithm.
int main()
{
	random_device value;
	mt19937 inl(value());
	uniform_int_distribution<int> val1(0, x);
	int a = val1(inl);
	uniform_int_distribution<int> val2(0, y);
	int b = val2(inl);
	//Let's determine neighboring spins.
	int lefta;
	if (a == 0)
	{
		lefta = x - 1;
	}
	else
	{
		lefta = a - 1;
	}
	int righta; 
	if (a == x - 1)
	{
		righta = 0;
	}
	else
	{
		righta = a + 1;
	}
	int leftb; 
	if (b == 0)
	{
		leftb = y - 1;
	}
	else
	{
		leftb = b - 1;
	}
	int rightb;
	if (b == y - 1)
	{
		rightb = 0;
	}
	else
	{
		rightb = b + 1;
	}
	cout << "Left x, right x; left y, right y " << lefta << righta << leftb << rightb;
	return 0;
//So, if I avoided messing things up, this should select one of two spins,
//and then flips them (assigns new values) according to MH algorithm.
}







