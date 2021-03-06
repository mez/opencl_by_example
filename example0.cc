/**
 * Example 0: Let's print out what devices we can make use of!
 * output for me:

    Hello, OpenCL!

    Platform Vendor : Apple 
    Platform Version: OpenCL 1.2 (Mar  6 2017 20:53:28) 

    Possible devices:
      Device Name: Intel(R) Core(TM) i7-3667U CPU @ 2.00GHz 
         Profile: FULL_PROFILE 
         Max Compute Units (cores): 4
         Max Clock Speed : 2.00 GHz
         Global Memory Size : 8.59 GB
         Local Memory Size : 32768 Bytes
         Global Cache Memory Size : 64 Bytes
         Global Cache Line Memory Size : 4.19 MB
         Max Work Item Dimensions: 3
         Max Work Item Size per Dimension: ( 1024,1,1, )
         Max Work Group Dimension: 1024

      Device Name: HD Graphics 4000 
         Profile: FULL_PROFILE 
         Max Compute Units (cores): 16
         Max Clock Speed : 1.15 GHz
         Global Memory Size : 1.61 GB
         Local Memory Size : 65536 Bytes
         Global Cache Memory Size : 0 Bytes
         Global Cache Line Memory Size : 0.00 MB
         Max Work Item Dimensions: 3
         Max Work Item Size per Dimension: ( 512,512,512, )
         Max Work Group Dimension: 512

 */
#include <iostream>
#include <vector>
#include "cl.hpp"

#include <iomanip>

using namespace std;

int main() {
  cout << "Hello, OpenCL!" << endl << endl;

  // get all platforms (drivers)
  vector<cl::Platform> all_platforms;
  cl::Platform::get(&all_platforms);

  if (all_platforms.size()==0) {
    cout<<" No platforms found. Check OpenCL installation!" << endl;
    exit(1);
  }

  for (auto & default_platform: all_platforms) {


    //cl::Platform default_platform = all_platforms[0];
    cout << "Platform Vendor : " << default_platform.getInfo<CL_PLATFORM_NAME>() << endl;
    cout << "Platform Version: " << default_platform.getInfo<CL_PLATFORM_VERSION>() << endl << endl;

    // get default device (CPUs, GPUs) of a given platform
    vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);

    if (all_devices.size() == 0) {
      cout << " No devices found. Check OpenCL installation!" << endl;
      exit(1);
    }

    cout << "Possible devices: " << endl;
    for (const auto &device : all_devices) {
      std::cout << std::fixed;
      std::cout << std::setprecision(2);

      cout << "\tDevice Name: " << device.getInfo<CL_DEVICE_NAME>() << endl;
      cout << "\t\t Profile: " << device.getInfo<CL_DEVICE_PROFILE>() << endl;
      cout << "\t\t Max Compute Units (cores): " << device.getInfo<CL_DEVICE_MAX_COMPUTE_UNITS>() << endl;
      cout << "\t\t Max Clock Speed : " << device.getInfo<CL_DEVICE_MAX_CLOCK_FREQUENCY>() / 1000.0 << " GHz" << endl;
      cout << "\t\t Global Memory Size : " << device.getInfo<CL_DEVICE_GLOBAL_MEM_SIZE>() / 1e9 << " GB" << endl;
      cout << "\t\t Local Memory Size : " << device.getInfo<CL_DEVICE_LOCAL_MEM_SIZE>() << " Bytes" << endl;
      cout << "\t\t Global Cache Memory Size : " << device.getInfo<CL_DEVICE_GLOBAL_MEM_CACHE_SIZE>() << " Bytes"
           << endl;
      cout << "\t\t Global Cache Line Memory Size : " << device.getInfo<CL_DEVICE_GLOBAL_MEM_CACHELINE_SIZE>() / 1e6
           << " MB" << endl;


      cout << "\t\t Max Work Item Dimensions: " << device.getInfo<CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS>() << endl;
      //this is a list for max work items per dimension
      auto max_work_items_per_dimension = device.getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();
      cout << "\t\t Max Work Item Size per Dimension: ( ";
      for (const auto &max_work_items: max_work_items_per_dimension) {
        cout << max_work_items << ",";
      }
      cout << " )" << endl;

      cout << "\t\t Max Work Group Dimension: " << device.getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>() << endl;

      cout << "\n";
    }
  }

  return 0;
}