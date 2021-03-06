/**
 * \file FrameParser.h
 * \brief 
 *
 * Copyright (c) 2016, Florian Evers, florian-evers@gmx.de
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *     (1) Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 
 *     (2) Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.  
 *     
 *     (3)The name of the author may not be used to
 *     endorse or promote products derived from this software without
 *     specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef HDLC_FRAME_PARSER_H
#define HDLC_FRAME_PARSER_H

#include <vector>
#include "HdlcFrame.h"
class ProtocolState;

class FrameParser {
public:
    FrameParser(ProtocolState& a_ProtocolState);
    void Reset();
    void AddReceivedRawBytes(const unsigned char* a_Buffer, size_t a_Bytes);
    
private:
    // Interal helpers
    size_t AddChunk(const unsigned char* a_Buffer, size_t a_Bytes);
    bool RemoveEscapeCharacters();
    HdlcFrame DeserializeFrame(const std::vector<unsigned char> &a_UnescapedBuffer) const;
    
    // Members
    ProtocolState& m_ProtocolState;

    enum { max_length = 1024 };
    std::vector<unsigned char> m_Buffer;
    bool m_bStartTokenSeen;
};

#endif // HDLC_FRAME_PARSER_H
