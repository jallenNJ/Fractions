# Fractions

## Summary
This mini library is designed to be a simple and light-weight include that can accurately represent, store, and complete mathmatical operations on rationial numbers without the limitations of floating point math. 

## Installation
Download the Fraction.h and Fraction.cpp files and place them in the soruce code directory of the project. Then include them as any other user-made file. 
The file UnitTest.cpp is provided to allow for simple unit tests to ensure functionality, and can be safely discarded if not needed. 

## Dependencies
In order to ensure the lightweight nature of this mini-library, the only dependency is the math.h include file for C++ 99 or later. 
In order to use the included UnitTest.cpp that file expands the dependncy to the native assert.h for the assert macro. 

## Features
This script is able to store a rationial number in the form p / q where p and q are both integers and q does not equal zero. If q is zero, q is set to one and the undefined flag within the object is set to true. 

A Fraction object can be intialized from two seperate integers, specifing the numerator and denominator, or from a float.

### In the current version, a Fraction object can:
- Reduce itself to simpliest terms
- Scale up 
- Add another fraction or whole number
- Convert to a float
- Convert to an int


## Author
[Joseph Allen](https://github.com/jallenNJ) 
