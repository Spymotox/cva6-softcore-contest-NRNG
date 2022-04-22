// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
//**********************************************************************
// Copyright (c) 2016-2018 Xilinx Inc.  All Rights Reserved
//**********************************************************************
//
//   TLM wrapper for NoC core. Excludes instances of agents (NMU/NSU/DDRMC)
//   Provides a sc_module anchor with a clock and connects to functional NoC
//
//**********************************************************************
#ifndef _NOCCoreTlmBase_h_
#define _NOCCoreTlmBase_h_

#include "properties.h"
#include <string>
#include <map>
#include <memory>

#include "NOCFlatAssembly.h"
#include "NOCMasterUnit.h"
#include "NOCSlaveUnit.h"
#include "NOCBehDDRSlaveUnit.h"

template <typename ExtProtocolAxiMMT=xtlm::xtlm_aximm_protocol_types,
          typename ExtProtocolAxiST =xtlm::xtlm_axis_protocol_types>
class NOCCoreTlmBase : public sc_core::sc_module {  
public:
  //typedef typename ExtProtocolT::tlm_payload_type TlmBaseTxn;
  typedef ::SimHrdIP::FuncSim::NocFlatModel
  <::SimHrdIP::FuncSim::NppProtocolTraits<>,
    ExtProtocolAxiMMT, ExtProtocolAxiST> FuncModel;

  NOCCoreTlmBase( sc_core::sc_module_name, const xsc::common_cpp::properties& );
  ~NOCCoreTlmBase();

  sc_core::sc_in_clk   noc_clk;
  sc_core::sc_in<bool> noc_rst_n;

  static FuncModel& getModel();

private:
  virtual void end_of_elaboration();  
  virtual void start_of_simulation();
  virtual void end_of_simulation();
  class Detail; std::unique_ptr<Detail> m_detail;
};

#endif


