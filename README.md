# Automatic_Sudoku_Solver

Here is my first big project in C++, which is an automatic Sudoku Solver.

To use it, simply define the grid you want to solve at the beginning of the main function. I added a few "template" grids to help you do that. Then, select whether you want:
- To calculate one possibility or every possibilities 
- To display the steps the computer makes to calculate the solution(s)
- To display only the number of solutions or also these solutions (only if you choose to calculate every possibilities)


To create it, I translated in C++ code the way I think when I'm solving myself a Sudoku, which is the following:
- Check if there is a line, column or box where a number can be in only one place (for example the number 7 has only one position to be in line 4)
- Check if there is a cell that has only one possible number
- If we have none of those, then we have to try several solutions. An important part of the project was to determine which solutions to try so we reduce drastically the calculation times.

If you see any bugs, please don't hesitate to tell me :)
