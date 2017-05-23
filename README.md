Welcome to OpenCL by Examples using C++.
-

### Why OpenCL? 
I actually started working and learning CUDA first, but I do
my work with a macair late 2012 model; I quickly realized
I couldn't run my CUDA code. My machine has an Intel HD 4000, I know, it sucks, 
but still usuable! My search on how to best make use of it led me to OpenCL.

My interests with OpenCL is primarly motivated by my interested in Deep Learning.
I want a better understanding of how these frameworks are making use 
of GPGPU to blaze through model training.

Here we are now, a repo of OpenCL examples. I'll be adding more
examples here as I pickup more of OpenCL. I am thinking each example will
get a bit more complex. 

### Setup I am using
1. Mac OSX
2. OpenCL 1.2
3. C++ 11
4. cmake 3.7

### How to Build and Run
1. Clone this repo and `cd` in this repo.
2. Run `mkdir build && cd build`
3. Run `cmake .. && make`

If everything has been correctly installed, you should be able to build 
the examples with no problems. Check out the `CMakeLists.txt` file for info
on how the examples are being built.

Note, I already added the C++ header for OpenCL 1.x in the `libs` directory.
However, if you are for example working with OpenCL 2 you can create your own
header file. Head over to the [KhronosGroup OpenCL-CLHPP repo](https://github.com/KhronosGroup/OpenCL-CLHPP)
and do the following.

1. Run `git clone https://github.com/KhronosGroup/OpenCL-CLHPP`
2. Run `cd OpenCL-CLHPP`
3. Run `python gen_cl_hpp.py -i input_cl2.hpp -o cl2.hpp`
4. Move the generated header file `cl2.hpp` into the `libs` directory.
5. Profit!

### Quick Introduction and OpenCL Terminology
You're here so I don't need to convince you that parallel computing is awesome
and the future. I don't expect you to become an expert after you've gone through this repo,
but I do hope you _at least_ get an overview of how to think in OpenCL.
 
> OpenCL™ (Open Computing Language) is the open, 
royalty-free standard for cross-platform, 
parallel programming of diverse processors 
found in personal computers, servers, 
mobile devices and embedded platforms. - [khronos site](https://www.khronos.org/)

The following are terms to know:

* **Platform**: Vendor specific OpenCL implementation.
* **Host**: The client code that is running on the CPU. Basically your application.
* **Device**: The physical devices you have that support OpenCL (CPU/GPU/FPGA etc..)
* **Context**: Devices you select to work together.
* **Kernel**: The function that is run on the device and does the work.
* **Work Item**: A unit of work that executes a kernel.
* **Work Group**: A collection of work items.
* **Command Queue**: The only way to tell a device what to do.
* **Buffer**: A chunk of memory on the device.
* **Memory**: Can be global/local/private/constant (more on this later.)
* **Compute Unit**: Think of a GPU core. 