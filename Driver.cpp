/*****************************************
** File:    driver.cpp
** Project: CSCE 221 Project 2
** Author:  Lupoli
** Date: 03/05/2020
** Section:518
** E-mail:  bramon24@tamu.edu
**
**  C++ file:
**	Do NOT modify this file!
**
**	This is the Proj 2 driver that handles CL args
**      and gets the show on the road.
**
**     DON'T PANIC! Just let Vogons be Vogons...
**
*******************************************/

#include "proj2aux.h"


int main(int argc, char *argv[])
{

	//if it has the right number of arguments
	if (argc != 3)
	{
		cout << "Usage:  ./Proj2.out input.txt commands.txt\n\n";
		cout << "input.txt - The file that contains a list of integers";
		cout << " to be inserted into a BST.\n";
		cout << "commands.txt - The file that contains the commands";
		cout << " that will be run over the BST that was created.\n\n";
	}
	//AugmentedBinarySearchTree ABSTree = AugmentedBinarySearchTree();

	proj2aux sim;

	/* Create Augmented BST */
	/* Read from input file to BinarySearchTree  */
	if (!sim.ReadFromInputFile(argv[1]))
	{
		cerr << "File Not Found Error: Filename '"
			<< argv[1]
			<< "' not found\n";
		return 1; // Exit with an error
	}

	/* Read from Command file */
	if (!sim.ReadFromCommandFile(argv[2]))
	{
		cerr << "File Not Found Error: Filename '"
			<< argv[2]
			<< "' not found\n";
		return 1; // Exit with an error
	}
	return 0;
}
