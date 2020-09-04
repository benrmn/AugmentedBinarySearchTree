/*****************************************
** File:    proj2aux.h
** Project: CSCE 221 Project 2
** Author:  Benjamin Ramon
** Date:    03/05/2020
** Section: 518
** E-mail:  bramon24@tamu.edu
**
**  C++ file:
**	Breif Description of the file
** contains all helpers to cerr to errors.txt and reading in inputs.txt and commands.txt
**
**
*******************************************/


#ifndef PROJ2AUX_H
#define PROJ2AUX_H

#include <fstream>
#include <sstream>
#include <iostream>       // For NULL

using namespace std;


/*----------------Includes---------------------*/

#include "AugmentedBinarySearchTree.h"
#include "Exception.h"

class proj2aux {
public:
  void DoPrintCommand(string command, int depth);
  void DoRemoveCommand(string command, int element);

  int GetMedanCommand(string command);
  int GetNthElementCommand(string command, int nthElement);
  int GetRankCommand(string command, int element);
  int GetResidualsCommand(string command);

  //bool IsComplete(string command);
  bool IsPerfect(string command);

  int ReadFromCommandFile(char* commandFile);
  int ReadFromInputFile(char* inputFile);

private:

  ifstream inFile;
  AugmentedBinarySearchTree<int> m_tree;

};

#endif
