// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// (c) Copyright 2013 - 2019 Xilinx, Inc. All rights reserved.
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
#ifndef _XTLM_AXIS_MONITOR_BASE_H_
#define _XTLM_AXIS_MONITOR_BASE_H_

#include "utils/xtlm_cmnhdr.h"
#include "xtlm_generic_payload/axis_payload.h"
#include "xtlm_interfaces/xtlm_axis_protocol_type.h"

namespace xtlm {
class xtlm_axis_monitor_base: public sc_interface {
public:
	explicit xtlm_axis_monitor_base(const std::string &name) :
			m_name(name) {
	}
	std::string get_name() const {
		return (m_name);
	}
	virtual void register_nb_call(const xtlm::axis_payload& payload,
			const tlm::tlm_phase& phase, const sc_core::sc_time& delay) {
	}

	virtual void register_nb_return_call(const xtlm::axis_payload& payload,
			const tlm::tlm_phase& phase, const sc_core::sc_time& delay,
			const tlm::tlm_sync_enum& status) {
	}

	virtual void register_b_call(const xtlm::axis_payload& payload,
			const sc_core::sc_time& delay) {
	}
	virtual void register_b_return_call(const xtlm::axis_payload& payload,
			const sc_core::sc_time& delay) {
	}
	virtual ~xtlm_axis_monitor_base() {
	}
protected:

private:
	std::string m_name;
};
}

#endif /* XTLM_INCLUDE_XTLM_INTERFACES_XTLM_AXIS_MONITOR_BASE_H_ */
