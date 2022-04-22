// 67d7842dbbe25473c3c32b93c0da8047785f30d78e8a024de1b57352245f9689
#ifndef __AIE_HANDLE_SIM_CONFIG_H__
#define __AIE_HANDLE_SIM_CONFIG_H__

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>

struct struct_sim_config
{
  std::string json_device_file_path;
  std::string aie_sim_sol_path;
  std::string used_tiles_file_path;
};

class ReadSimConfig
{
public:
	ReadSimConfig();
  ~ReadSimConfig();
  struct_sim_config aie_sim_config;
  int read_sim_config_file(std::string file_name);
  void initialize_sim_config();
};


#endif //end of __AIE_HANDLE_SIM_CONFIG_H__
