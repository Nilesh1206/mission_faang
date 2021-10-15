// In this problem we are going to solve the sudoku

#include<bits/stdc++.h>
using namespace std;
#define N 9



bool isSafe(int num,int grid[N][N],int i,int j)
{
    // Check for the current row contains same value of not
    for(int k=0;k<N;k++)
    {
        // if value already present , then break the loop and return the false
        if(grid[i][k]==num)
        {
            return false;
        }
    }

    // Check for the current column contains same value or not

    for(int k=0;k<N;k++)
    {
        if(grid[k][j]==num)
        {
            return false;
        }
    }

    // check for every 3 boxes of row,col contain same value or not
    int xs=i-i%3;
    int ys=j-j%3;

    for(int k=0;k<3;k++)
    {
        for(int l=0;l<3;l++)
        {
            if(grid[k+xs][l+ys]==num)
            {
                return false;
            }
        }
    }

    // else value is not present 
    return true;
}

bool solve(int grid[N][N],int i,int j)
{
    // We have solve sudoku
    if(i==N-1 && j==N)
    {
        return true;
    }


    // Check if column value  becomes 9 ,
    // we move to next row and
    //  column start from 0
    if(j==N)
    {
        j=0;
        i++;
    }


    // Check if the current position of
    // the grid already contains
    // value >0, we iterate for next column
    if(grid[i][j]>0)
    {
        return solve(grid,i,j+1);
    }

    //check every possible value for the blank space
    for(int k=1;k<=9;k++)
    {
        // Check if it is safe to place
        // the num (1-9)  in the
        // given row ,col  ->we
        // move to next column
        if(isSafe(k,grid,i,j))
        {
            grid[i][j]=k;
            if(solve(grid,i,j+1))
            {
                return true;
            }
        }
        // Removing the assigned num ,
        // since our assumption
        // was wrong , and we go for
        // next assumption with
        // diff num value
        grid[i][j]=0;
    }

    return false;
}

int main()
{
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    if(solve(grid,0,0))
    {
        cout<<"Soltuion exists...!!"<<endl;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else
    {
        cout<<"Solution doesn't exist..!!!"<<endl;
    }
    return 0;

}


/*
Time complexity: O(9^(n*n)). 
    For every unassigned index there are 9 possible options so the time complexity is O(9^(n*n)).
Space Complexity: O(n*n). 
    To store the output array a matrix is needed.
*/
























// Another solution 
// Backtracking Approach


#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty
// cells in sudoku grid
#define UNASSIGNED 0

// N is used for the size of Sudoku grid.
// Size will be NxN
#define N 9

// This function finds an entry in grid
// that is still unassigned
bool FindUnassignedLocation(int grid[N][N],
							int& row, int& col);

// Checks whether it will be legal
// to assign num to the given row, col
bool isSafe(int grid[N][N], int row,
			int col, int num);

/* Takes a partially filled-in grid and attempts
to assign values to all unassigned locations in
such a way to meet the requirements for
Sudoku solution (non-duplication across rows,
columns, and boxes) */
bool SolveSudoku(int grid[N][N])
{
	int row, col;

	// If there is no unassigned location,
	// we are done
	if (!FindUnassignedLocation(grid, row, col))
		// success!
		return true;

	// Consider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{
		
		// Check if looks promising
		if (isSafe(grid, row, col, num))
		{
			
			// Make tentative assignment
			grid[row][col] = num;

			// Return, if success
			if (SolveSudoku(grid))
				return true;

			// Failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}
	
	// This triggers backtracking
	return false;
}

/* Searches the grid to find an entry that is
still unassigned. If found, the reference
parameters row, col will be set the location
that is unassigned, and true is returned.
If no unassigned entries remain, false is returned. */
bool FindUnassignedLocation(int grid[N][N],
							int& row, int& col)
{
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified row matches
the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry in the specified column
matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether
an assigned entry within the specified 3x3 box
matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow]
					[col + boxStartCol] ==
									num)
				return true;
	return false;
}

/* Returns a boolean which indicates whether
it will be legal to assign num to the given
row, col location. */
bool isSafe(int grid[N][N], int row,
			int col, int num)
{
	/* Check if 'num' is not already placed in
	current row, current column
	and current 3x3 box */
	return !UsedInRow(grid, row, num)
		&& !UsedInCol(grid, col, num)
		&& !UsedInBox(grid, row - row % 3,
						col - col % 3, num)
		&& grid[row][col] == UNASSIGNED;
}

/* A utility function to print grid */
void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}


int main()
{
	// 0 means unassigned cells
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		cout << "No solution exists";

	return 0;
}

/*
Complexity Analysis:  

Time complexity: O(9^(n*n)). 
    For every unassigned index, there are 9 possible options so the time complexity is O(9^(n*n)). 
    The time complexity remains the same but there will be some early pruning so the time taken will be 
    much less than the naive algorithm but the upper bound time complexity remains the same.
Space Complexity: O(n*n). 
    To store the output array a matrix is needed.
*/