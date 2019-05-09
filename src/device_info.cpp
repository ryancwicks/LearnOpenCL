#include "LearnOpenCL/device_info.h"

#include <CL/cl.hpp>
#include <iostream>
#include <vector>

#define __CL_ENABLE_EXCEPTIONS

int device_info() {

    try {
    std::vector <cl::Platform> platforms;
    cl::Platform::get (&platforms);

    std::cout << "# of OpenCL platforms: " << platforms.size() << std::endl;
    
    // Investigate each platform
    std::cout << "\n-------------------------" << std::endl;
    for (const auto & platform: platforms) {

        std::string s;
        platform.getInfo(CL_PLATFORM_NAME, &s);
        std::cout << "Platform: " << s << std::endl;

       platform.getInfo(CL_PLATFORM_VENDOR, &s);
       std::cout << "\tVendor:  " << s << std::endl;

       platform.getInfo(CL_PLATFORM_VERSION, &s);
       std::cout << "\tVersion: " << s << std::endl;

         // Discover number of devices
      std::vector<cl::Device> devices;
      platform.getDevices(CL_DEVICE_TYPE_ALL, &devices);
      std::cout << "\n\tNumber of devices: " << devices.size() << std::endl;

      for (const auto & device: devices) {

        std::cout << "\t-------------------------" << std::endl;

        device.getInfo(CL_DEVICE_NAME, &s);
        std::cout << "\t\tName: " << s << std::endl;

        device.getInfo(CL_DEVICE_OPENCL_C_VERSION, &s);
        std::cout << "\t\tVersion: " << s << std::endl;

        int i;
        device.getInfo(CL_DEVICE_MAX_COMPUTE_UNITS, &i);
        std::cout << "\t\tMax. Compute Units: " << i << std::endl;

        size_t size;
        device.getInfo(CL_DEVICE_LOCAL_MEM_SIZE, &size);
        std::cout << "\t\tLocal Memory Size: " << size/1024 << " KB" << std::endl;

        device.getInfo(CL_DEVICE_GLOBAL_MEM_SIZE, &size);
        std::cout << "\t\tGlobal Memory Size: " << size/(1024*1024) << " MB" << std::endl;

        device.getInfo(CL_DEVICE_MAX_MEM_ALLOC_SIZE, &size);
        std::cout << "\t\tMax Alloc Size: " << size/(1024*1024) << " MB" << std::endl;

        device.getInfo(CL_DEVICE_MAX_WORK_GROUP_SIZE, &size);
        std::cout << "\t\tMax Work-group Total Size: " << size << std::endl;

        std::vector<size_t> d;
        device.getInfo(CL_DEVICE_MAX_WORK_ITEM_SIZES, &d);
        std::cout << "\t\tMax Work-group Dims: (";
        for (std::vector<size_t>::iterator st = d.begin(); st != d.end(); st++)
          std::cout << *st << " ";
        std::cout << "\x08)" << std::endl;

        std::cout << "\t-------------------------" << std::endl;

      }

    }
    }
    catch (std::exception err)
  {
    std::cout << "OpenCL Error: " << err.what() << " returned " << std::endl;
    std::cout << "Check cl.h for error codes." << std::endl;
    exit(-1);
}


    return 0;
}