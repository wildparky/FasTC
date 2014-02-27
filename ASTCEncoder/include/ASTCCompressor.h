/* FasTC
 * Copyright (c) 2014 University of North Carolina at Chapel Hill.
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for educational, research, and non-profit purposes, without
 * fee, and without a written agreement is hereby granted, provided that the
 * above copyright notice, this paragraph, and the following four paragraphs
 * appear in all copies.
 *
 * Permission to incorporate this software into commercial products may be
 * obtained by contacting the authors or the Office of Technology Development
 * at the University of North Carolina at Chapel Hill <otd@unc.edu>.
 *
 * This software program and documentation are copyrighted by the University of
 * North Carolina at Chapel Hill. The software program and documentation are
 * supplied "as is," without any accompanying services from the University of
 * North Carolina at Chapel Hill or the authors. The University of North
 * Carolina at Chapel Hill and the authors do not warrant that the operation of
 * the program will be uninterrupted or error-free. The end-user understands
 * that the program was developed for research purposes and is advised not to
 * rely exclusively on the program for any reason.
 *
 * IN NO EVENT SHALL THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL OR THE
 * AUTHORS BE LIABLE TO ANY PARTY FOR DIRECT, INDIRECT, SPECIAL, INCIDENTAL,
 * OR CONSEQUENTIAL DAMAGES, INCLUDING LOST PROFITS, ARISING OUT OF THE USE OF
 * THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE UNIVERSITY OF NORTH CAROLINA
 * AT CHAPEL HILL OR THE AUTHORS HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 *
 * THE UNIVERSITY OF NORTH CAROLINA AT CHAPEL HILL AND THE AUTHORS SPECIFICALLY
 * DISCLAIM ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE AND ANY 
 * STATUTORY WARRANTY OF NON-INFRINGEMENT. THE SOFTWARE PROVIDED HEREUNDER IS ON
 * AN "AS IS" BASIS, AND THE UNIVERSITY  OF NORTH CAROLINA AT CHAPEL HILL AND
 * THE AUTHORS HAVE NO OBLIGATIONS TO PROVIDE MAINTENANCE, SUPPORT, UPDATES, 
 * ENHANCEMENTS, OR MODIFICATIONS.
 *
 * Please send all BUG REPORTS to <pavel@cs.unc.edu>.
 *
 * The authors may be contacted via:
 *
 * Pavel Krajcevski
 * Dept of Computer Science
 * 201 S Columbia St
 * Frederick P. Brooks, Jr. Computer Science Bldg
 * Chapel Hill, NC 27599-3175
 * USA
 * 
 * <http://gamma.cs.unc.edu/FasTC/>
 */

#ifndef ASTCENCODER_INCLUDE_ASTCCOMPRESSOR_H_
#define ASTCENCODER_INCLUDE_ASTCCOMPRESSOR_H_

#include "CompressionJob.h"

namespace ASTCC {

  // The size of the block for the ASTC data. This needs to be supplied
  // for every block stream, since ASTC defines texel weights to be less
  // than or equal to the block size in order to save bits when decompressing
  enum EASTCBlockSize {
    eASTCBlockSize_4x4,
    eASTCBlockSize_5x4,
    eASTCBlockSize_5x5,
    eASTCBlockSize_6x5,
    eASTCBlockSize_6x6,
    eASTCBlockSize_8x5,
    eASTCBlockSize_8x6,
    eASTCBlockSize_8x8,
    eASTCBlockSize_10x5,
    eASTCBlockSize_10x6,
    eASTCBlockSize_10x8,
    eASTCBlockSize_10x10,
    eASTCBlockSize_12x10,
    eASTCBlockSize_12x12,
  };

  // Takes a stream of compressed ASTC data and decompresses it into R8G8B8A8
  // format. The block size must be specified in order to properly
  // decompress the data.
  void Decompress(const FasTC::DecompressionJob &,
                  EASTCBlockSize blockSize);

}  // namespace ASTCC

#endif  // ASTCENCODER_INCLUDE_ASTCCOMPRESSOR_H_
