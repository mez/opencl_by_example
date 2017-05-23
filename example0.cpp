/**
 * Example 0: Let's print out what devices we can make use of!
 * output for me:

    Hello, OpenCL!

    Platform Vendor : Apple 
    Platform Version: OpenCL 1.2 (Mar  6 2017 20:53:28) 

    Possible devices:
      > Intel(R) Core(TM) i7-3667U CPU @ 2.00GHz 
      > HD Graphics 4000 

 */
#include <iostream>
#include <vector>
#include "cl.hpp"

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

  cl::Platform default_platform=all_platforms[0];
  cout << "Platform Vendor : " << default_platform.getInfo<CL_PLATFORM_NAME>() << endl;
  cout << "Platform Version: " << default_platform.getInfo<CL_PLATFORM_VERSION>() << endl << endl;

  // get default device (CPUs, GPUs) of a given platform
  vector<cl::Device> all_devices;
  default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);

  if(all_devices.size()==0){
    cout<<" No devices found. Check OpenCL installation!" << endl;
    exit(1);
  }

  cout<< "Possible devices: " << endl;
  for (const auto& device : all_devices) {
    cout << "\t> " << device.getInfo<CL_DEVICE_NAME>()<< endl;
  }

  return 0;
}