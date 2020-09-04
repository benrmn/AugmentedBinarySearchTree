/*****************************************
** File:    proj2aux.cpp
** Project: CSCE 221 Project 2
** Author:  Benjamin Ramon
** Date:    03/05/2020
** Section: 518
** E-mail:  bramon24@tamu.edu
**
**  C++ file:
**	Breif Description of the file
** contains all methods to cerr to errors.txt and reading in inputs.txt and commands.txt
**
**
*******************************************/

#ifndef PROJ2AUX_CPP
#define PROJ2AUX_CPP

#include "AugmentedBinarySearchTree.h"
#include "Exception.h"
#include "proj2aux.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// printing a command, does not need cerr
void proj2aux::DoPrintCommand(string command, int depth) {
  std::cout << "\n" << command << " " << depth << ": ";
  m_tree.PrintLevels(depth);
}

// printing remove, remove doesnt need cerr
void proj2aux::DoRemoveCommand(string command, int element) {
  std::cout << "\n" << command << " " << element << ": ";
  int flag = m_tree.remove(element);
  // checks if remove failed or success from output of remove()
  if (flag) {
    std::cout << "SUCCESS" << std::endl;
  } else {
    std::cout << "FAILED" << std::endl;
  }
}

// print median command, need to try and see if there is an error, if there is catch it
int proj2aux::GetMedanCommand(string command) {
  int n;
	  try {
		  n = m_tree.Median();
	  } catch (exception &excep) {
		  cerr << excep.what() << endl;// cerr to errors.txt
		  n = -1;
		}
  std::cout << "\n" << command << ": " << n << std::endl;
  return n;
}

// print nthElement command, need to try and see if there is an error, if there is catch it
int proj2aux::GetNthElementCommand(string command, int nthElement) {
  int n;
  try {
	  n = m_tree.NthElement(nthElement);
  } catch (exception &excep) {
      cerr << excep.what() << endl;// cerr to errors.txt
      n = -1;
    }
  std::cout << "\n" << command << " " << nthElement << ": " << n << std::endl;
  return n;
}

// print rank command, need to try and see if there is an error, if there is catch it
int proj2aux::GetRankCommand(string command, int element) {
	int n;
	  try {
		  n = m_tree.Rank(element);
	  } catch (exception &excep) {
		  cerr << excep.what() << endl;// cerr to errors.txt
		  n = -1;
		}
  std::cout << "\n" << command << " " << element << ": " << n << std::endl;
  return n;
}

// prints remove residue
int proj2aux::GetResidualsCommand(string command) {
  std::cout << "\n" << command << ": " << m_tree.RemoveResidue() << std::endl;
  return m_tree.RemoveResidue();
}

/*bool proj2aux::IsComplete(string command) {
  return m_tree.IsComplete();
}*/

// same process as remove
bool proj2aux::IsPerfect(string command) {
  bool flag = m_tree.IsPerfect();
  std::cout << "\n" << command << ": ";
  // cheks output to determine what to print
  if (flag) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
  return m_tree.IsPerfect();
}

int proj2aux::ReadFromCommandFile(char* commandFile) {
  inFile.open(commandFile);
  if (!inFile.is_open()) { return 0; }
  fstream efile;
  efile.open("errors.txt", ios::out);
  // save original place for buffer
  streambuf* tempTxt = efile.rdbuf();
  // redirect buffer
  streambuf* stream_buffer_cerr = cerr.rdbuf();
  cerr.rdbuf(tempTxt);
  string line; string eline;
  while (getline(inFile, line)) {
    // stream in each line separting into commands
    istringstream ss(line);
    string command;
    int num;
    while (ss >> command) {
      // located and calls each command based on what is read in, ignores commants #
      if (command.find('#') != std::string::npos) {
        break;
      } else if (command == "PRINT") {
        ss >> num;
        DoPrintCommand(command, num);
      } else if (command == "REMOVE") {
        ss >> num;
        DoRemoveCommand(command, num);
      } else if (command == "MEDIAN") {
        GetMedanCommand(command);
      } else if (command == "NTH") {
        ss >> num;
        GetNthElementCommand(command, num);
      } else if (command == "RANK") {
        ss >> num;
        GetRankCommand(command, num);
      } else if (command == "RESIDUALS") {
        GetResidualsCommand(command);
      } else if (command == "PERFECT") {
        IsPerfect(command);
      } else if (command == "COMPLETE") {
        // excpetion since i did not implement complete
        cerr << "COMPLETE command has not been implemented";
      } else {
        // if we get here the caommand is invalid and throw and cathc error
          try {
        throw CommandNotFound(command);
      } catch (exception &excep) {
          cerr << excep.what() << endl;
          break;
        }
      }
    }
  }
  inFile.close();
  cerr.rdbuf(stream_buffer_cerr);
  efile.close();
  // close fstreams and reset buffers
  return 1;
}

int proj2aux::ReadFromInputFile(char* inputFile) {
  inFile.open(inputFile);
  if (!inFile.is_open()) {
    // open file properly
    return 0;
  }
  string line;
  while (getline(inFile, line)) {
    // read in from file
    istringstream ss(line);
    int num;
    while (ss >> num) {
      m_tree.insert(num);
      // insert vales into the tree
    }
  }
  inFile.close();
  // close file
  return 1;
}

#endif
