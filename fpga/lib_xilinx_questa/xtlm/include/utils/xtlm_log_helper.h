// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// (c) Copyright 2013 - 2018 Xilinx, Inc. All rights reserved.
//
// This file contains confidential and proprietary information
// of Xilinx, Inc. and is protected under U.S. and
// international copyright and other intellectual property
// laws.
//
// DISCLAIMER
// This disclaimer is not a license and does not grant any
// rights to the materials distributed herewith. Except as
// otherwise provided in a valid license issued to you by
// Xilinx, and to the maximum extent permitted by applicable
// law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
// WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
// AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
// BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
// INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
// (2) Xilinx shall not be liable (whether in contract or tort,
// including negligence, or under any other theory of
// liability) for any loss or damage of any kind or nature
// related to, arising under or in connection with these
// materials, including for any direct, or any indirect,
// special, incidental, or consequential loss or damage
// (including loss of data, profits, goodwill, or any type of
// loss or damage suffered as a result of any action brought
// by a third party) even if such damage or loss was
// reasonably foreseeable or Xilinx had been advised of the
// possibility of the same.
//
// CRITICAL APPLICATIONS
// Xilinx products are not designed or intended to be fail-
// safe, or for use in any application requiring fail-safe
// performance, such as life-support or safety devices or
// systems, Class III medical devices, nuclear facilities,
// applications related to the deployment of airbags, or any
// other applications that could lead to death, personal
// injury, or severe property or environmental damage
// (individually and collectively, "Critical
// Applications"). Customer assumes the sole risk and
// liability of any use of Xilinx products in Critical
// Applications, subject only to applicable laws and
// regulations governing limitations on product liability.
//
// THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
// PART OF THIS FILE AT ALL TIMES.
#include "utils/xtlm_cmnhdr.h"
#include "xtlm_generic_payload/aximm_payload.h"
#include "xtlm_generic_payload/axis_payload.h"

#ifndef _XTLM_LOG_HELPER_H_
#define _XTLM_LOG_HELPER_H_

namespace xtlm {
static std::string tab("  ");

inline void get_nb_transport_log(const xtlm::aximm_payload& trans,
		const tlm::tlm_phase& phase, const sc_core::sc_time& delay,
		std::string& log, const unsigned int& level) {
	if (level == 0) {
		return;
	}

	std::stringstream msg("");
	std::string payload_str("");
	trans.get_log(payload_str, level);
	msg << tab << "Phase:: " << phase << "\n";
	msg << tab << "Delay:: " << delay << "\n";
	msg << tab << "Payload\n";
	msg << payload_str;
	log += msg.str();
}

inline void get_b_transport_log(const xtlm::axis_payload& trans,
  const sc_core::sc_time& delay, std::string& log,
  const unsigned int& level) {
  if (level == 0) {
    return;
  }
  std::string payload_str("");
  std::stringstream msg("");
  trans.get_log(payload_str, level);
  msg << tab << "Delay:: " << delay << "\n";
  msg << tab << "Payload\n";
  msg << payload_str << "\n";
  log += msg.str();
}

inline void get_b_transport_log(const xtlm::aximm_payload& trans,
		const sc_core::sc_time& delay, std::string& log,
		const unsigned int& level) {
	if (level == 0) {
		return;
	}
	std::string payload_str("");
	std::stringstream msg("");
	trans.get_log(payload_str, level);
	msg << tab << "Delay:: " << delay << "\n";
	msg << tab << "Payload\n";
	msg << payload_str << "\n";
	log += msg.str();
}

inline void get_nb_transport_log(const xtlm::axis_payload& trans,
		const tlm::tlm_phase& phase, const sc_core::sc_time& delay,
		std::string& log, const unsigned int& level) {
	if (level == 0) {
		return;
	}

	std::stringstream msg("");
	std::string payload_str("");
	trans.get_log(payload_str, level);
	msg << tab << "Phase:: " << phase << "\n";
	msg << tab << "Delay:: " << delay << "\n";
	msg << tab << "Payload\n";
	msg << payload_str;
	log += msg.str();
}

inline void get_transport_dbg_log(const xtlm::aximm_payload& trans,
		std::string& log, const unsigned int& level) {
	if (level == 0) {
		return;
	}
	std::string payload_str("");
	std::stringstream msg("");
	trans.get_log(payload_str, level);
	msg << tab << "Payload\n";
	msg << payload_str << "\n";
	log += msg.str();
}

inline void get_transport_dbg_log(const xtlm::axis_payload& trans,
  std::string& log, const unsigned int& level) {
  if (level == 0) {
    return;
  }
  std::string payload_str("");
  std::stringstream msg("");
  trans.get_log(payload_str, level);
  msg << tab << "Payload\n";
  msg << payload_str << "\n";
  log += msg.str();
}

inline void get_tlm_sync_enum_as_string(std::string& log,
		const tlm::tlm_sync_enum& status) {
	switch (status) {
	case 0:
		log += "TLM_ACCEPTED";
		break;
	case 1:
		log += "TLM_UPDATED";
		break;
	default:
		log += "TLM_COMPLETED";
	}
}

inline void get_direct_mem_ptr_log(const xtlm::aximm_payload& trans,
		const tlm::tlm_dmi& dmi_data, std::string& log,
		const unsigned int& level) {
	if (level == 0) {
		return;
	}
	std::string payload_str("");
	std::stringstream msg("");
	trans.get_log(payload_str, level);
	msg << tab << "Payload\n";
	msg << payload_str << "\n";
	log += msg.str();
}

inline void get_direct_mem_ptr_log(const xtlm::axis_payload& trans,
  const tlm::tlm_dmi& dmi_data, std::string& log,
  const unsigned int& level) {
  if (level == 0) {
    return;
  }
  std::string payload_str("");
  std::stringstream msg("");
  trans.get_log(payload_str, level);
  msg << tab << "Payload\n";
  msg << payload_str << "\n";
  log += msg.str();
}

inline void get_invalidate_direct_mem_ptr_log(const sc_dt::uint64& start_range,
		const sc_dt::uint64& end_range, std::string& log,
		const unsigned int& level) {

	if (level == 0) {
		return;
	}
	std::string tab("  ");
	std::stringstream msg("");
	msg << tab << "start_range:: " << start_range << "\n";
	msg << tab << "end_range:: " << end_range << "\n";
	log += msg.str();
}
}
#endif /* _XTLM_LOG_HELPER_H_ */

