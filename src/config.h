#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

class Config
{
public:
  static Config& Instance()
  {
    static Config C;
    return C;
  };

  //should be getters, but didn't want to change the names after using them in the program
  int getHeight() const
  {
    //cout << "The window height has been set to " << w_height 				<< endl;
    return w_height;
  };

  int getWidth() const
  {
    //cout << "The width has been set to " << w_width << endl				;
    return w_width;
  };
  int circle() const
  {
    //cout << "The circle size has been set to " << c_size << 		       endl;
    return c_size;
  }
  int numCircles()
  {
    //cout << "The number of circles has been set to " 				<< c_num << endl;
    return c_num;
  }
  //getters
  //int getWindowHeight()
  //int getWindowWidth();
  //int getCircleSize();
  //int getNumCircles();
  //setters
  void setWindowHeight(int height)
  {
    w_height = height;
  };
  void setWindowWidth(int width)
  {
    w_width = width;
  };
  void setCircleSize(int size)
  {
    c_size = size;
  };
  void setNumCircles(int numCircles)
  {
    c_num = numCircles;
  };

  // read in fil & set data w/setters
  void readIn(char *fileName)
  {
    ifstream inFile;
    inFile.open(fileName);
    int value;
    int nums[4];

    if(inFile.fail())
    {
      cout << "Could not find file " << endl;
    }
    else
    {
      int i = 0;
      while(inFile >> value)
      {
        nums[i] = value;
        cout << value << endl;
        i++;
      }
      cout << "File opened, reading data" << endl;
    }

    //set values for each function
    setWindowHeight(nums[0]);
    setWindowWidth(nums[1]);
    setCircleSize(nums[2]);
    setNumCircles(nums[3]);
    //close file
    inFile.close();

  }

private:

  Config()
  {
    std::cout << "Creating!!!\n";
  }
  ~Config()
  {
    std::cout << "Destroyedddd!!!!\n";
  }

  int w_height;//window height
  int w_width; //window width
  int c_size; //circle size
  int c_num; //number of circles
};
