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
// $Maintainer: Chris Bielow $
// $Authors:  Chris Bielow $
// --------------------------------------------------------------------------

#pragma once

#include <OpenMS/DATASTRUCTURES/String.h>

namespace OpenMS
{

  class OPENMS_DLLAPI ConsoleUtils
  {
public:
    /// make a string console friendly
    /// by breaking it into multiple lines according to the console width
    /// The 'indentation' gives the number of spaces which is prepended beginning at the second (!)
    /// line, so one gets a left aligned block which has some space to the left.
    /// An indentation of 0 results in the native console's default behaviour: just break at the end of
    /// its width and start a new line.
    /// but usually one wants nicely indented blocks, which the console does not support
    /// 'max_lines' gives the upper limit of lines returned after breaking is finished. 
    /// Excess lines are removed and replaced by '...', BUT the last line will be preserved.
    /// @param input String to be split
    /// @param indentation Number of spaces to use for lines 2 until last line.
    /// @param max_lines Limit of output lines (all others are removed)
    static String breakString(const String& input, const Size indentation, const Size max_lines);

    static int getConsoleWidth();


#ifdef OPENMS_WINDOWSPLATFORM

    /// reset the color of the windows output handle
    void resetCoutColor();
    /// reset the color of the windows error handle
    void resetCerrColor();

#endif

private:
    /// width of console we are currently in (if not determinable, set to 80 as default)
    int console_width_;

    /// read console settings for output shaping
    int readConsoleSize_();

    /// return console width
    int getConsoleWidth_(); 

    /// returns a console friendly version of input
    String breakString_(const String& input, const Size indentation, const Size max_lines);

    /// C'tor
    ConsoleUtils();

    /// Copy C'tor
    ConsoleUtils(const ConsoleUtils &);

    /// Destructor
    ~ConsoleUtils();

    /// Assignment operator
    void operator=(ConsoleUtils const&);

#ifdef OPENMS_WINDOWSPLATFORM
    
    /// reset the color of both output streams
    void resetConsoleColor_();

    /// Default console color for output stream
    int default_cout_;

    /// Default console color for error stream
    int default_cerr_;

#endif
  };


  
  class IndentedStringStream
  {
  public:
    IndentedStringStream(std::ostream& stream, const Size indentation, const Size max_lines)
    : stream_(&stream),
      indentation_(indentation),
      max_lines_(max_lines),
      current_column_pos_(0)
    {
      max_line_width_ = ConsoleUtils::getConsoleWidth_();
    }

    template<class T>
    IndentedStringStream& operator<<(const T& data)
    {
      std::stringstream s;
      s << data;
      const auto& string_to_print = s.str();
      // length?
      // needs splitting?
      // update current_column_pos_

    }

    template<>
    IndentedStringStream& operator<< <Colorizer>(const Colorizer& colorizer)
    {
      colorizer.applyColor(*stream_);
      this->operator<<(colorizer.getDataAsString());
      colorizer.undoColor(*stream_);
    }

  private:
    std::ostream* stream_;
    Size indentation_;
    Size max_lines_;
    int max_line_width_;
    Size current_column_pos_;
  };

} // namespace OpenMS

