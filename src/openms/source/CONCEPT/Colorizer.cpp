// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2021.
//
// This software is released under a three-clause BSD license:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of any author or any participating institution
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
// For a full list of authors, refer to the file AUTHORS.
// --------------------------------------------------------------------------
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL ANY OF THE AUTHORS OR THE CONTRIBUTING
// INSTITUTIONS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// --------------------------------------------------------------------------
// $Maintainer: Moritz Berger, Tetana Krymovska $
// $Authors: Moritz Berger, Tetana Krymovska$
// --------------------------------------------------------------------------

#include <OpenMS/CONCEPT/Colorizer.h>
//#include <OpenMS/CONCEPT/Colorizer.h>
#include <iostream>

#if defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
#include <windows.h>
#endif
/**

#include <OpenMS/DATASTRUCTURES/String.h>

#include <OpenMS/CONCEPT/Types.h>
#include <OpenMS/CONCEPT/Exception.h>
**/
namespace OpenMS
{

  /** @name Constructors and Destructor
   */
  //@{
  // constructor
  Colorizer::Colorizer(int color): _color(color)
  {
    //If we are on windows, get the "default" console color and safe it in _defcolor
    #if defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
    CONSOLE_SCREEN_BUFFER_INFO Info;
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hStdout, &Info);
    _defcolor = Info.wAttributes;
    #endif
    
  }

  /// Default destructor
  Colorizer::~Colorizer()
  {
    //if colorizer object is destroyed, set console color back to def col. 
    #if defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _defcolor);
    #elif defined(__linux__) || defined(__OSX__)
    std::cout << colors[8];
    #endif
  }
  //@}

  /**
  \fn getColor(int i)
  \details this function return the ANSI escape sequence for the color, saved in the Colorizer Object.
  \return std::string contaaining ANSI escape characters for colors
  \arg i codes for following colors:
   * 0=black
   * 1=red
   * 2=green
   * 3=yellow
   * 4=blue
   * 5=magenta
   * 6=cyan
   * 7=white
   * 8=default console color (reset)
  \return std::string contaaining ANSI escape characters for colors
  */
  auto Colorizer::getColor(int i)
  {
    //checking if parameter is outside array size or not set at all
    // Darf nicht NULL, da dadurch kein "black" mehr möglich ist
    return ((i == -1 || i > 8 || i < 0) ? this->colors[this->_color] : this->colors[i]);
  }

  std::string Colorizer::getText()
  { 

    return _input.str();
  }   
  // overload the shift operator (<<)
  std::ostream &operator<<(std::ostream &o_stream, OpenMS::Colorizer& col)
  {
    // colorize string with color set in the object
#if defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
   
    //set color of output   
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col.getColor());

    // paste text
    o_stream << col.getText();
    
    // recover old Console font and set it as new one.
    if(col.getReset()) 
    {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col._defcolor);
    }

#elif defined(__linux__) || defined(__OSX__)
    o_stream << col.getColor();

    o_stream << col.getText();
    //if flag reset is set: reset comand line. else dont reset.
    o_stream << ((col.getReset())? col.getColor(8):"");
#endif

    return o_stream;
  }


  // All color types (Linux/OSX)
  /*
  Black           30  40
  Red             31  41
  Green           32  42
  Yellow          33  43
  Blue            34  44
  Magenta         35  45
  Cyan            36  46
  White           37  47
  */

 //Objekte des typs colorizer
  OpenMS::Colorizer color_black(0);
  OpenMS::Colorizer make_red(1);
  //std::string red(std::string text)
  //{
   // return std::string(red(text));

  //}
  OpenMS::Colorizer make_green(2);


  OpenMS::Colorizer make_yellow(3);
  OpenMS::Colorizer make_blue(4);
  OpenMS::Colorizer make_magenta(5);
  OpenMS::Colorizer make_cyan(6);
  OpenMS::Colorizer make_white(7);
  OpenMS::Colorizer make_def(8);



 //free funct. make_color


}
