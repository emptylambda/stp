// -*- c++ -*-
/********************************************************************
 * AUTHORS: Trevor Hansen
 *
 * BEGIN DATE: July, 2010
 *
 * LICENSE: Please view LICENSE file in the home dir of this Program
 ********************************************************************/

/*
 * pimpl class to make compiling easier.
 */

#ifndef NODETOFIXEDBITSMAP_H_
#define NODETOFIXEDBITSMAP_H_

#include "stp/AST/AST.h"
#include "stp/Simplifier/constantBitP/FixedBits.h"

namespace simplifier
{
  namespace constantBitP
  {

    class NodeToFixedBitsMap
    {
    public:
      typedef hash_map<BEEV::ASTNode, FixedBits*,
          BEEV::ASTNode::ASTNodeHasher, BEEV::ASTNode::ASTNodeEqual>
          NodeToFixedBitsMapType;

      NodeToFixedBitsMapType* map;

      NodeToFixedBitsMap(int size)
      {
        map = new NodeToFixedBitsMapType(size);
      }
      virtual
      ~NodeToFixedBitsMap()
      {
        clear();
        delete map;
      }

      void
      clear()
      {
        NodeToFixedBitsMap::NodeToFixedBitsMapType::iterator itD = map->begin();
        for (; itD != map->end(); itD++)
          delete itD->second;
        map->clear();
      }
    };
  }
}

#endif /* NODETOFIXEDBITSMAP_H_ */
