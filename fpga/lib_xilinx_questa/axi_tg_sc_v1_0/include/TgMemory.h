// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
//**********************************************************************
// Copyright (c) 2016-2018 Xilinx Inc.  All Rights Reserved
//**********************************************************************
//
//  Common implementation utilities for AXI TG
//
//**********************************************************************
#ifndef _xsc_axitg_TgMemory_h_
#define _xsc_axitg_TgMemory_h_

#include "xtlm.h"
#include "report_handler.h"
#include <memory>
#include <type_traits>

namespace xsc    {
namespace axi_tg {

enum class Tg_type {
  Master, Slave
};

// chunks equal to 4KB so each AXI txn hits only 1
// Any module that requires an instance of this class must
// invoke get_dic_inst<>() mentod.
//
// If the requestor is Master TG, then a shared pointer is 
// returned. All master read and write to same resource
//
// If the requestor is Slave ED, then a unique pointer is
// returned. Each Slave owns its own resource.
class DataIntegritySparseStorage {
  int m_trace;
  std::string m_header;

  template <int ChunkSize=4096> class Detail;
  std::unique_ptr<Detail<>> m_detail;

  //Static shared pointer that all NMU's share
  static std::shared_ptr<DataIntegritySparseStorage> m_nmu_mem;

 public:
  ~DataIntegritySparseStorage();
  //Move constructor and assignment operator
  DataIntegritySparseStorage(DataIntegritySparseStorage&& );
  DataIntegritySparseStorage& operator=(DataIntegritySparseStorage&& );
  //Copy constructor and assignment operator
  DataIntegritySparseStorage(DataIntegritySparseStorage const& ) = delete;
  DataIntegritySparseStorage& operator=(DataIntegritySparseStorage const& ) = delete;

 private:
  DataIntegritySparseStorage();
   
 public:
  using Addr          = uint64_t;
  using NumBytes      = uint16_t;
  using DataArr       = unsigned char*; // storage in bytes
  using ConstDataArr  = const unsigned char*; // storage in bytes

  void check( Addr, ConstDataArr, uint16_t ) const;
  std::pair<unsigned char, bool> byteAt( Addr ) const;
  void write( Addr, ConstDataArr, uint16_t, ConstDataArr byteEnable=0 );
  void read(Addr, DataArr, uint16_t);
  void printPayload(
      const uint8_t* ptr, uint64_t addr, uint16_t num, bool isRead);
  void setHeader(std::string header);

  template<Tg_type V,
           typename = std::enable_if_t<V == Tg_type::Master>>
  static std::shared_ptr<DataIntegritySparseStorage> get_dic_inst()
  {
    if (!m_nmu_mem)
      m_nmu_mem = std::shared_ptr<DataIntegritySparseStorage>(
          new DataIntegritySparseStorage());
    return m_nmu_mem;
  }

  template<Tg_type V,
           typename = std::enable_if_t<V == Tg_type::Slave>>
  static std::unique_ptr<DataIntegritySparseStorage> get_dic_inst()
  {
    return std::unique_ptr<DataIntegritySparseStorage>(
        new DataIntegritySparseStorage());
  }
};


}
}

#endif


