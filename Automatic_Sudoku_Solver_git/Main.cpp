#include "SudokuSolver.h"

void DisplayArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
	std::cout << std::endl;
}

void DisplayGrid(int** array, int sqs)
{
	int size = sqs * sqs;
	for (int i = 0; i < size; ++i)
	{
		if (i > 0 && i % sqs == 0)
		{
			std::cout << std::string(2 * sqs, '-');
			std::cout << "|";
			std::cout << std::string(2 * sqs + 1, '-');
			std::cout << "|";
			std::cout << std::string(2 * sqs, '-') << std::endl;
		}
		for (int j = 0; j < size; ++j)
		{
			if (j > 0 && j % sqs == 0)
			{
				std::cout << "| ";
			}
			std::cout << array[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}


// Naive algorithm (Risk of crashing your PC for complicated sudokus!!)

//bool possible(int** grid, int ai, int aj, int val, int sqs)
//{
//	int size = sqs * sqs;
//
//	for (int j = 0; j < size; ++j)
//	{
//		if (grid[ai][j] == val)
//			return false;
//	}
//
//	for (int i = 0; i < size; ++i)
//	{
//		if (grid[i][aj] == val)
//			return false;
//	}
//
//	int imin = sqs * (ai / sqs);
//	int jmin = sqs * (aj / sqs);
//	for (int i = imin; i < imin + sqs; ++i)
//	{
//		for (int j = jmin; j < jmin + sqs; ++j)
//		{
//			if (grid[i][j] == val)
//				return false;
//		}
//	}
//
//	return true;
//}
//
//void SolveSudokuNaive(int** grid, std::list<int**>* listposs, int sqs)
//{
//	int size = sqs * sqs;
//	int** ansgrid = new int* [size];
//	for (int i = 0; i < size; ++i)
//	{
//		ansgrid[i] = new int[size];
//		for (int j = 0; j < size; ++j)
//		{
//			ansgrid[i][j] = grid[i][j];
//		}
//	}
//
//	int** ansgrid2 = new int* [size];
//	for (int i = 0; i < size; ++i)
//	{
//		ansgrid2[i] = new int[size];
//		for (int j = 0; j < size; ++j)
//		{
//			ansgrid2[i][j] = grid[i][j];
//		}
//	}
//
//	for (int i = 0; i < size; ++i)
//	{
//		for (int j = 0; j < size; ++j)
//		{
//			if (ansgrid[i][j] == 0)
//			{
//				for (int k = 1; k <= size; ++k)
//				{
//					if (possible(ansgrid, i, j, k, sqs))
//					{
//						ansgrid2[i][j] = k;
//
//						SolveSudokuNaive(ansgrid2, listposs, sqs);
//						ansgrid2[i][j] = 0;
//					}
//				}
//				return;
//			}
//		}
//	}
//
//	(*listposs).push_back(ansgrid);
//	return;
//
//}

int main() {

	bool onesolution = true;       // If true, displays only one solution. If false, displays every solutions (do not do that if grid has less than ~15 no-zeros elements, or it might take a while!)
	bool dispsteps = false;         // Display all the steps of the calculations. If you are in multi-solutions mode, just use this function if you have a very small number of solutions, otherwise it could be extremely long!!

	bool dispallsol = false;        // Displayevery solutions, only for multi-solutions mode. Can be extremely long if your sudoku grid has many zeros!!

	// Definition of the grid

	int n = 3;
	int N = n * n;


	// Grid definition

	int grid0[9][9] =
	{
	{0,3,8,    0,5,0,    0,0,0},
	{6,0,2,    0,0,4,    1,8,0},
	{0,0,0,    0,0,0,    0,0,0},

	{0,8,6,    0,0,1,    9,3,0},
	{0,4,0,    0,0,0,    0,6,0},
	{0,9,3,    0,0,0,    4,5,0},

	{0,0,0,    0,0,0,    0,0,0},
	{0,1,4,    6,0,0,    5,0,3},
	{0,0,0,    0,3,0,    6,4,0}
	};




	// If you want to define a new grid, just copy paste this one above and fill the zeros with whatever numbers you want between 0 and 9
	// Zero corresponds to an empty cell


	/*
	int grid0[9][9] =
	{
	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0},

	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0},

	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0},
	{0,0,0,    0,0,0,    0,0,0}
	};
	*/




	// The next grid are taken from the Sudoku app made by Beetles studio on the Google Play store
	// For each grid, we also have the corresponding difficulty in the app


	// Expert

	/*
	int grid0[9][9] =
	{
	{0,3,8,    0,5,0,    0,0,0},
	{6,0,2,    0,0,4,    1,8,0},
	{0,0,0,    0,0,0,    0,0,0},

	{0,8,6,    0,0,1,    9,3,0},
	{0,4,0,    0,0,0,    0,6,0},
	{0,9,3,    2,0,0,    4,5,0},

	{0,0,0,    0,0,0,    0,0,0},
	{0,1,4,    6,0,0,    5,0,3},
	{0,0,0,    0,3,0,    6,4,0}
	};
	*/

	//Extrême

	/*
	int grid0[9][9] =
	{
	{0,0,0,    7,0,1,    0,0,0},
	{0,0,0,    0,0,0,    0,4,2},
	{0,3,0,    0,0,0,    0,0,0},

	{2,0,0,    0,6,0,    0,0,0},
	{0,0,0,    3,0,0,    9,0,0},
	{8,0,4,    0,0,0,    0,0,0},

	{0,0,0,    1,3,0,    0,0,0},
	{0,0,0,    0,2,4,    0,0,0},
	{0,7,0,    0,0,0,    5,0,0}
	};
	*/


	// Empty 16 x 16

	/*
	int grid0[16][16] =
	{
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},

		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},

		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},

		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
		{0,0,0,0,      0,0,0,0,      0,0,0,0,      0,0,0,0},
	};
	*/


	// 16 x 16 (10 corresponds to A, 11 corresponds to B, and so on)

	/*
	int grid0[16][16] =
	{
		{0,11,12,14,      0,13,2,0,      0,3,0,0,      0,4,7,0},
		{0,13,0,0,      5,0,0,16,      0,4,7,0,      0,1,0,14},
		{10,3,0,0,      9,1,0,0,      0,0,0,14,      6,15,0,0},
		{9,4,0,0,      7,14,0,15,      10,0,0,0,      3,0,5,0},

		{0,2,0,11,      1,0,0,12,      0,0,0,3,      0,10,13,0},
		{16,12,6,4,      11,0,0,5,      13,15,9,10,      7,0,0,0},
		{0,8,0,0,      0,0,0,10,      0,0,16,4,      0,0,9,15},
		{13,9,0,10,      0,0,0,0,      0,1,0,7,      4,8,0,11},

		{0,16,0,0,      0,15,0,0,      3,13,2,0,      5,12,6,10},
		{3,6,4,0,      8,0,10,13,      0,0,1,0,      0,0,16,2},
		{8,0,2,5,      0,11,6,0,      16,14,10,12,      0,0,0,0},
		{7,0,15,13,      0,0,16,14,      0,9,5,0,      0,0,0,0},

		{0,0,0,6,      12,4,14,0,      9,0,8,2,      0,5,10,3},
		{0,0,0,1,      0,6,0,11,      0,0,0,5,      8,2,12,16},
		{2,0,0,0,      15,16,0,0,      0,0,4,0,      0,13,1,0},
		{12,15,3,16,      0,8,5,0,      14,7,0,0,      11,9,4,0},
	};
	*/




	// Copy the grid to an "int** format"

	int** grid = new int* [N];

	for (int i = 0; i < N; ++i)
	{
		grid[i] = new int[N];
		for (int j = 0; j < N; ++j)
		{
			grid[i][j] = grid0[i][j];
		}
	}


	SudokuSolver sudokusolver(grid, dispsteps, n);
	std::cout << "Starting grid : " << std::endl << std::endl;
	sudokusolver.DisplayGrid();
	std::cout << std::endl << std::endl << std::endl;

	// Only one solution

	if (onesolution)
	{
		const clock_t begin_time = clock();
		sudokusolver.CalculateSolution(-1, -1, 0);
		std::cout << "The Sudoku is solved" << std::endl << std::endl;
		std::cout << "Time : " << float(clock() - begin_time) / CLOCKS_PER_SEC;
		std::cout << std::endl << std::endl;
		std::cout << "Solution : " << std::endl << std::endl;
		sudokusolver.DisplayGrid();
		std::cout << std::endl << std::endl << std::endl;
	}

	// All the solutions

	else {
		std::list<int**> listposs = {};
		const clock_t begin_time = clock();
		sudokusolver.CalculateEverySolutions(&listposs, -1, -1, 0);
		std::cout << "Time : " << float(clock() - begin_time) / CLOCKS_PER_SEC;
		std::cout << std::endl;

		int length = 0;
		for (int** gridsol : listposs)
		{
			length++;
		}

		if (length > 0)
		{
			std::cout << "Number of solutions : ";
			std::cout << length << std::endl << std::endl << std::endl;
			if (dispallsol)
			{
				if (length == 1)
				{
					std::cout << "Solution : " << std::endl << std::endl;
					for (int** grillesol : listposs)
					{
						DisplayGrid(grillesol, n);
						std::cout << std::endl << std::endl << std::endl;
					}
				}
				else {
					std::cout << std::endl << std::endl << std::endl;
					std::cout << "Every solutions : " << std::endl << std::endl;
					for (int** grillesol : listposs)
					{
						DisplayGrid(grillesol, n);
						std::cout << std::endl << std::endl << std::endl;
					}
				}
			}
		}
		else
		{
			std::cout << "No solutions " << std::endl;
		}


		for (int** grillesol : listposs)       // We delete the whole list to avoid overflow
		{
			for (int i = 0; i < N; ++i)
				delete[]grillesol[i];
			delete[]grillesol;
		}
	}


	return 0;
}