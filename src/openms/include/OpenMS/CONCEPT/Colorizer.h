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
// $Maintainer: Moritz Berger ; Tetana Krymovska$
// $Authors: Moritz Berger ; Tetana Krymovska$
// --------------------------------------------------------------------------

#pragma once

//#include <OpenMS/KERNEL/MSExperiment.h>

#include <iosfwd>
#include <sstream>
#include <array>
//#include <OPENMS_DLLAPI>





namespace OpenMS
{

  /**
   * @brief A class, that provides options for coloring String output with the "<<" Operator
   *
   */
  class Colorizer
  {

  public:
    /** @name Constructors and Destructor
     */
    //@{
    Colorizer(int color); 

    /// Copy constructor
    //Colorizer(const Colorizer &rhs);

    /// Default destructor
    ~Colorizer();
    //@}

    
    auto getColor(int i = -1);
    std::string getText();
    bool getReset() {return this->reset;}

//operator overloading
    friend std::ostream &operator<<(std::ostream &o_stream, Colorizer& col);
    
    
    
    template <typename T>
    Colorizer& operator()(T s)
    {
      //clear was not possible (resets some flags in the sream)
      //std::string str = "";
      this->_input.str("");
      this->_input << s;
     

      (this->_input.str() == "")? this->reset = false: this->reset = true;
      
      return *this;
    }
    Colorizer& operator()()
    {
      
      this ->reset = false;
      this->_input.str("");
      return *this;
    }

/*
//klammer operator, um die farbigen Text an eine funktion übergeben zu können. 
    template <typename T>
    friend std::string operator()(T s)
    {

      std::stringstream text;
      text << this;
      return text.str();  
    }
*/
   

  private:
    //std::string _text;
    const int _color;
    std::stringstream _input;
    bool reset = true;
#if defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
    int _defcolor;
#endif
   //ewnum für farbauswahl



/**
     * @brief constant string array which saves the Linux color codes.
     * 0=black
     * 1=red
     * 2=green
     * 3=yellow
     * 4=blue
     * 5=magenta
     * 6=cyan
     * 7=white
     * 8=default console color (reset)
     *
     */
#if defined(__linux__) || defined(__OSX__)
    inline static const std::array<const char*,9> colors {"\033[30m", "\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m", "\033[37m", "\033[0m"};
#elif defined(_WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(_WIN64)
    inline static const std::array<const int,9> colors {16,12,10,14,9,13,11,15,15};
#endif
  };



  extern /*OPENMS_DLLAPI*/ Colorizer color_black;
  extern /*OPENMS_DLLAPI*/ Colorizer make_red;
  extern /*OPENMS_DLLAPI*/ Colorizer make_green;
  extern /*OPENMS_DLLAPI*/ Colorizer make_yellow;
  extern /*OPENMS_DLLAPI*/ Colorizer make_blue;
  extern /*OPENMS_DLLAPI*/ Colorizer make_magenta;
  extern /*OPENMS_DLLAPI*/ Colorizer make_cyan;
  extern /*OPENMS_DLLAPI*/ Colorizer make_white;
  extern /*OPENMS_DLLAPI*/ Colorizer make_def;



  template <typename T = std::string>
  extern std::string black(T s = T(" "))
  {
    std::stringstream text;
    text << color_black(s);
      return text.str(); 
}
  template <typename T = std::string>
  extern std::string red(T s = T(""))
  {
    std::stringstream text;
    text << make_red(s);
      return text.str(); 
}
  template <typename T= std::string>
  extern std::string green(T s)
  {
    std::stringstream text;
    text << make_green(s);
      return text.str(); 
}
  template <typename T= std::string>
  extern std::string yellow(T s = T("") )
  {
    std::stringstream text;
    text << make_yellow(s);
      return text.str(); 
}
  template <typename T= std::string>
  extern std::string blue(T s = T(""))
  {
    std::stringstream text;
    text << make_blue(s);
      return text.str(); 
}
  template <typename T= std::string>
  extern std::string magenta(T s = T(""))
  {
    std::stringstream text;
    text << make_magenta(s);
      return text.str(); 
}
  template <typename T = std::string>
  extern std::string cyan(T s = T(""))
  {
    std::stringstream text;
    text << make_cyan(s);
      return text.str(); 
}
  template <typename T= std::string>
  extern std::string white(T s = T(""))
  {
    std::stringstream text;
    text << make_white(s);
      return text.str(); 
}
  template <typename T = std::string>
  extern std::string def(T s = T(""))
  {
    std::stringstream text;
    text << make_def(s);
      return text.str(); 
}

/*
  Colorizer red(std::string text);
  Colorizer green(std::string text);
  Colorizer yellow(std::string text);
  Colorizer cyan(std::string text);

  //Colorizer blue(const char *text);
  Colorizer red(const char *text);
  Colorizer green(const char *text);
  Colorizer yellow(const char *text);
  Colorizer cyan(const char *text);*/
}










