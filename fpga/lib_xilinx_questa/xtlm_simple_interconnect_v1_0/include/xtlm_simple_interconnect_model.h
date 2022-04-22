// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
/*  (c) Copyright 2014 - 2019 Xilinx, Inc. All rights reserved.

 This file contains confidential and proprietary information
 of Xilinx, Inc. and is protected under U.S. and
 international copyright and other intellectual property
 laws.

 DISCLAIMER
 This disclaimer is not a license and does not grant any
 rights to the materials distributed herewith. Except as
 otherwise provided in a valid license issued to you by
 Xilinx, and to the maximum extent permitted by applicable
 law: (1) THESE MATERIALS ARE MADE AVAILABLE "AS IS" AND
 WITH ALL FAULTS, AND XILINX HEREBY DISCLAIMS ALL WARRANTIES
 AND CONDITIONS, EXPRESS, IMPLIED, OR STATUTORY, INCLUDING
 BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, NON-
 INFRINGEMENT, OR FITNESS FOR ANY PARTICULAR PURPOSE; and
 (2) Xilinx shall not be liable (whether in contract or tort,
 including negligence, or under any other theory of
 liability) for any loss or damage of any kind or nature
 related to, arising under or in connection with these
 materials, including for any direct, or any indirect,
 special, incidental, or consequential loss or damage
 (including loss of data, profits, goodwill, or any type of
 loss or damage suffered as a result of any action brought
 by a third party) even if such damage or loss was
 reasonably foreseeable or Xilinx had been advised of the
 possibility of the same.

 CRITICAL APPLICATIONS
 Xilinx products are not designed or intended to be fail-
 safe, or for use in any application requiring fail-safe
 performance, such as life-support or safety devices or
 systems, Class III medical devices, nuclear facilities,
 applications related to the deployment of airbags, or any
 other applications that could lead to death, personal
 injury, or severe property or environmental damage
 (individually and collectively, "Critical
 Applications"). Customer assumes the sole risk and
 liability of any use of Xilinx products in Critical
 Applications, subject only to applicable laws and
 regulations governing limitations on product liability.

 THIS COPYRIGHT NOTICE AND DISCLAIMER MUST BE RETAINED AS
 PART OF THIS FILE AT ALL TIMES.                       */



#ifndef _XTLM_SIMPLE_INTERCONNECT_MODEL_H_
#define _XTLM_SIMPLE_INTERCONNECT_MODEL_H_

#include "xtlm.h"
#include "report_handler.h"
#include <map>
namespace xsc{
class xtlm_simple_interconnect_model_impl;
}
class xtlm_simple_interconnect_model: public sc_core::sc_module {

public:

	//Master interfaces
	xtlm::xtlm_aximm_initiator_socket* initiator_rd_sockets[32];
	xtlm::xtlm_aximm_initiator_socket* initiator_wr_sockets[32];

	//Slave interfaces
	xtlm::xtlm_aximm_target_socket*    target_rd_sockets[32];
	xtlm::xtlm_aximm_target_socket*    target_wr_sockets[32];
	xtlm_simple_interconnect_model(sc_core::sc_module_name,xsc::common_cpp::properties& properties);
	virtual ~xtlm_simple_interconnect_model();
	SC_HAS_PROCESS(xtlm_simple_interconnect_model);
private :
	std::vector<uint64_t>      m_slave_data_width;
	std::vector<uint64_t>      m_master_data_width;
	xsc::common_cpp::report_handler* m_report_handler;
	uint64_t                         m_num_masters;
	uint64_t                         m_num_slaves;
	xsc::xtlm_simple_interconnect_model_impl* m_imp;
	//Negative value indicates decode error
	uint64_t addressDecoder(uint64_t address,uint64_t slave_id);

};

#endif /* _XTLM_SIMPLE_INTERCONNECT_MODEL_H_ */

