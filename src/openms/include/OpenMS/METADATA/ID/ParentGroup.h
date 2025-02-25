// --------------------------------------------------------------------------
//                   OpenMS -- Open-Source Mass Spectrometry
// --------------------------------------------------------------------------
// Copyright The OpenMS Team -- Eberhard Karls University Tuebingen,
// ETH Zurich, and Freie Universitaet Berlin 2002-2022.
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
// $Maintainer: Hendrik Weisser $
// $Authors: Hendrik Weisser $
// --------------------------------------------------------------------------

#pragma once

#include <OpenMS/METADATA/ID/ParentSequence.h>

#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>

namespace OpenMS
{
  namespace IdentificationDataInternal
  {
    /** @brief: Group of ambiguously identified parent sequences (e.g. protein group)
    */
    // @TODO: derive from MetaInfoInterface?
    struct ParentGroup
    {
      std::map<ScoreTypeRef, double> scores;
      // @TODO: does this need a "leader" or some such?
      std::set<ParentSequenceRef> parent_refs;
    };

    typedef boost::multi_index_container<
      ParentGroup,
      boost::multi_index::indexed_by<
        boost::multi_index::ordered_unique<
        boost::multi_index::member<
          ParentGroup, std::set<ParentSequenceRef>,
          &ParentGroup::parent_refs>>>
      > ParentGroups;
    typedef IteratorWrapper<ParentGroups::iterator> ParentGroupRef;

    /** @brief Set of groups of ambiguously identified parent sequences (e.g. results of running a protein inference algorithm)
    */
    struct ParentGroupSet: public ScoredProcessingResult
    {
      String label; // @TODO: use "label" as a uniqueness constraint?
      ParentGroups groups;

      explicit ParentGroupSet(
        const String& label = "",
        const ParentGroups& groups = ParentGroups()):
        label(label), groups(groups)
      {
      }
    };

    typedef std::vector<ParentGroupSet> ParentGroupSets;

  }
}
