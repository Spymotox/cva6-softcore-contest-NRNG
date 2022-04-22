// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
//**********************************************************************
// Copyright (c) 2013-2019 Xilinx Inc.  All Rights Reserved
//**********************************************************************
//
//   AXI TLM Extensions
//
//**********************************************************************
#include "TlmExtDef.h"

namespace xsc { namespace tlm_ext {

template class SingleValTlmExt< UniqPktId::type>              ;
template class SingleValTlmExt< AxiInfo>;

}}
