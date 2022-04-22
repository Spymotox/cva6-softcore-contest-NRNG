// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
//**********************************************************************
// Copyright (c) 2016-2018 Xilinx Inc.  All Rights Reserved
//**********************************************************************
//
//   TLM wrapper for NoC core. Excludes instances of agents (NMU/NSU/DDRMC)
//   Provides a sc_module anchor with a clock and connects to functional NoC
//
//**********************************************************************
#ifndef _NOCCoreTlm_h_
#define _NOCCoreTlm_h_

#include "tlm_cmnhdr.h"
#include "NOCCoreTlmBase.h"

using NOCCoreTlm = NOCCoreTlmBase <tlm::tlm_base_protocol_types,
                                   tlm::tlm_base_protocol_types>;

#endif


