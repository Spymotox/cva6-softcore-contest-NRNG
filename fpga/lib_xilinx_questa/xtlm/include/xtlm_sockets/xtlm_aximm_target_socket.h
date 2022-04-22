// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
// (c) Copyright(C) 2013 - 2019 by Xilinx, Inc. All rights reserved.
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

#ifndef XTLM_AXIMM_TARGET_SOCKET_T_H
#define XTLM_AXIMM_TARGET_SOCKET_T_H
#include "utils/xtlm_cmnhdr.h"
#ifdef XTLM_DLL
#define XTLM_AXIMM_TARGET_SOCKET_EXPORT XTLM_EXPORT
#else
#define XTLM_AXIMM_TARGET_SOCKET_EXPORT XTLM_IMPORT
#endif
#include "xtlm_interfaces/xtlm_aximm_protocol_type.h"
#include "xtlm_sockets/xtlm_aximm_sockets_base.h"

namespace xtlm {
//target socket forward declaration...
class xtlm_aximm_initiator_socket;
class xtlm_aximm_passthrough_target_socket_tagged;
class xtlm_aximm_simple_initiator_socket_tagged;
class xtlm_aximm_monitor_socket;

class XTLM_AXIMM_TARGET_SOCKET_EXPORT xtlm_aximm_target_socket: public tlm::tlm_target_socket<
		0, xtlm_aximm_protocol_types>,
		public xtlm_aximm_sockets_base {
public:
	typedef tlm::tlm_target_socket<0, xtlm_aximm_protocol_types> base_type;

	xtlm_aximm_target_socket(const char* name, int width) :
			base_type(name) {
		m_width = width;
	}

	//std::string name() { return m_name; }
	const char* kind() const {
		return "xtlm_aximm_target_socket";
	}
	unsigned int get_bus_width() const {
		return m_width;
	}

	// Bind target socket to initiator socket
	void bind(xtlm_aximm_initiator_socket& s);
	void operator()(xtlm_aximm_initiator_socket& s) {
		bind(s);
	}

	void bind(xtlm_aximm_simple_initiator_socket_tagged& s);
	void operator()(xtlm_aximm_simple_initiator_socket_tagged& s) {
		bind(s);
	}

	// Bind target socket to target socket (hierarchical bind)
	void bind(xtlm_aximm_target_socket& s);
	void operator()(xtlm_aximm_target_socket& s) {
		bind(s);
	}

	void bind(xtlm_aximm_passthrough_target_socket_tagged& s);
	void operator()(xtlm_aximm_passthrough_target_socket_tagged& s) {
		bind(s);
	}

	// Binding interface to socket doesn't require bus width check.
	// keeping tlm::tlm_target_socket bind for bw_interface_type as it is...
	void bind(tlm::tlm_fw_transport_if<xtlm_aximm_protocol_types> &ifs);
	void operator()(tlm::tlm_fw_transport_if<xtlm_aximm_protocol_types> &ifs) {
		bind(ifs);
	}

	void bind(xtlm_aximm_monitor_socket& s);
	void operator()(xtlm_aximm_monitor_socket& s) {
		bind(s);
	}

	xtlm_aximm_target_socket* operator->() {
		return this;
	}

	tlm::tlm_sync_enum nb_transport_bw(xtlm::aximm_payload& trans,
			tlm::tlm_phase& phase, sc_core::sc_time& t);

	void invalidate_direct_mem_ptr(sc_dt::uint64 start_range,
			sc_dt::uint64 end_range);
private:
	int m_width;
	void end_of_elaboration();
	void start_of_simulation();
};
}
;

#endif

